#include "evaluate.h"
using namespace std;

int posValue[GRID_NUM][GRID_NUM];
// 匹配字符串，用来判断棋型
string pattern[39] = {
	"aaaaa",//连五
	"oaaaao",//活四
	"baaaao","oaaaab",///眠四
	"aoaaab","baaaoa","aaoaa","boaaaoa","aoaaaob",//低级死四
	"oaaaoo","ooaaao",//活三
	"oaaoao","oaoaao",//跳活三
	"baaaoo","ooaaab","baaoao","oaoaab","oaaoab","baoaao","aooaa","aaooa","aoaoa","boaaaob",//眠三
	"ooaaoo","oooaao","oaaooo",//活二
	"ooaoao","oaoaoo","oaooao",//低级活二
	"aaooo","oooaa","baoaoo","ooaoab","oaooab","baooao","aoooa","boaoaob","boaaoob","booaaob"//眠二
};
//给分数组
int scores[13] = { 1000000,100000,50000,10000,5000,4000,1000,900,500,100,90,50,20 };

int VALUE_BLACK = 0;
int VALUE_WHITE = 0;

void initPosValue()//初始化棋盘估值，在游戏开始时需要调用一次
{
	for (int i = 1; i < GRID_NUM; i++)
		for (int j = 1; j < GRID_NUM; j++)
			posValue[i][j] = min(min(i - 0, GRID_NUM - 1 - i), min(j - 0, GRID_NUM - 1 - j));
}

int getValue(int x, int y, int player)
{
	int value = posValue[x][y];
	int offsetX[4] = { 0,1,1,1 }, offsetY[4] = { 1 , 0 ,1,-1 };

	//棋型判断数组
	int patternCount[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int x1, y1;
	int k;
	//从四个方向考虑
	for (int i = 0; i < 4; i++)
	{
		string t;
		x1 = x;
		y1 = y;
		int k = 4;
		while (k--)
		{
			x1 -= offsetX[i];
			y1 -= offsetY[i];

			if (x1 > 0 && x1 < GRID_NUM && y1 > 0 && y1 < GRID_NUM)
			{
				if (!chessBoard[x1][y1])
					t.insert(0, 1, 'o');
				else if (chessBoard[x1][y1] == player)
					t.insert(0, 1, 'a');
				else if (chessBoard[x1][y1] != player)
					t.insert(0, 1, 'b');
			}
			else
				break;
		}
		t.push_back('a');
		k = 4;
		x1 = x;
		y1 = y;
		while (k--)
		{
			x1 += offsetX[i];
			y1 += offsetY[i];
			if (x1 > 0 && x1 < GRID_NUM && y1 > 0 && y1 < GRID_NUM)
			{
				if (!chessBoard[x1][y1])
					t.push_back('o');
				else if (chessBoard[x1][y1] == player)
					t.push_back('a');
				else if (chessBoard[x1][y1] != player)
					t.push_back('b');
			}
			else
				break;
		}

		for (k = 0; k < 39; ++k)
		{
			if (t.find(pattern[k]) != string::npos)
			{
				break;
			}

		}
		if (k < 37)
		{
			if (k == 0)
				++patternCount[0];
			else if (k == 1)
				++patternCount[1];
			else if (k > 1 && k < 4)
				++patternCount[2];
			else if (k > 3 && k < 9)
				++patternCount[3];
			else if (k > 8 && k < 11)
				++patternCount[4];
			else if (k > 10 && k < 13)
				++patternCount[5];
			else if (k > 12 && k < 23)
				++patternCount[6];
			else if (k > 22 && k < 26)
				++patternCount[7];
			else if (k > 25 && k < 29)
				++patternCount[8];
			else if (k > 28 && k < 39)
				++patternCount[9];
		}
	}
	///综合四个方向的评分
	if (patternCount[0] >= 1)
		value += scores[0];
	else if (patternCount[1] > 0 || patternCount[2] + patternCount[3] > 1 || ((patternCount[2] + patternCount[3]) == 1 && (patternCount[4] + patternCount[5]) == 1))
		value += scores[1];
	else if (patternCount[4] + patternCount[5] > 1)
		value += scores[2];
	else if (patternCount[4] >= 1 && patternCount[6] >= 1)
		value += scores[3];
	else if (patternCount[2] >= 1)
		value += scores[4];
	else if (patternCount[3] >= 1)
		value += scores[5];
	else if (patternCount[4] >= 1)
		value += scores[6];
	else if (patternCount[5] >= 1)
		value += scores[7];
	else if (patternCount[7] + patternCount[8] > 1)
		value += scores[8];
	else if (patternCount[7] > 0)
		value += scores[9];
	else if (patternCount[8] > 0)
		value += scores[10];
	else if (patternCount[6] > 0)
		value += scores[11];
	else if (patternCount[9] > 0)
		value += scores[12];
	return value;
}

int evaluate(int x, int y, int color)//估值算法，返回估值，x,y为点坐标，player为黑白子即black，white
{
	int result = 0;
	result = getValue(x, y, color);// +getValue(x, y, color ^ 3);//考虑对自己的利益与减少敌人利益
	return result;
}



//由于五子棋搜索分支庞大，通常无法直接搜索到胜负终局，当搜索到一定深度时需要根据局面返回搜索结果。
//参考资料：
//张明亮, 吴俊, 李凡长. 五子棋机器博弈系统评估函数的设计[J]. 计算机应用, 2012, 32(07):1969-1972.
//裴博文. 五子棋人工智能权重估值算法[J]. 电脑编程技巧与维护, 2008(6):69-75.
//https://www.cnblogs.com/maxuewei2/p/4825520.html