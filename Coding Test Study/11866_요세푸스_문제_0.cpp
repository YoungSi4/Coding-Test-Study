#include<iostream>
#include<queue>
using namespace std;

// ���� ť�� ���

int main() {
	int n, k, count = 0; // n: ��� ��, k: k��° ����, count : k��° ���� �뵵
	queue<int> joseputh; // ���� ť... ó�� Ȱ���� ����
	// �������� �ʴ� ���� enqueue ���� dequeue
	// �����ϴ� ���� �׷��� queue
	
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		joseputh.push(i + 1);
	}

	// ��� �� ��ó��
	cout << "<";
	while (!joseputh.empty()) {
		count++;
		if (count == k) {
			cout << joseputh.front();
			joseputh.pop();
			if (!joseputh.empty()) cout << ", ";
			count = 0;
		}
		else {
			joseputh.push(joseputh.front());
			joseputh.pop();
		}
	}
	cout << ">" << '\n';

	return 0;
}