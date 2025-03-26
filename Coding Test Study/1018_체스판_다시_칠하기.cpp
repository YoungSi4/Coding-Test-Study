#include<iostream>
#include<string>
#include<limits.h>
using namespace std;

int main() {
	// 확인용 체커보드
	char** checkerB = new char* [8]; // 검정으로 시작
	char** checkerW  = new char* [8]; // 흰색으로 시작
	for (int i = 0; i < 8; i++) {
		checkerB[i] = new char[8];
		checkerW[i] = new char[8];
	}

	int m, n;
	int minNum = INT_MAX;

	int paintNumB = 0;
	int paintNumW = 0;

	// 비교 확인용 체커보드 초기화
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			checkerB[i][j] = ( (i + j) % 2 == 0) ? 'B' : 'W';
			checkerW[i][j] = ((i + j) % 2 == 0) ? 'W' : 'B';
		}
	}

	// 체스보드 크기, 최소 변경 숫자
	
	cin >> m >> n;

	// 입력 받은 체스보드
	string* chessBoard = new string [m];

	for (int i = 0; i < m; i++) {
		cin >> chessBoard[i];
	}


	// 8x8 사이즈 윈도우로 탐색, 판정된 결과를 받음
	for (int i = 0; i < m - 7; i++) {
		for (int j = 0; j < n - 7; j++) {

			// 윈도우의 왼쪽 위를 기준으로 8x8을 탐색
			for (int y = i; y < i + 8; y++) {
				for (int x = j; x < j + 8; x++) {
					if (chessBoard[y][x] != checkerB[y - i][x - j]) paintNumB++;
					if (chessBoard[y][x] != checkerW[y - i][x - j]) paintNumW++;
				}
			}

			// 탐색 후 최솟값이라면 적용
			if (paintNumB < minNum) {
				minNum = paintNumB;
			}
			if (paintNumW < minNum) {
				minNum = paintNumW;
			}
			// 초기화
			paintNumB = 0;
			paintNumW = 0;
		}
	}
	
	cout << minNum << endl;

	// 메모리 회수
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