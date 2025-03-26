#include<iostream>
#include<string>
#include<stack>
using namespace std;

/************
1. ���� ��Ʈ�� ������ �ޱ�
2. while(cin >> )���� ��Ʈ�� �Է� �ޱ� (�̰� for�� ���ΰ�)
3. stack�� �޾ƾ���!!!
4. �����鼭 �˻�
  4-1. ' ) ' �� ������ ���
  4-2. ' ) ' �� ���� ���
  4-3. �� �´� ���
5. ��� ���
6. �ݺ�.
*************/

int main() {
	stack<char> parenthesisStack; // push top pop
	bool isVPS;

	// �Է� �ޱ�
	int n;
	cin >> n;
	cin.ignore();

	// �Է� �ޱ�
	for (int i = 0; i < n; i++) {
		string parenthesisString;
		if (!getline(cin, parenthesisString)) break;
		isVPS = true; // �ʱ�ȭ

		// �˻� ����
		for (int j = 0; j < parenthesisString.length(); j++) {
			if (parenthesisString[j] == '(') {
				parenthesisStack.push('(');
			}
			// ���� ��� �Ÿ���
			else if (parenthesisString[j] == ')') {
				if (parenthesisStack.empty()) {
					isVPS = false;
					break;
				}
				else { // ������ ( �� ���� ����
					parenthesisStack.pop();
				}
			}
		}

		if (!parenthesisStack.empty() && isVPS) {
			// ���� �ȿ� ���� ���
			isVPS = false;
		}

		// ��� ���
		if (isVPS) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

		// ����, ���ڿ� �ʱ�ȭ
		while (!parenthesisStack.empty()) parenthesisStack.pop();
		parenthesisString = "";
	}

	return 0;
}