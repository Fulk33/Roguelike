
CC = gcc
STD = c99
IN = src/*.c
OUT = rogue

make:
		$(CC) -o $(OUT) -std=$(STD) $(IN)

clean:

		rm $(OUT)
