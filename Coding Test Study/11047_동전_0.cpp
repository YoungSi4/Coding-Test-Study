#include<iostream>
using namespace std;


int main() {
	int n, k, coinNum = 0; // n: ���� ����,  k : ���� ��ġ�� ��
	cin >> n >> k;

	int* coinValue = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> coinValue[i]; // ��������
	}

	/*
		Ex ) k : 4200
		coinValue < k �� ���� ���� coinValue �� Ȯ��
		/ ���� : ���� Ȯ��
		% ���� : ���� �� Ȯ��

		���� ������ �ݺ�
		��. ���� �� �¾� �������� �Ѵ�
	*/

	for (int i = n - 1; 0 <= i; i--) {
		if (coinValue[i] <= k) {
			coinNum += k / coinValue[i];
			k = k % coinValue[i];
		}
	}
	
	cout << coinNum;

	return 0;
}