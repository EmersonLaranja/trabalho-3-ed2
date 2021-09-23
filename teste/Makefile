compile:
	clear
	gcc *.c -o trab3 -lm

run:
	./trab3 ./input/index.txt

val: compile
	valgrind --leak-check=full ./trab3 ./input/index.txt -lm


test: 
	clear
	gcc -o test.out *.c -lm
	./test.out < input.txt
	rm test.out

all:compile run