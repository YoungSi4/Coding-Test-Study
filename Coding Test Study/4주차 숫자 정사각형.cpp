#include <iostream>
using namespace std;

int main() {
	int n, m, side;
	char square[50][50];
	cin >> n >> m;

	// ���� �Է� ���� ���簢���� �� ������ ����
	if (n < m) {
		side = n;
	}
	else {
		side = m;
	}

	// N x M �Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> square[i][j];
		}
	}

	// ������ Ž��
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