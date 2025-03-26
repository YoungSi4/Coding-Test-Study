#include<iostream>
#include<queue>
using namespace std;

int main() {
	// 카드 장 수
	int n;
	cin >> n;

	// 계산할 queue
	queue<int> cardQueue;
	bool threshold = true; // true : 버린다, false : 뒤에 enqueue

	// 카드 채우기
	for (int i = 1; i <= n; i++) {
		cardQueue.push(i);
	}

	// 동작 수행
	// 한 장 버리고 한 장 뒤에 enqueue하고 반복
	// 1장만 남을 때까지
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

	// 마지막 하나 출력
	cout << cardQueue.front() << '\n';

	return 0;
}