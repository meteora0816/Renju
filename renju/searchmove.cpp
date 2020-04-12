#include "define.h"
#include "createmoves.h"
#include "makemove.h"
#include "evaluate.h"
#include "printchessboard.h"
int dfs(int &x, int &y, int color, int c) 
{
	if (c > 3) {
		return evaluate(player ^ 3);
	}
	if (c % 2) {
		int MAX = -0x7fffffff;
		for (int i = 1; i < 16; i++) {
			for (int j = 1; j < 16; j++) {
				if (chessBoard[i][j] != 0) continue;
				chessBoard[i][j] = color;
				int eva = dfs(x, y, color, c + 1);
				if (eva > MAX) {
					MAX = eva;
					x = i;
					y = j;
				}
				chessBoard[i][j] = 0;
			}
		}
		return MAX;
	}
	else {
		int MIN = 0x7fffffff;
		for (int i = 1; i < 16; i++) {
			for (int j = 1; j < 16; j++) {
				if (chessBoard[i][j] != 0) continue;
				chessBoard[i][j] = color;
				int eva = dfs(x, y, color, c + 1);
				if (eva < MIN) {
					MIN = eva;
					x = i;
					y = j;
				}
				chessBoard[i][j] = 0;
			}
		}
		return MIN;
	}
}
int searchMove() //ËÑË÷º¯ÊýÖ÷Ìå
{
	int x, y;
	/*x = rand() % 15 + 1;
	y = rand() % 15 + 1;
	while (chessBoard[x][y] != 0) {
		x = rand() % 15 + 1;
		y = rand() % 15 + 1;
	}*/
	dfs(x, y, player ^ 3, 1);
	makeMove(x, y, player ^ 3);
	return 0;
}
