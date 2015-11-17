
CC = gcc
STD = c99
FLAGS = -lncurses
IN = src/*.c
OUT = rogue

make:
		$(CC) -o $(OUT) -std=$(STD) $(IN) $(FLAGS)

clean:

		rm $(OUT)
