main.out : main.o io.o
	g++ -o main.out main.o io.o

main.o : io.h main.cpp
	g++ -c -o main.o main.cpp

io.o : io.h io.cpp
	g++ -c -o io.o io.cpp

clean :
	rm *.o *.out