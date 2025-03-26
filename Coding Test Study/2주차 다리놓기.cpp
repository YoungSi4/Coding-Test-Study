#include <iostream>
using namespace std;

// 오버플로우가 발생하여 30 C 15를 계산할 수 없다.
int main() {
	// 변수 선언, 초기화
	unsigned int r, n, num_cond, deno_cond, result;
	cin >> r >> n;

	// num_cond 설정
	if (n - r >= r) {
		num_cond = n - r;
		deno_cond = r;
	}
	else {
		num_cond = r;
		deno_cond = n - r;
	}

	// 1. n ~ num_cond + 1까지 곱하기
	for (n; n > num_cond; n--) {
		
	}

	// 2. deno_cond ~ 2의 곱 계산하기
	for (deno_cond; deno_cond > 1; deno_cond--) {
		
	}

	// 3. 나눠서 조합 경우의 수 구하기
	cout << result;

	// 시간 복잡도가 O(N) + O(N)인데 더 간단해질 수 있나?
	// memoization을 사용하면 되나?
	return 0;
}