#ifndef _DEFINE_
#define _DEFINE_
//ȫ�ֱ�������

#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <ctime>
#include<vector>
using namespace std;

#define blank 0		//�հ׵�
#define black 1		//�ڷ�
#define white 2		//�׷�
#define inf (0x7fffffff)		
#define inboard(a,b) (a>0 && a<=15 && b>0 && b<=15)		//���ڼ����з��Ƿ���������

#define GRID_NUM 16	//���̹�ģ	

#define DEPTH 4 //�������
extern int chessBoard[GRID_NUM][GRID_NUM]; //����
extern int player;
extern int piecesCount;//������
extern vector<pair<int, int>> moveStep;//�������
extern int avg_time; //ƽ������ʱ��(ms)

int gameover(int x, int y, int player);//�ж��Ƿ���Ϸ����,0��δ������1����player��ʤ����2�Ǻ;֣��������ˣ�,����x,yΪ��ǰ���ӣ�playerΪ������ɫ

#endif


