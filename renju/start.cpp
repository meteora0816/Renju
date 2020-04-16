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
		else if (input == "move") {
			int x, y;
			cin >> x >> y;
			if (inboard(x, y)) {
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
}
