#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	/*
		n���� �ְ� Pi�� �ִ�
		
		P : 3 1 4 3 2
		���� 1 2 3 4 5 -> SUM( 3*5 + 1*4 + 4*3 + 4*2 + 2*1 )

		�� �տ� �������� ���� ���� -> �������� ���� �ʿ�
		�� �� ���
	*/

	int n; // ��� ��

	int timeSumMin = 0; // �ð� �հ�

	// input
	cin >> n;
	int* time = new int[n];
	// Pi : i���� ���� �����ϴµ� �ɸ��� �ð�
	
	for (int i = 0; i < n; i++) {
		cin >> time[i];
	}

	// ������������ ����
	sort(time, time+n); // start() -> end()
	for (int i = 0; i < n; i++) {
		timeSumMin += time[i] * (n - i);
	}

	// ��� ���
	cout << timeSumMin << '\n';

	// �޸� ȸ��
	delete[] time;

	return 0;
}