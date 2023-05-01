STANDARD = c99

sudoku: sudoku.c
	gcc sudoku.c -o sudoku -std=$(STANDARD)

.PHONY:clean

clean:
	rm sudoku
