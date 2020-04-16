#include "define.h"
#include "searchmove.h"
#include "printchessboard.h"
#include "makemove.h"
#include "evaluate.h"

int main()
{
	cout << "*************�������˻�����AI*************" << endl;
	cout << "����: newblack  ��������" << endl;
	cout << "����: newwhite  ���Ժ���" << endl;
	cout << "����: move x y  ��ʾ���ӵ�" << endl;
	cout << "����: remove  ��ʾ����һ��" << endl;
	srand(time(0));
	print();
	initPosValue(); //��ʼ�����̹�ֵ
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
		else if (input == "remove")
		{
			if (piecesCount >= 2)
			{
				if (unMakeMove())
					cout << "���˳ɹ�" << endl;
				else
					cout << "����ʧ��" << endl;
				print();
			}
			else
			{
				cout << "���벻�Ϸ�������������" << endl;
			}
		}
		else if (input == "move") {
			int x, y;
			cin >> x >> y;
			if (inboard(x, y)&&chessBoard[x][y]==0) {
				bool gameOver = makeMove(x, y, player);
				if (gameOver) {
					print();
					cout << "��Ϸ���������ʤ��" << endl;
					break;
				}
				print();
				gameOver = searchMove();
				print();
				if (gameOver) {
					cout << "��Ϸ����������ʤ��" << endl;
					break;
				}
				else cout << "������" << endl;
			}
			else {
				cout << "���벻�Ϸ�������������" << endl;
			}
		}
		else {
			cout << "���벻�Ϸ�������������" << endl;
		}
	}

	cout << "�Ƿ��̣�����yesΪ���̣�����������" << endl;
	cin >> input;
	if (input == "yes")
	{
		cout << "ÿһ������һ����ĸ������һ��" << endl;
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
