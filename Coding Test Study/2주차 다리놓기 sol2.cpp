#include <iostream>
using namespace std;

// �����÷ο찡 �߻��ϱ� ������
// �� ���� ���ϰ� �� ���� ������ ����� �� ����
// �ϳ� ���ϰ� �ϳ� ������ �ݺ��ؼ�
// ���� ũ�⸦ �����ؾ� �Ѵ�.

// �ð����⵵�� O(N^2) ���� ������� Ǯ����.
// �� ����.

int main() {
	int n, r, divide;
	bool flag = 1;
	unsigned int result = 1;
	cin >> r >> n;
	
	// 30 C 12 -> 30 C 18 �� �ٲ��ֱ�
	if (n / 2 >= r) {
		r = n - r;
	}

	divide = n - r;

	if (n == r or r == 0) {
		cout << "1";
		return 0;
	}

	// 30 ~ 18 ���ϱ� , 12 ~ 1 ������
	while (flag) {
		result *= n;
		n--;

		while (divide != 0 and result % divide == 0) {
			result /= divide;
			divide--;
		}
		
		if (n - r == 0) {
			flag = 0;
		}
	}

	cout << result;

	return 0;
}