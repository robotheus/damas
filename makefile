all: tp1

file.o: file.h file.c
	gcc -c file.c

board.o: board.h board.c
	gcc -c board.c

print.o: print.h print.c
	gcc -c print.c

brutalgame.o: brutalgame.h brutalgame.c
	gcc -c brutalgame.c

times.o: times.h times.c
	gcc -c times.c

main.o: main.c
	gcc -c main.c

tp1: main.o file.o board.o print.o brutalgame.o times.o
	gcc main.o file.o board.o print.o brutalgame.o times.o -o tp1 -lm
	
clean:
	rm -rf main.o file.o board.o print.o brutalgame.o tp1 saida.txt times.o