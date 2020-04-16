#include "define.h"
#include "searchmove.h"
#include "printchessboard.h"
#include "makemove.h"
#include "evaluate.h"

int main()
{
	cout << "*************五子棋人机对弈AI*************" << endl;
	cout << "输入: newblack  电脑先手" << endl;
	cout << "输入: newwhite  电脑后手" << endl;
	cout << "输入: move x y  表示落子点" << endl;
	cout << "输入: remove  表示悔棋一步" << endl;
	srand(time(0));
	print();
	initPosValue(); //初始化棋盘估值
	string input;
	while (true) {
		cin >> input;
		if (input == "newblack") {
			player = white;
			searchMove();
			print();
			cout << "请落子" << endl;
		}
		else if (input == "newwhite") {
			player = black;
			cout << "请落子" << endl;
		}
		else if (input == "remove")
		{
			if (piecesCount >= 2)
			{
				if (unMakeMove())
					cout << "回退成功" << endl;
				else
					cout << "回退失败" << endl;
				print();
			}
			else
			{
				cout << "输入不合法，请重新输入" << endl;
			}
		}
		else if (input == "move") {
			int x, y;
			cin >> x >> y;
			if (inboard(x, y)&&chessBoard[x][y]==0) {
				bool gameOver = makeMove(x, y, player);
				if (gameOver) {
					print();
					cout << "游戏结束，玩家胜利" << endl;
					break;
				}
				print();
				gameOver = searchMove();
				print();
				if (gameOver) {
					cout << "游戏结束，电脑胜利" << endl;
					break;
				}
				else cout << "请落子" << endl;
			}
			else {
				cout << "输入不合法，请重新输入" << endl;
			}
		}
		else {
			cout << "输入不合法，请重新输入" << endl;
		}
	}

	cout << "是否复盘？输入yes为复盘，否则程序结束" << endl;
	cin >> input;
	if (input == "yes")
	{
		cout << "每一步输入一个字母进行下一步" << endl;
		for (int i = 1; i < GRID_NUM; i++)
		{
			for (int j = 1; j < GRID_NUM; j++)
			{
				chessBoard[i][j] = 0;
			}
		}
		for (int i = 0; i < moveStep.size(); i++)
		{
			chessBoard[moveStep[i].first][moveStep[i].second] = black;
			print();
			cin >> input;
			i++;
			if (i < moveStep.size())
			{
				chessBoard[moveStep[i].first][moveStep[i].second] = white;
				print();
			}
			cin >> input;
		}
	}
}
