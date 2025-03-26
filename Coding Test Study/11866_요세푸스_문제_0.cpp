#include<iostream>
#include<queue>
using namespace std;

// 원형 큐를 사용

int main() {
	int n, k, count = 0; // n: 사람 수, k: k번째 제거, count : k번째 세는 용도
	queue<int> joseputh; // 원형 큐... 처럼 활용할 예정
	// 제거하지 않는 값은 enqueue 이후 dequeue
	// 제거하는 값은 그래도 queue
	
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		joseputh.push(i + 1);
	}

	// 출력 및 값처리
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