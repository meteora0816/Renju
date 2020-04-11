#include "makemove.h"
#include "printchessboard.h"

bool makeMove()
{
	//执行落子操作（chessboard[i][j]=1 & chessboard[i][j]=2）
	int x = rand() % 15 + 1, y = rand() % 15 + 1;
	while (chessBoard[x][y] != 0) {
		x = rand() % 15 + 1;
		y = rand() % 15 + 1;
	}
	printf("%d %d\n", x, y);
	chessBoard[x][y] = player ^ 3;
	return true;
}

bool unMakeMove()
{
	//撤销落子操作（chessboard[i][j]=0）
	return true;
}
