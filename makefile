all:locadora.o
	gcc -Wall locadora.o main.c -o main

tp1.o:locadora.h
	gcc -c locadora.c

clean:
	rm -rf *.o main