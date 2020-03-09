PROGRAMM = main

src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

CC=g++

LDLIBS = `sdl2-config --cflags --libs` -lSDL2 -lSDL2main -lSDL2_image
CFLAGS += -Wall -Wextra -pedantic-errors

all: $(PROGRAMM)

run: all
	./$(PROGRAMM)

$(PROGRAMM): $(obj)

.PHONY: clean
clean:
	rm -f $(obj) $(PROGRAMM)
