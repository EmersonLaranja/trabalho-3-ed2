compile:
	clear
	gcc *.c -o trab3

run:
	./trab3 ./input/index.txt

val: compile
	valgrind --leak-check=full ./trab3 ./input/index.txt

all:compile run