#include "makemove.h"
#include "printchessboard.h"
#include "evaluate.h"

bool makeMove(int x, int y, int color)
{
	//执行落子操作（chessboard[i][j]=1 & chessboard[i][j]=2）
	chessBoard[x][y] = color;
	moveStep.push_back(make_pair(x,y));
	piecesCount++;
	printf("make: %d %d %d\n", x, y, color);
	int delta = evaluate(x, y, color);
	if (color==black) VALUE_BLACK += delta;
	else VALUE_WHITE += delta;
	if (gameover(x,y,color)) return true;
	else return false;
}

bool unMakeMove()
{
	//撤销落子操作（chessboard[i][j]=0）
	pair<int, int> p1, p2;
	p1 = moveStep.back();
	moveStep.pop_back();
	p2 = moveStep.back();
	moveStep.pop_back();
	chessBoard[p1.first][p1.second] = 0;
	chessBoard[p2.first][p2.second] = 0;
	piecesCount -= 2;
	if (chessBoard[p1.first][p1.second] == 0 && chessBoard[p2.first][p2.second] == 0)
		return true;
	else
		return false;
}
