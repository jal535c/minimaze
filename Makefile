SOURCES := $(wildcard *.cpp)
OBJECTS := $(subst .cpp,.o,$(SOURCES))
INCLUDE := -I. -Ihead
LIBS    := -lncurses
CC      := g++

minimaze: $(OBJECTS)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CC) -c $^ $(INCLUDE) -std=c++11

clean:
	rm -f *.o minimaze

info:
	$(info $(SOURCES))


