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
 */
int BoardInit(struct PlayBoard *playboard)
{
	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++)
			playboard->board[i][j] = 0;
	return 0;
}

/*
 * PlayBoard Input
 */
int BoardAdd(struct PlayBoard *playboard)
{
	int posx, posy, num;
	int validpos = 0, validnum = 0;
	
	while(!validnum){
		printf("Input your decision from [1-9(number) or 0(quit)]: ");
		scanf("%d", &num);
		if(!num) return 1;
		else if(num < 0 || num > 9)
			printf("Error Input: number is invalid, Please re-input.\n");
		else
			validnum = 1;
	}

	while(!validpos){
		printf("Input your position[x, y]: ");
		scanf("%d %d", &posx, &posy);
		if(posx < 1 || posy < 1 || posx > 9 || posy > 9)
			printf("Error Input: position is invalid, Please re-input.\n");
		else
			validpos = 1;
	}

	playboard->board[posx-1][posy-1] = num;
	return 0;
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

	int result;
	while(1){
		result = BoardAdd(&playboard);	
		if(!result) BoardDisplay(playboard);
		else break;
	}

	return 0;
}
