#include "createmoves.h"
#include <algorithm>

bool valid(int x, int y)
{
	if (chessBoard[x][y] != 0) return false;
	for (int i = -2; i <= 2; i++) {
		for (int j = -2; j <= 2; j++) {
			if (i == 0 && j == 0) continue;
			if (!inboard(x + i, y + j)) continue;
			if (chessBoard[x + i][y + j] != 0) return true;
		}
	}
	return false;
}

int tmp_moves[15 * 15], tmp_values[15 * 15], idx[15 * 15];
bool cmp(int a, int b) { return tmp_values[a] > tmp_values[b]; }
int createMoves(int *moves, int *values, int color) //生成全部合法走法集
{
	int len = 0;
	for (int i = 1; i < 16; i++) {
		for (int j = 1; j < 16; j++) {
			if (!valid(i, j)) continue;
			tmp_moves[len] = (i - 1) * 15 + j;
			tmp_values[len] = evaluate(i, j, color);
			idx[len] = len;
			len++;
		}
	}
	sort(idx, idx + len, cmp);
	for (int i = 0; i < len; i++) {
		moves[i] = tmp_moves[idx[i]];
		values[i] = tmp_values[idx[i]];
	}
	return len;
}
//查找所有合法落子点。对于五子棋来说，棋盘上的空白点均为可行走法。