
CC = gcc
STD = c99
IN = main.c
OUT = rogue

make:
		$(CC) -o $(OUT) -std=$(STD) $(IN)
