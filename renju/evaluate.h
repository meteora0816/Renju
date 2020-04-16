#ifndef _EVALUATE_
#define _EVALUATE_
//估值生成器
#include<string>
#include "define.h"

extern int posValue[GRID_NUM][GRID_NUM];
extern int VALUE_BLACK;
extern int VALUE_WHITE;

void initPosValue();//初始化棋盘估值，在游戏开始时需要调用一次

int evaluate(int, int, int);//估值算法，返回估值，x,y为点坐标，player为黑白子即black，white



#endif
