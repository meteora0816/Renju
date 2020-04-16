#include "makemove.h"
#include "printchessboard.h"
#include "evaluate.h"

bool makeMove(int x, int y, int color)
{
	//执行落子操作（chessboard[i][j]=1 & chessboard[i][j]=2）
	chessBoard[x][y] = color;
	piecesCount++;
	printf("%d %d %d\n", x, y, color);
	int delta = evaluate(x, y);
	if (color==black) VALUE_BLACK += delta;
	else VALUE_WHITE += delta;
	if (gameover(x,y,color)) return true;
	else return false;
}

bool unMakeMove()
{
	//撤销落子操作（chessboard[i][j]=0）
	return true;
}
