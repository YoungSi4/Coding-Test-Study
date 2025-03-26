#include<iostream>
using namespace std;

// 재귀로 풀면 타임아웃 나겠지 아마?
// 2 <= n <= 2^7

int main() {
	int blue = 0, white = 0, sum = 0;

	int n; // 종이 한 변의 길이
	cin >> n;
	
	// 생성
	int** paper = new int* [n];
	for (int i = 0; i < n; i++) {
		paper[i] = new int[n];
	}

	// 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[j][i];
		}
	}

	/*
		n x n 크기의 칸으로 스캐닝

		한 변의 길이가
		n 으로 검사 -> 모두 같은 색인가?
		yes -> 유지 -> 색에 따라 개수 증가
		no -> 4분면으로 자르기

		n/2으로 검사 -> 동일 조건
		yes -> 유지 -> 색에 따라 개수 증가
		no -> n/2 를 절반으로

		...

		n == 1 (basic case) -> 여기선 아직 안 된 곳 갯수 세긴
	*/

	// 한 변의 길이가 1이 될 때까지
	int a = n;

	while (a >= 1) {

		// 검사 시작 좌표 지정
		for (int y = 0; y * a < n; y++) {
			for (int x = 0; x * a < n; x++) {

				// 좌표 검사
				for (int i = 0; i < a; i++) {
					for (int j = 0; j < a; j++) {
						// 0 : 흰색  1 : 파란색
						sum += paper[a * y + i][a * x + j];
					}
				}

				// 종이 수 증가 및 해당 구역 무효화
				if (sum == a * a) {
					blue++;
					for (int i = 0; i < a; i++) {
						for (int j = 0; j < a; j++) {
							paper[a* y + i][a * x + j] = -1;
						}
					}
				}
				else if (sum == 0) {
					white++;
					for (int i = 0; i < a; i++) {
						for (int j = 0; j < a; j++) {
							paper[a * y + i][a * x + j] = -1;
						}
					}
				}

				// sum 값 초기화
				sum = 0;
			}
		}

		// 검사 범위 절반
		a /= 2;
	}


	cout << white << '\n' << blue << '\n';

	// 회수
	for (int i = 0; i < n; i++) {
		delete[] paper[i];
	}
	delete[] paper;

	return 0;
}
