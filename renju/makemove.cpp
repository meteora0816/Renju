#include "makemove.h"
#include "printchessboard.h"

bool makeMove(int x, int y, int color)
{
	//ִ�����Ӳ�����chessboard[i][j]=1 & chessboard[i][j]=2��
	chessBoard[x][y] = color;
	return true;
}

bool unMakeMove()
{
	//�������Ӳ�����chessboard[i][j]=0��
	return true;
}
