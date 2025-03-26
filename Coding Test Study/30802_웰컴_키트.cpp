#include<iostream>
#include<vector>
using namespace std;

int main() {
	// n : ������ ��, s : ������ ��
	int n, s;
	cin >> n;

	// Ƽ���� ������ �Է� �ޱ�
	vector<int> TshirtsSize;
	for (int i = 0; i < 6; i++) {
		cin >> s;
		TshirtsSize.push_back(s);
	}

	// Ƽ���� ���� ��, �� ���� ��
	int t, p;
	cin >> t >> p;

	int tshirtSet = 0;
	for (int i = 0; i < 6; i++) {
		if (TshirtsSize[i] % t != 0) {
			tshirtSet += (TshirtsSize[i] / t) + 1;
		}
		else {
			tshirtSet += TshirtsSize[i] / t;
		}
	}

	int penSet, pen;
	penSet = n / p;
	pen = n % p;

	// ���
	cout << tshirtSet << '\n' << penSet << " " << pen << '\n';

	return 0;
}