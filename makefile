STANDARD = c99

sudoku: sudoku.c
	gcc $^ -o $@ -std=$(STANDARD)

.PHONY:clean

clean:
	rm sudoku
