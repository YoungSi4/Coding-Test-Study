#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	/*
		t : �׽�Ʈ ���̽�
		n : �ǻ� ��
		str1, str2 : �ǻ� �̸�, �ǻ� ����
	*/

	// ����
	// �� �������� �� ������ n+1C1 x n+1C1 x ... x n+1Cr - 1 (�ƹ��͵� �� ���� ���)
	// 
	//
	
	int t; // �׽�Ʈ ���̽�
	cin >> t;

	for (; t--;) {
		int n; // �ǻ� ��
		cin >> n;

		map<string, int> closet;

		// �ޱ�
		for (int i = 0; i < n; i++) {
			string clothName, clothPart;
			cin >> clothName >> clothPart;

			closet[clothPart]++;
		}

		// ���� �� ����
		int combination = 1;
		for (const auto &pair : closet) {
			combination *= (pair.second + 1);
		}

		combination--;

		cout << combination << '\n';
	}



	return 0;
}