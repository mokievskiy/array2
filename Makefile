all: prog

prog: main.o test.o
	g++ main.o test.o block.hpp test.hpp -o prog

main.o: main.cpp block.hpp test.hpp
	g++ -c main.cpp

DynamicArrayF.o: test.cpp block.hpp test.hpp
	g++ -c test.cpp

clean:
	rm -f *.o prog