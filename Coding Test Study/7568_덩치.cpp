#include<iostream>
using namespace std;

int main() {
	// ����� ��
	int n;
	cin >> n;

	// 2�� ������ �迭 ����
	int** peopleArray = new int* [n];
	for (int i = 0; i < n; i++) {
		peopleArray[i] = new int[3];
	}

	// 2�� �����Ϳ� �ޱ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> peopleArray[i][j];
		}
		peopleArray[i][2] = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((peopleArray[i][0] < peopleArray[j][0]) && (peopleArray[i][1] < peopleArray[j][1])) {
				peopleArray[i][2]++;
			}
		}
	}

	// ��� ���
	for (int i = 0; i < n; i++) {
		cout << peopleArray[i][2] + 1 << " ";
	}

	// �޸� ȸ��
	for (int i = 0; i < n; i++) {
		delete[] peopleArray[i];
	}
	delete[] peopleArray;

	return 0;
}