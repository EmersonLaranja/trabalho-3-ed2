compile:
	clear
	gcc *.c -o trab3 -lm

run:
	./trab3 ./input/index.txt

val: compile
	valgrind --leak-check=full ./trab3 ./input/index.txt -lm


test: 
	clear
	gcc -o test pageRank.c -lm
	./test < input.txt

all:compile run