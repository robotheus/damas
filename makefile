all: tp1

tp1: main.o file.o board.o print.o brutalgame.o
	gcc -o tp1 main.o file.o board.o print.o brutalgame.o -lm

main.o: main.c
	gcc -c main.c

file.o: file.h file.c
	gcc -c file.c

board.o: board.h board.c
	gcc -c board.c

print.o: print.h print.c
	gcc -c print.c

brutal_game.o:
	gcc -c brutal_game.c

clean:
	rm -rf main.o file.o board.o print.o brutalgame.o tp1