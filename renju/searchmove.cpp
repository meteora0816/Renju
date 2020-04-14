#include "define.h"
#include "createmoves.h"
#include "makemove.h"
#include "evaluate.h"
#include "printchessboard.h"
int dfs(int &x, int &y, int color, int dep, int val_ai, int val_player) 
{
	if (dep > 2) {
		return val_ai-val_player;
	}
	if (dep % 2) {
		int MAX = -0x7fffffff;
		for (int i = 1; i < 16; i++) {
			for (int j = 1; j < 16; j++) {
				if (chessBoard[i][j] != 0) continue;
				chessBoard[i][j] = color;
				int eva = dfs(x, y, color, dep + 1, val_ai + evaluate(i, j), val_player);
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
				int eva = dfs(x, y, color, dep + 1, val_ai, val_player + evaluate(i, j));
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
	if (player==white) dfs(x, y, player ^ 3, 1, VALUE_BLACK, VALUE_WHITE);
	else dfs(x, y, player ^ 3, 1, VALUE_WHITE, VALUE_BLACK);
	return makeMove(x, y, player ^ 3);
}
