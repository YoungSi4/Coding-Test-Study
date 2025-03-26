#include <iostream>
using namespace std;

int main() {	
	// 변수 선언 및 초기화
	int count = 0, M, N;
	cin >> M >> N;

	// 둘 중 하나가 0이 될 때까지 반복
	while (M * N > 0) {
		// X를 -1 하고 카운트 +1
		M = M - 1;
		count = count + 1;
		// cout << "M 감소 이후: " << count << endl;

		// 만약 X가 0이 됐다면 즉시 탈출
		if (M <= 0) {
			break;
		}

		// Y를 -1하고 카운트 +1
		N = N - 1;
		count = count + 1;
		// cout << "N 감소 이후: " << count << endl;
	}

	// 마지막엔 꺾지 않고 바로 끝이므로 -1
	cout << count - 1;

	return 0;
}