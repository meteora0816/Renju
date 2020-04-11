#include "define.h"
#include "searchmove.h"
#include "printchessboard.h"
#include "makemove.h"

int main()
{
	cout << "*************�������˻�����AI*************" << endl;
	cout << "����: newblack  ��������" << endl;
	cout << "����: newwhite  ���Ժ���" << endl;
	cout << "����: move x y  ��ʾ���ӵ�" << endl;
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
			cout << "������" << endl;
		}
		else if (input == "newwhite") {
			player = 1;
			cout << "������" << endl;
		}
		else if (input == "move") {
			int x, y;
			cin >> x >> y;
			if (inboard(x, y)) {
				chessBoard[x][y] = player;
				makeMove();
				print();
				cout << "������" << endl;
			}
			else {
				cout << "���벻�Ϸ�������������" << endl;
			}
		}
		else {
			cout << "���벻�Ϸ�������������" << endl;
		}
	}
}
