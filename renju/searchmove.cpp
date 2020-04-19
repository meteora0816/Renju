#include "define.h"
#include "createmoves.h"
#include "makemove.h"
#include "evaluate.h"
#include "printchessboard.h"
#include <ctime>

int nx, ny;
int dfs(int color, int dep, int val_ai, int val_player, int alpha, int beta) 
{
	if (dep > DEPTH) {
		return val_ai-val_player;
	}
	int *moves = new int[15 * 15];
	int *values = new int[15 * 15];
	int len = createMoves(moves, values, color);
	if (dep % 2) {
		int MAX = -inf;
		for (int i = 0; i < len; i++) {
			int x = (moves[i] - 1) / 15 + 1;
			int y = (moves[i] - 1) % 15 + 1;
				chessBoard[x][y] = color;
				int eva = dfs(color ^ 3, dep + 1, val_ai + values[i], val_player, alpha, beta);
				chessBoard[x][y] = 0;
				if (eva > MAX) {
					MAX = eva;
					if (dep == 1) {
						nx = x;
						ny = y;
					}
				}
				if (eva > alpha) {
					alpha = eva;
				}
				if (eva >= beta) {
					return eva;
				}
		}
		delete moves;
		delete values;
		return MAX;
	}
	else {
		int MIN = inf;
		for (int i = 0; i < len; i++) {
			int x = (moves[i] - 1) / 15 + 1;
			int y = (moves[i] - 1) % 15 + 1;
				chessBoard[x][y] = color;
				int eva = dfs(color ^ 3, dep + 1, val_ai, val_player + values[i], alpha, beta);
				chessBoard[x][y] = 0;
				if (eva < MIN) {
					MIN = eva;
				}
				if (eva <= alpha) {
					return eva;
				}
				if (eva < beta) {
					beta = eva;
				}
		}
		delete moves;
		delete values;
		return MIN;
	}
}
int searchMove() //ËÑË÷º¯ÊýÖ÷Ìå
{
	printf("Search starts\n");
	int stt = clock();
	if (piecesCount == 0) {
		return makeMove(8, 8, player ^ 3);
	}
	nx = ny = 0;
	if (player==white) dfs(player ^ 3, 1, VALUE_BLACK, VALUE_WHITE, -inf, inf);
	else dfs(player ^ 3, 1, VALUE_WHITE, VALUE_BLACK, -inf, inf);
	printf("time: %d\n", clock()-stt);
	avg_time += clock() - stt;
	return makeMove(nx, ny, player ^ 3);
}
