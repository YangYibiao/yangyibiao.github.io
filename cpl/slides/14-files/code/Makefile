calc: calc.o stack.o token.o
	gcc -o calc calc.o stack.o token.o
calc.o: calc.c stack.h token.h
	gcc -c calc.c
stack.o: stack.c stack.h
	gcc -c stack.c
token.o: token.c token.h
	gcc -c token.c
