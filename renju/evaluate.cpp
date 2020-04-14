#include "evaluate.h"
using namespace std;

int posValue[GRID_NUM][GRID_NUM];
// ƥ���ַ����������ж�����
string pattern[39] = {
	"aaaaa",///0:����
	"oaaaao",///1:����
	"baaaao","oaaaab",///2~3����
	"aoaaab","baaaoa","aaoaa","boaaaoa","aoaaaob",///4~8�ͼ�����
	"oaaaoo","ooaaao",///9~10����
	"oaaoao","oaoaao",///11~12������
	"baaaoo","ooaaab","baaoao","oaoaab","oaaoab","baoaao","aooaa","aaooa","aoaoa","boaaaob",///13~22����
	"ooaaoo","oooaao","oaaooo",///23~25���
	"ooaoao","oaoaoo","oaooao",///26~28�ͼ����
	"aaooo","oooaa","baoaoo","ooaoab","oaooab","baooao","aoooa","boaoaob","boaaoob","booaaob"///29~38�߶�
};
//���ݲ�ͬ�ĳ������и���
int scores[13] = { 1000000,100000,50000,10000,5000,4000,1000,900,500,100,90,50,20 };

int VALUE_BLACK = 0;
int VALUE_WHITE = 0;

void initPosValue()//��ʼ�����̹�ֵ������Ϸ��ʼʱ��Ҫ����һ��
{
	for (int i = 1; i < GRID_NUM; i++)
		for (int j = 1; j < GRID_NUM; j++)
			posValue[i][j] = min(min(i - 0, GRID_NUM - 1 - i), min(j - 0, GRID_NUM - 1 - j));
}

int getValue(int x, int y, int player)
{
	int value = posValue[x][y];
	int offsetX[4] = { 0,1,1,1 }, offsetY[4] = { 1 , 0 ,1,-1 };

	//�����ж�����
	int patternCnt[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int x1, y1;
	int k;
	//���ĸ�������
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
				++patternCnt[0];
			else if (k == 1)
				++patternCnt[1];
			else if (k > 1 && k < 4)
				++patternCnt[2];
			else if (k > 3 && k < 9)
				++patternCnt[3];
			else if (k > 8 && k < 11)
				++patternCnt[4];
			else if (k > 10 && k < 13)
				++patternCnt[5];
			else if (k > 12 && k < 23)
				++patternCnt[6];
			else if (k > 22 && k < 26)
				++patternCnt[7];
			else if (k > 25 && k < 29)
				++patternCnt[8];
			else if (k > 28 && k < 39)
				++patternCnt[9];
		}
	}
	///�ۺ��ĸ����������
	if (patternCnt[0] >= 1)
		value += scores[0];
	else if (patternCnt[1] > 0 || patternCnt[2] + patternCnt[3] > 1 || ((patternCnt[2] + patternCnt[3]) == 1 && (patternCnt[4] + patternCnt[5]) == 1))
		value += scores[1];
	else if (patternCnt[4] + patternCnt[5] > 1)
		value += scores[2];
	else if (patternCnt[4] >= 1 && patternCnt[6] >= 1)
		value += scores[3];
	else if (patternCnt[2] >= 1)
		value += scores[4];
	else if (patternCnt[3] >= 1)
		value += scores[5];
	else if (patternCnt[4] >= 1)
		value += scores[6];
	else if (patternCnt[5] >= 1)
		value += scores[7];
	else if (patternCnt[7] + patternCnt[8] > 1)
		value += scores[8];
	else if (patternCnt[7] > 0)
		value += scores[9];
	else if (patternCnt[8] > 0)
		value += scores[10];
	else if (patternCnt[6] > 0)
		value += scores[11];
	else if (patternCnt[9] > 0)
		value += scores[12];
	return value;
}

int evaluate(int x, int y)//��ֵ�㷨�����ع�ֵ��x,yΪ�����꣬playerΪ�ڰ��Ӽ�black��white
{
	int result = 0;
	result = getValue(x, y, black) + getValue(x, y, white);//���Ƕ��Լ�����������ٵ�������
	return result;
}



//����������������֧�Ӵ�ͨ���޷�ֱ��������ʤ���վ֣���������һ�����ʱ��Ҫ���ݾ��淵�����������
//�ο����ϣ�
//������, �⿡, ���. �������������ϵͳ�������������[J]. �����Ӧ��, 2012, 32(07):1969-1972.
//�Ჩ��. �������˹�����Ȩ�ع�ֵ�㷨[J]. ���Ա�̼�����ά��, 2008(6):69-75.
//https://www.cnblogs.com/maxuewei2/p/4825520.html