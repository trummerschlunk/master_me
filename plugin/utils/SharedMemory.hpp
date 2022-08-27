/*
 * DISTRHO Plugin Framework (DPF)
 * Copyright (C) 2012-2022 Filipe Coelho <falktx@falktx.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with
 * or without fee is hereby granted, provided that the above copyright notice and this
 * permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD
 * TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef DISTRHO_SHARED_MEMORY_HPP_INCLUDED
#define DISTRHO_SHARED_MEMORY_HPP_INCLUDED

#include "extra/String.hpp"

#ifdef DISTRHO_OS_WINDOWS
# define WIN32_LEAN_AND_MEAN
# include <winsock2.h>
# include <windows.h>
#else
# include <cerrno>
# include <fcntl.h>
# include <unistd.h>
# include <sys/mman.h>
#endif

#include <ctime>

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------

template<class S>
class SharedMemory
{
public:
    SharedMemory()
        : ptr(nullptr),
          filename(),
         #ifdef DISTRHO_OS_WINDOWS
          handle(INVALID_HANDLE_VALUE)
         #else
          fd(-1)
         #endif
    {
    }

    ~SharedMemory()
    {
        close();
    }

    bool create()
    {
        DISTRHO_SAFE_ASSERT_RETURN(ptr == nullptr, false);

        char filename2[64];
       #ifdef DISTRHO_OS_WINDOWS
        std::sprintf(filename2, "Local\\dpf_XXXXXX");
       #else
        std::sprintf(filename2, "/dpf_XXXXXX");
        int fd2;
       #endif
        const std::size_t filename2len = std::strlen(filename2);

        std::srand(static_cast<uint>(std::time(nullptr)));

        // Step 1. Find a valid shared memory segment (keep trying until one is obtained or an error occurs)
        for (;;)
        {
            // character set to use randomly
            static const char charSet[] = "abcdefghijklmnopqrstuvwxyz"
                                          "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                          "0123456789";
            static const int charSetLen = static_cast<int>(std::strlen(charSet) - 1); // -1 to avoid trailing '\0'

            // fill the XXXXXX characters randomly
            for (std::size_t c = filename2len - 6; c < filename2len; ++c)
                filename2[c] = charSet[std::rand() % charSetLen];

           #ifdef DISTRHO_OS_WINDOWS
            const HANDLE h = ::CreateFileMapping(INVALID_HANDLE_VALUE, nullptr,
                                                 PAGE_READWRITE|SEC_COMMIT, 0, 8, filename2);
            DISTRHO_SAFE_ASSERT_RETURN(h != INVALID_HANDLE_VALUE, false);

            const DWORD error = ::GetLastError();
            ::CloseHandle(h);

            if (error == 0) // FIXME ERROR_NONE or similar?
                break;

            if (error == ERROR_ALREADY_EXISTS)
            {
                d_stderr("SharedMemory::create: file '%s' already exists, retrying", filename2);
                continue;
            }

            d_stderr("SharedMemory::create: file '%s' failed, error code 0x%x", filename2, error);
            return false;
           #else
            fd2 = -1;

            try {
                fd2 = ::shm_open(filename2, O_CREAT|O_EXCL|O_RDWR, 0600);
            } DISTRHO_SAFE_EXCEPTION("SharedMemory::create");

            if (fd2 >= 0)
                break;

            const int error = errno;

            if (error == EEXIST)
            {
                d_stderr("SharedMemory::create: file '%s' already exists, retrying", filename2);
                continue;
            }

            d_stderr2("SharedMemory::create: shm_open failed: %s", std::strerror(error));
            return false;
           #endif
        }

        // Step 2. Memory-map the file contents
      #ifdef DISTRHO_OS_WINDOWS
        SECURITY_ATTRIBUTES sa;
        std::memset(&sa, 0, sizeof(sa));
        sa.nLength = sizeof(sa);
        sa.bInheritHandle = TRUE;

        void* const handle2 = ::CreateFileMappingA(INVALID_HANDLE_VALUE, &sa, PAGE_READWRITE|SEC_COMMIT, 0,
                                                   sizeof(S), filename2);

        if (handle2 == nullptr || handle2 == INVALID_HANDLE_VALUE)
        {
            const DWORD errorCode = ::GetLastError();
            d_stderr2("SharedMemory::create: CreateFileMapping failed for '%s', errorCode:%x",
                      filename2, errorCode);
            return false;
        }

        void* const ptr2 = ::MapViewOfFile(handle2, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(S));

        if (ptr2 == nullptr)
        {
            const DWORD errorCode = ::GetLastError();
            d_stderr2("SharedMemory::create: MapViewOfFile failed for '%s', errorCode:%x",
                      filename2, errorCode);
            ::CloseHandle(handle2);
            return false;
        }

        handle = handle2;
        ptr = (S*)ptr2;
      #else
        int ret;

        try {
            ret = ::ftruncate(fd2, sizeof(S));
        } DISTRHO_SAFE_EXCEPTION("SharedMemory::create");

        if (ret != 0)
        {
            d_stderr2("SharedMemory::create: ftruncate failed: %s", std::strerror(errno));
            ::close(fd2);
            ::shm_unlink(filename2);
            return false;
        }

        void* ptr2;
       #ifdef MAP_LOCKED
        ptr2 = ::mmap(nullptr, sizeof(S), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_LOCKED, fd2, 0);
        if (ptr2 == nullptr || ptr2 == MAP_FAILED)
       #endif
        {
            ptr2 = ::mmap(nullptr, sizeof(S), PROT_READ|PROT_WRITE, MAP_SHARED, fd2, 0);
        }

        if (ptr2 == nullptr || ptr2 == MAP_FAILED)
        {
            d_stderr2("SharedMemory::create: mmap failed: %s", std::strerror(errno));
            ::close(fd2);
            ::shm_unlink(filename2);
            return false;
        }

       #ifndef MAP_LOCKED
        ::mlock(ptr2, sizeof(S));
       #endif

        fd = fd2;
        ptr = (S*)ptr2;
      #endif

        filename = filename2;
        return true;
    }

    S* connect(const char* const filename2)
    {
        DISTRHO_SAFE_ASSERT_RETURN(ptr == nullptr, nullptr);

      #ifdef DISTRHO_OS_WINDOWS
        void* const handle2 = ::OpenFileMappingA(FILE_MAP_ALL_ACCESS, FALSE, filename2);

        DISTRHO_SAFE_ASSERT_RETURN(handle2 != nullptr, nullptr);
        DISTRHO_SAFE_ASSERT_RETURN(handle2 != INVALID_HANDLE_VALUE, nullptr);

        void* const ptr2 = ::MapViewOfFile(handle2, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(S));

        if (ptr2 == nullptr)
        {
            const DWORD errorCode = ::GetLastError();
            d_stderr2("SharedMemory::create: MapViewOfFile failed for '%s', errorCode:%x",
                      filename2, errorCode);
            ::CloseHandle(handle2);
            return nullptr;
        }

        handle = handle2;
        ptr = (S*)ptr2;
      #else
        int fd2;

        try {
            fd2 = ::shm_open(filename2, O_RDWR, 0);
        } DISTRHO_SAFE_EXCEPTION_RETURN("SharedMemory::connect", nullptr);

        if (fd2 < 0)
        {
            d_stderr2("SharedMemory::connect: open failed: %s", std::strerror(errno));
            return nullptr;
        }

        void* ptr2;
       #ifdef MAP_LOCKED
        ptr2 = ::mmap(nullptr, sizeof(S), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_LOCKED, fd2, 0);
        if (ptr2 == nullptr || ptr2 == MAP_FAILED)
       #endif
        {
            ptr2 = ::mmap(nullptr, sizeof(S), PROT_READ|PROT_WRITE, MAP_SHARED, fd2, 0);
        }

        if (ptr2 == nullptr || ptr2 == MAP_FAILED)
        {
            d_stderr2("SharedMemory::create: mmap failed: %s", std::strerror(errno));
            ::close(fd2);
            return nullptr;
        }

       #ifndef MAP_LOCKED
        ::mlock(ptr2, sizeof(S));
       #endif

        fd = fd2;
        ptr = (S*)ptr2;
      #endif

        return ptr;
    }

    void close()
    {
        if (ptr != nullptr)
        {
           #ifdef DISTRHO_OS_WINDOWS
            ::UnmapViewOfFile(ptr);
            ::CloseHandle(handle);
            map = INVALID_HANDLE_VALUE;
           #else
            try {
                ::munmap(ptr, sizeof(S));
            } DISTRHO_SAFE_EXCEPTION("SharedMemory::close");

            try {
                ::close(fd);
            } DISTRHO_SAFE_EXCEPTION("SharedMemory::close");
            fd = -1;
           #endif
            ptr = nullptr;
        }

        if (filename.isNotEmpty())
        {
           #ifndef DISTRHO_OS_WINDOWS
            try {
                ::shm_unlink(filename);
            } DISTRHO_SAFE_EXCEPTION("SharedMemory::close");
           #endif
            filename.clear();
        }
    }

    bool isCreatedOrConnected() const noexcept
    {
        return ptr != nullptr;
    }

    S* getDataPointer() const noexcept
    {
        return ptr;
    }

    // creator-side only
    const char* getDataFilename() const noexcept
    {
        return filename;
    }

private:
    S* ptr;
    String filename;

   #ifdef DISTRHO_OS_WINDOWS
    HANDLE handle;
   #else
    int fd;
   #endif

    DISTRHO_PREVENT_VIRTUAL_HEAP_ALLOCATION
    DISTRHO_DECLARE_NON_COPYABLE(SharedMemory)
};

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO

#endif // DISTRHO_SHARED_MEMORY_HPP_INCLUDED
