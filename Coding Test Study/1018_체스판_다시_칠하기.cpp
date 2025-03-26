#include<iostream>
#include<string>
#include<limits.h>
using namespace std;

int main() {
	// Ȯ�ο� üĿ����
	char** checkerB = new char* [8]; // �������� ����
	char** checkerW  = new char* [8]; // ������� ����
	for (int i = 0; i < 8; i++) {
		checkerB[i] = new char[8];
		checkerW[i] = new char[8];
	}

	int m, n;
	int minNum = INT_MAX;

	int paintNumB = 0;
	int paintNumW = 0;

	// �� Ȯ�ο� üĿ���� �ʱ�ȭ
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			checkerB[i][j] = ( (i + j) % 2 == 0) ? 'B' : 'W';
			checkerW[i][j] = ((i + j) % 2 == 0) ? 'W' : 'B';
		}
	}

	// ü������ ũ��, �ּ� ���� ����
	
	cin >> m >> n;

	// �Է� ���� ü������
	string* chessBoard = new string [m];

	for (int i = 0; i < m; i++) {
		cin >> chessBoard[i];
	}


	// 8x8 ������ ������� Ž��, ������ ����� ����
	for (int i = 0; i < m - 7; i++) {
		for (int j = 0; j < n - 7; j++) {

			// �������� ���� ���� �������� 8x8�� Ž��
			for (int y = i; y < i + 8; y++) {
				for (int x = j; x < j + 8; x++) {
					if (chessBoard[y][x] != checkerB[y - i][x - j]) paintNumB++;
					if (chessBoard[y][x] != checkerW[y - i][x - j]) paintNumW++;
				}
			}

			// Ž�� �� �ּڰ��̶�� ����
			if (paintNumB < minNum) {
				minNum = paintNumB;
			}
			if (paintNumW < minNum) {
				minNum = paintNumW;
			}
			// �ʱ�ȭ
			paintNumB = 0;
			paintNumW = 0;
		}
	}
	
	cout << minNum << endl;

	// �޸� ȸ��
	delete[]	chessBoard;
	chessBoard = nullptr;
	for (int i = 0; i < 8; i++) {
		delete[] checkerB[i];
		delete[] checkerW[i];
	}
	delete[] checkerB;
	delete[] checkerW;

	return 0;
}