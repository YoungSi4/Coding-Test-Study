#include <iostream>
using namespace std;

// �����÷ο찡 �߻��Ͽ� 30 C 15�� ����� �� ����.
int main() {
	// ���� ����, �ʱ�ȭ
	unsigned int r, n, num_cond, deno_cond, result;
	cin >> r >> n;

	// num_cond ����
	if (n - r >= r) {
		num_cond = n - r;
		deno_cond = r;
	}
	else {
		num_cond = r;
		deno_cond = n - r;
	}

	// 1. n ~ num_cond + 1���� ���ϱ�
	for (n; n > num_cond; n--) {
		
	}

	// 2. deno_cond ~ 2�� �� ����ϱ�
	for (deno_cond; deno_cond > 1; deno_cond--) {
		
	}

	// 3. ������ ���� ����� �� ���ϱ�
	cout << result;

	// �ð� ���⵵�� O(N) + O(N)�ε� �� �������� �� �ֳ�?
	// memoization�� ����ϸ� �ǳ�?
	return 0;
}