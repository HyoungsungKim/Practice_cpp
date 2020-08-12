main.out : main.o gravity.o
	g++ -o main.out main.o gravity.o

main.o : gravity.h main.cpp
	g++ -c -o main.o main.cpp

gravity.o : gravity.h gravity.cpp
	g++ -c -o gravity.o gravity.cpp

clean :
	rm *.o *.out 