#ifndef _DEFINE_
#define _DEFINE_
//全局变量定义

#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <ctime>
#include<vector>
using namespace std;

#define blank 0		//空白点
#define black 1		//黑方
#define white 2		//白方
#define inf (0x7fffffff)		
#define inboard(a,b) (a>0 && a<=15 && b>0 && b<=15)		//用于检验招法是否在棋盘上

#define GRID_NUM 16	//棋盘规模	

#define DEPTH 4 //搜索深度
extern int chessBoard[GRID_NUM][GRID_NUM]; //棋盘
extern int player;
extern int piecesCount;//棋子数
extern vector<pair<int, int>> moveStep;//保存棋局
extern int avg_time; //平均搜索时间(ms)

int gameover(int x, int y, int player);//判断是否游戏结束,0是未结束，1是有player方胜利，2是和局（棋盘满了）,输入x,y为当前落子，player为落子颜色

#endif


