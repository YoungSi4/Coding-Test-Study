#include <iostream>
using namespace std;

// 오버플로우가 발생하기 때문에
// 한 번에 곱하고 한 번에 나눠서 계산할 수 없고
// 하나 곱하고 하나 나누고를 반복해서
// 값의 크기를 제어해야 한다.

// 시간복잡도를 O(N^2) 보다 낮춰야지 풀린다.
// 못 했음.

int main() {
	int n, r, divide;
	bool flag = 1;
	unsigned int result = 1;
	cin >> r >> n;
	
	// 30 C 12 -> 30 C 18 로 바꿔주기
	if (n / 2 >= r) {
		r = n - r;
	}

	divide = n - r;

	if (n == r or r == 0) {
		cout << "1";
		return 0;
	}

	// 30 ~ 18 곱하기 , 12 ~ 1 나누기
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