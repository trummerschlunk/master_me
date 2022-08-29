
ifeq ($(NAME),)
$(error NAME is not set)
endif

soundsgood.$(NAME):
	g++ $(CXXFLAGS) -DFAST_TESTS faustbench.cpp -o soundsgood.$(NAME)


clean:
	rm soundsgood.*
