main.out : main.o add.o
	g++ -o main.out main.o add.o

main.o : add.h main.cpp
	g++ -c -o main.o main.cpp

add.o : add.cpp
	g++ -c -o add.o add.cpp

clean :
	rm *.o *.out
	