#include "define.h"
int gameover(int x, int y, int player)//判断是否游戏结束
{
	int offset[4] = { 1,GRID_NUM - 1,GRID_NUM,GRID_NUM + 1 };
	int cnt;
	int offsetX[4] = { 0,1,1,1 }, offsetY[4] = { 1 , 0 ,1,-1 };
	for (int i = 0; i < 4; i++)
	{
		cnt = 1;
		int k = 4;
		int x1 = x, y1 = y;
		while (k--)
		{
			x1 -= offsetX[i];
			y1 -= offsetY[i];
			if (x1 > 0 && x1 < GRID_NUM && y1 > 0 && y1 < GRID_NUM && chessBoard[x1][y1] == player)
			{
				++cnt;
			}
			else
				break;
		}
		k = 4;
		x1 = x;
		y1 = y;
		//检查右边的连子数
		while (k--)
		{
			x1 += offsetX[i];
			y1 += offsetY[i];
			if (x1 > -1 && x1 < GRID_NUM && y1 > -1 && y1 < GRID_NUM && chessBoard[x1][y1] == player)
			{
				++cnt;
			}
			else
				break;
		}
		if (cnt >= 5)
		{
			return 1;
		}
		else if (cnt < 5 && piecesCount >= (GRID_NUM - 1) * (GRID_NUM - 1))
		{
			return 2;
		}

	}
	return 0;
}
