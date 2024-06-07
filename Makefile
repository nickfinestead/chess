CC=gcc
CFLAGS=-I.

all: main

main: main.c chess.c moves.c 
	${CC} -o chess $^ -g

clean: 
	rm -rf chess
