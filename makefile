CC=gcc
CFLAGS=-I.

all: main

main: main.c  moves.c chess.c
	${CC} -o chess $^ -g

clean: 
	rm -rf chess