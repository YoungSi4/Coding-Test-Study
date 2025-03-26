#include<iostream>
#include<queue>
using namespace std;

int main() {
	// ī�� �� ��
	int n;
	cin >> n;

	// ����� queue
	queue<int> cardQueue;
	bool threshold = true; // true : ������, false : �ڿ� enqueue

	// ī�� ä���
	for (int i = 1; i <= n; i++) {
		cardQueue.push(i);
	}

	// ���� ����
	// �� �� ������ �� �� �ڿ� enqueue�ϰ� �ݺ�
	// 1�常 ���� ������
	while (!(cardQueue.size() == 1)) {
		if (threshold) {
			cardQueue.pop();
			threshold = false;
		}
		else {
			cardQueue.push(cardQueue.front());
			cardQueue.pop();
			threshold = true;
		}
	}

	// ������ �ϳ� ���
	cout << cardQueue.front() << '\n';

	return 0;
}