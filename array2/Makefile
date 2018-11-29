all: prog

prog: main.o test.o
	g++ main.o test.o DynamicArrayF.cpp -o prog

main.o: main.cpp block.hpp test.hpp
	g++ -c main.cpp

test.o: test.cpp block.hpp test.hpp
	g++ -c test.cpp

clean:
	rm -f *.o prog