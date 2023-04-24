#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

struct PlayBoard
{
	int mode;
	int board[SIZE][SIZE];
};

/*
 * PlayBoard Initialization
 * Start with 0
 */
void BoardInit(struct PlayBoard *playboard)
{
	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++)
			playboard->board[i][j] = 0;
}


/*
 * PlayBoard Display
 */
void LineDisplay(struct PlayBoard playboard, int line)
{
	for(int i = 0; i < 3; i++){
		printf("| ");
		for(int j = i * 3; j < i * 3 + 3; j++){
			printf("%d ", playboard.board[line][j]);
		}
	}
	printf("|\n");
}

void CutOffDisplay()
{
	for(int i = 0; i < 3; i++){
		printf("+");
		for(int j = 0; j < 7; j++)
			printf("-");
	}
	printf("+\n");		
}
	
void BoardDisplay(struct PlayBoard playboard)
{
	for(int i = 0; i < 3; i++){
		CutOffDisplay();
		for(int j = i * 3; j < i * 3 + 3; j++)
			LineDisplay(playboard, j);
	}
	CutOffDisplay();
}


/*
 * main part
 */
int main(int argc, char *argv[])
{
	struct PlayBoard playboard;
	playboard.mode = atoi(argv[1]);

	BoardInit(&playboard);	

	BoardDisplay(playboard);

	return 0;
}
