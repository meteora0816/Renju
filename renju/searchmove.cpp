#include "define.h"
#include "createmoves.h"
#include "makemove.h"
#include "evaluate.h"
#include "printchessboard.h"
bool tooFar(int x, int y)
{
	for (int i = -2; i <= 2; i++) {
		for (int j = -2; j <= 2; j++) {
			if (i == 0 && j == 0) continue;
			if (!inboard(x+i,y+j)) continue;
			if (chessBoard[x + i][y + j] != 0) return false;
		}
	}
	return true;
}
int x, y;
int dfs(int color, int dep, int val_ai, int val_player, int alpha, int beta) 
{
	if (dep > 2) {
		return val_ai-val_player;
	}
	if (dep % 2) {
		int MAX = -inf;
		for (int i = 1; i < 16; i++) {
			for (int j = 1; j < 16; j++) {
				if (chessBoard[i][j] != 0) continue;
				if (piecesCount!=0&&tooFar(i, j)) continue;
				chessBoard[i][j] = color;
				int eva = dfs(color, dep + 1, val_ai + evaluate(i, j), val_player, alpha, beta);
				chessBoard[i][j] = 0;
				//if (dep == 1) printf("%d %d %d\n", i, j, eva);
				if (eva > MAX) {
					MAX = eva;
					if (dep == 1) {
						x = i;
						y = j;
					}
				}
				if (eva > alpha) {
					alpha = eva;
				}
				if (eva >= beta) {
					return eva;
				}
			}
		}
		return MAX;
	}
	else {
		int MIN = inf;
		for (int i = 1; i < 16; i++) {
			for (int j = 1; j < 16; j++) {
				if (chessBoard[i][j] != 0) continue;
				chessBoard[i][j] = color;
				int eva = dfs(color, dep + 1, val_ai, val_player + evaluate(i, j), alpha, beta);
				chessBoard[i][j] = 0;
				if (eva < MIN) {
					MIN = eva;
					if (dep == 1) {
						x = i;
						y = j;
					}
				}
				if (eva <= alpha) {
					return eva;
				}
				if (eva < beta) {
					beta = eva;
				}
			}
		}
		return MIN;
	}
}
int searchMove() //ËÑË÷º¯ÊýÖ÷Ìå
{
	printf("Search starts\n");
	if (piecesCount == 0) {
		return makeMove(8, 8, player ^ 3);
	}
	x = y = 0;
	if (player==white) dfs(player ^ 3, 1, VALUE_BLACK, VALUE_WHITE, -inf, inf);
	else dfs(player ^ 3, 1, VALUE_WHITE, VALUE_BLACK, -inf, inf);
	//printf("%d %d\n", x, y);
	return makeMove(x, y, player ^ 3);
}
