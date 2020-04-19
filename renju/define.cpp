#include "define.h"

int chessBoard[GRID_NUM][GRID_NUM];//定义棋盘
int player;
int piecesCount = 0;
int avg_time;
vector<pair<int, int>> moveStep;//保存棋局