PROGRAMM = main

src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

CC=g++

LDLIBS = `sdl2-config --cflags --libs` #-lasan
CFLAGS += -Wall -Wextra -pedantic-errors #-fsanitize=address

all: $(PROGRAMM)

run: all
	./$(PROGRAMM)

$(PROGRAMM): $(obj)

.PHONY: clean
clean:
	rm -f $(obj) $(PROGRAMM)
