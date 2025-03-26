#include<iostream>
using namespace std;

// ��ͷ� Ǯ�� Ÿ�Ӿƿ� ������ �Ƹ�?
// 2 <= n <= 2^7

int main() {
	int blue = 0, white = 0, sum = 0;

	int n; // ���� �� ���� ����
	cin >> n;
	
	// ����
	int** paper = new int* [n];
	for (int i = 0; i < n; i++) {
		paper[i] = new int[n];
	}

	// �Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[j][i];
		}
	}

	/*
		n x n ũ���� ĭ���� ��ĳ��

		�� ���� ���̰�
		n ���� �˻� -> ��� ���� ���ΰ�?
		yes -> ���� -> ���� ���� ���� ����
		no -> 4�и����� �ڸ���

		n/2���� �˻� -> ���� ����
		yes -> ���� -> ���� ���� ���� ����
		no -> n/2 �� ��������

		...

		n == 1 (basic case) -> ���⼱ ���� �� �� �� ���� ����
	*/

	// �� ���� ���̰� 1�� �� ������
	int a = n;

	while (a >= 1) {

		// �˻� ���� ��ǥ ����
		for (int y = 0; y * a < n; y++) {
			for (int x = 0; x * a < n; x++) {

				// ��ǥ �˻�
				for (int i = 0; i < a; i++) {
					for (int j = 0; j < a; j++) {
						// 0 : ���  1 : �Ķ���
						sum += paper[a * y + i][a * x + j];
					}
				}

				// ���� �� ���� �� �ش� ���� ��ȿȭ
				if (sum == a * a) {
					blue++;
					for (int i = 0; i < a; i++) {
						for (int j = 0; j < a; j++) {
							paper[a* y + i][a * x + j] = -1;
						}
					}
				}
				else if (sum == 0) {
					white++;
					for (int i = 0; i < a; i++) {
						for (int j = 0; j < a; j++) {
							paper[a * y + i][a * x + j] = -1;
						}
					}
				}

				// sum �� �ʱ�ȭ
				sum = 0;
			}
		}

		// �˻� ���� ����
		a /= 2;
	}


	cout << white << '\n' << blue << '\n';

	// ȸ��
	for (int i = 0; i < n; i++) {
		delete[] paper[i];
	}
	delete[] paper;

	return 0;
}
