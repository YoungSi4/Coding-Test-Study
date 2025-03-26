#include<iostream>
#include<stack>
using namespace std;



int main() {
	// ���� �� �� �Է�
	int k;
	cin >> k;

	// ���� �� ó�� n
	int n;
	// ���� ����
	stack<int> moneyStack;
	int sum = 0;

	// �� �Է�
	for (int i = 0; i < k; i++) {
		cin >> n;
		
		if (n == 0) {
			moneyStack.pop();
		}
		else {
			moneyStack.push(n);
		}
	}

	// �� �ջ�
	while (!moneyStack.empty()) {
		sum += moneyStack.top();
		moneyStack.pop();
	}

	cout << sum << '\n';

	return 0;
}