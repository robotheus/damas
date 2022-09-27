all: tp1 gerarcasos

file.o: file.h file.c
	gcc -c file.c

board.o: board.h board.c
	gcc -c board.c

print.o: print.h print.c
	gcc -c print.c

algorithm1.o: algorithm1.h algorithm1.c
	gcc -c algorithm1.c

times.o: times.h times.c
	gcc -c times.c

algorithm2.o: algorithm2.h algorithm2.c
	gcc -c algorithm2.c

main.o: main.c
	gcc -c main.c

gerarcasos: casos.c
	gcc casos.c -o gerarcasos -lm

tp1: main.o file.o board.o print.o algorithm1.o times.o algorithm2.o
	gcc main.o file.o board.o print.o algorithm1.o times.o algorithm2.o -o tp1 -lm
	
clean:
	rm -rf main.o file.o board.o print.o algorithm1.o times.o algorithm2.o tp1 saida.txt gerarcasos