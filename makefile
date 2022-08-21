all: tp1

tp1: main.o file.o board.o
	gcc -o tp1 main.o file.o board.o

main.o: main.c
	gcc -c main.c

file.o: file.h file.c
	gcc -c file.c

board.o: board.h board.c
	gcc -c board.c

clean:
	rm -rf main.o file.o board.o tp1