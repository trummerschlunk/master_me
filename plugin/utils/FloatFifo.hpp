/*
 * DISTRHO Plugin Framework (DPF)
 * Copyright (C) 2012-2021 Filipe Coelho <falktx@falktx.com>
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

#ifndef DISTRHO_FLOAT_FIFO_HPP_INCLUDED
#define DISTRHO_FLOAT_FIFO_HPP_INCLUDED

#include "DistrhoUtils.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------

/**
  Amount of float/audio samples in the buffer.
 */
template <uint32_t numSamples>
struct FloatFifo {
   /**
      Fifo buffer data.
    */
    float buffer[numSamples];

   /**
      Current reading position.
      Increments when reading.
    */
    uint32_t readPosition;

   /**
      Current writing position.
      Increments when writing.
    */
    uint32_t writePosition;
};

// -----------------------------------------------------------------------

/**
   DPF built-in FloatFifo class.
   FloatFifoControl takes one fifo struct to take control over, and operates over it.

   This is meant for single-writer, single-reader type of control.
   Writing and reading is wait and lock-free.

   Typically usage involves:
   ```
   // definition
   FloatFifo fifoData;
   FloatFifoControl fifo;

   // assign fifo and clear data
   fifo.setFloatFifo(&fifoData, true);

   // writing data
   fifo.write(0.0f);
   fifo.write(0.5f);
   fifo.write(1.0f);

   // reading data
   if (fifo.readSpace())
   {
      const float value = fifo.read();
      // do something with "value"
   }
   ```

   @see FloatFifo
 */
template <uint32_t numSamples>
class FloatFifoControl
{
public:
    /*
     * Constructor for unitialized float fifo.
     * A call to setFloatFifo is required to tied this control to a float fifo struct;
     *
     */
    FloatFifoControl()
        : fifoPtr(nullptr) {}

    /*
     * Destructor.
     */
    virtual ~FloatFifoControl() {}

    // -------------------------------------------------------------------
    // check operations

    inline bool canRead() const noexcept
    {
        return fifoPtr != nullptr && fifoPtr->readPosition != fifoPtr->writePosition;
    }

    // -------------------------------------------------------------------
    // clear/reset operations

    /*
     * Clear the entire float fifo data, marking the fifo as empty.
     * Requires a fifo struct tied to this class.
     */
    void clearData() noexcept
    {
        DISTRHO_SAFE_ASSERT_RETURN(fifoPtr != nullptr,);

        fifoPtr->readPosition = fifoPtr->writePosition = 0;
        std::memset(fifoPtr->buffer, 0, sizeof(float)*numSamples);
    }

    // -------------------------------------------------------------------

    /*
     * Tie this float fifo control to a float fifo struct, optionally clearing its data.
     */
    void setFloatFifo(FloatFifo<numSamples>* const floatFifo, const bool clearFifoData = true) noexcept
    {
        DISTRHO_SAFE_ASSERT_RETURN(fifoPtr != floatFifo,);

        fifoPtr = floatFifo;

        if (clearFifoData && floatFifo != nullptr)
            clearData();
    }

    // -------------------------------------------------------------------

    /*
     * Read one single sample.
     */
    float read()
    {
        DISTRHO_SAFE_ASSERT_RETURN(fifoPtr != nullptr, 0.0f);

        uint32_t readPosition = fifoPtr->readPosition;
        const float ret = *(fifoPtr->buffer + readPosition);

        if (++readPosition == numSamples)
            readPosition = 0;

        fifoPtr->readPosition = readPosition;
        return ret;
    }

    /*
     * Write one single sample.
     */
    void write(const float value)
    {
        DISTRHO_SAFE_ASSERT_RETURN(fifoPtr != nullptr,);

        uint32_t writePosition = fifoPtr->writePosition;

        *(fifoPtr->buffer + writePosition) = value;

        if (++writePosition == numSamples)
            writePosition = 0;

        fifoPtr->writePosition = writePosition;
    }

    // -------------------------------------------------------------------

private:
    /** Fifo struct pointer. */
    FloatFifo<numSamples>* fifoPtr;

    DISTRHO_PREVENT_VIRTUAL_HEAP_ALLOCATION
    DISTRHO_DECLARE_NON_COPYABLE(FloatFifoControl)
};

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO

#endif // DISTRHO_FLOAT_FIFO_HPP_INCLUDED
