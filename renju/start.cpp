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
	srand(time(0));
	print();
	string input;
	while (true) {
		cin >> input;
		if (input == "newblack") {
			player = white;
			searchMove();
			print();
			cout << "������" << endl;
		}
		else if (input == "newwhite") {
			player = black;
			cout << "������" << endl;
		}
		else if (input == "move") {
			int x, y;
			cin >> x >> y;
			if (inboard(x, y)) {
				makeMove(x, y, player);
				searchMove();
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
