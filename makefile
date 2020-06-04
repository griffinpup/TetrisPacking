all: recursive_place.o node.o shape.o
	c++ -o solve.out test.cpp recursive_place.o node.o shape.o

recursive_place.o: recursive_place.cpp node.h
	c++ -c recursive_place.cpp

node.o: node.h node.cpp
	c++ -c node.cpp

shape.o: shape.h shape.cpp
	c++ -c shape.cpp

clean:
	rm node.o shape.o
