


main    : 3DField.o main.o
	g++ 3DField.o main.o
	
main.o      : main.cpp
	g++ -c main.cpp
3DField.o   : 3DField.cpp
	g++ -c 3DField.cpp
