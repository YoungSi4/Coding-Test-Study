#include<iostream>
#include<stack>
using namespace std;



int main() {
	// 받을 줄 수 입력
	int k;
	cin >> k;

	// 받을 수 처리 n
	int n;
	// 담을 스택
	stack<int> moneyStack;
	int sum = 0;

	// 값 입력
	for (int i = 0; i < k; i++) {
		cin >> n;
		
		if (n == 0) {
			moneyStack.pop();
		}
		else {
			moneyStack.push(n);
		}
	}

	// 값 합산
	while (!moneyStack.empty()) {
		sum += moneyStack.top();
		moneyStack.pop();
	}

	cout << sum << '\n';

	return 0;
}