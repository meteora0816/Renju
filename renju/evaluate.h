#ifndef _EVALUATE_
#define _EVALUATE_
//��ֵ������
#include<string>
#include "define.h"

extern int posValue[GRID_NUM][GRID_NUM];
extern int VALUE_BLACK;
extern int VALUE_WHITE;

void initPosValue();//��ʼ�����̹�ֵ������Ϸ��ʼʱ��Ҫ����һ��

int evaluate(int, int, int);//��ֵ�㷨�����ع�ֵ��x,yΪ�����꣬playerΪ�ڰ��Ӽ�black��white



#endif
