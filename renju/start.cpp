#include "define.h"
#include "searchmove.h"
#include "printchessboard.h"
#include "makemove.h"

int main()
{
	cout << "*************五子棋人机对弈AI*************" << endl;
	cout << "输入: newblack  电脑先手" << endl;
	cout << "输入: newwhite  电脑后手" << endl;
	cout << "输入: move x y  表示落子点" << endl;
	printf("%d %d\n", 1 ^ 3, 2 ^ 3);
	srand(time(0));
	print();
	string input;
	while (true) {
		cin >> input;
		if (input == "newblack") {
			player = 2;
			makeMove();
			print();
			cout << "请落子" << endl;
		}
		else if (input == "newwhite") {
			player = 1;
			cout << "请落子" << endl;
		}
		else if (input == "move") {
			int x, y;
			cin >> x >> y;
			if (inboard(x, y)) {
				chessBoard[x][y] = player;
				makeMove();
				print();
				cout << "请落子" << endl;
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
