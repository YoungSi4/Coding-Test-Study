#include <iostream>
using namespace std;

int main() {
	int n, m, side;
	char square[50][50];
	cin >> n >> m;

	// 작은 입력 값을 정사각형의 한 변으로 지정
	if (n < m) {
		side = n;
	}
	else {
		side = m;
	}

	// N x M 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> square[i][j];
		}
	}

	// 꼭짓점 탐색
	for (int k = side; k > 1; side--) {
		for (int i = 0; i < n - side; i++) {
			for (int j = 0; j < m - side; j++) {
				if (square[i][j] == square[i][j + side] && square[i][j] == square[i + side][j] && square[i][j] == square[i + side][j + side]) {
					cout << side + 1;
					return 0;
				}
			}
		}
	}
	cout << "1";

	return 0;
}