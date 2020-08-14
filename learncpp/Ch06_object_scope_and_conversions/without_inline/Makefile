#compile_version = -std=c++17

main.out : main.o constants.o
	g++ -o main.out main.o constants.o

main.o : main.cpp constants.h
	g++ -c -o main.o main.cpp 

constants.o : constants.h constants.cpp
	g++ -c -o constants.o constants.cpp

clean :
	rm *.o *.out