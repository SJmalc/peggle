# Makefile for lab 10
#   make: creates all three executables
#   make symbol: creates the symbol executable
#   same for bounce and animate
peggle: pegs.o project.o gfx.o
	g++ -std=c++11 project.o pegs.o gfx.o -o peggle -lX11

pegs.o: pegs.cpp pegs.h gfx.o
	g++ -std=c++11 pegs.cpp -c -o pegs.o -lX11

project.o: project.cpp 
	g++ -std=c++11 project.cpp -c -o project.o -lX11

clean:
	rm project.o pegs.o
	rm peggle
