#include<iostream>
#include<queue>
#include<array>
using namespace std;

int main() {
	/*
		방법 1 ) visited
		방법 2 ) 0 으로 바꾸기
	*/

	// t: 테스트 케이스 수
	// m: 가로 , n : 세로
	// k : 배추 수
	int t, m, n, k;
	cin >> t;
	
	// test case 수 만큼
	for (; t--;) {
		cin >> m >> n >> k;

		int whiteWorm = 0;
		int cursorWorm[2] = { 0, 0 }; // cursor 위치

		queue<array<int, 2>> next;

		// 배추밭 만들기
		int** baechuFarm = new int* [n];
		for (int i = 0; i < n; i++) {
			baechuFarm[i] = new int[m];
		}

		// 초기화
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				baechuFarm[i][j] = 0;
			}
		}

		// 배추 심기
		for (int i = 0; i < k; i++) {
			int p, q; // x y
			cin >> p >> q;

			baechuFarm[q][p] = 1;
		}

		// 검사
		// queue.front() == cursor 인지 확인 후 pop 필요
		// cursorWorm[2], cursorCount[2]

		// i, j 가 커서 위치
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {

				// 배추가 심어져 있다면

				if (baechuFarm[i][j] == 1) {
					// 상하좌우 확인
					// 상: 확인 불필요
					// 하: (i, j+1), 좌(i-1, j), 우(i+1, j)
					// out of range면 취소
					// 하: j != n, 좌 i != 0, 우 i != m

					// 최초 1회 실행 (queue 채우기 위함)
					// cursor 위치 지정
					cursorWorm[0] = i, cursorWorm[1] = j;

					// 주변 검사 - 이미 이 자리가 1 인건 확인하고 들어왔으므로 안 해도 됨
					// 아래
					if (j != n - 1 && baechuFarm[i][j + 1] == 1) {
						next.push({ i, j + 1 });
					}
					// 왼쪽
					if (i != 0 && baechuFarm[i - 1][j] == 1) {
						next.push({ i - 1, j });
					}
					// 오른쪽
					if (i != m - 1 && baechuFarm[i + 1][j] == 1) {
						next.push({ i + 1, j });
					}

					baechuFarm[i][j] = 0; // 체크

					// 반복  - 주변에 없으면 그냥 바로 아래로
					while (!next.empty()) {
						// 커서 이동
						cursorWorm[0] = next.front()[0];
						cursorWorm[1] = next.front()[1];
						next.pop();
						// 이동 후 체크
						baechuFarm[cursorWorm[0]][cursorWorm[1]] = 0;

						if (next.empty()) {}
						else if (cursorWorm[0] == next.front()[0] && cursorWorm[1] == next.front()[1]) {
							// 이동한 위치와 다음 이동할 위치가 동일하다면
							next.pop(); // 제거
						}
						
						// 아래
						if (cursorWorm[1] != n - 1 && baechuFarm[cursorWorm[0]][cursorWorm[1] + 1] == 1) {
							baechuFarm[cursorWorm[0]][cursorWorm[1] + 1] = 0;
							next.push({ cursorWorm[0], cursorWorm[1] + 1});
						}
						// 왼쪽
						if (cursorWorm[0] != 0 && baechuFarm[cursorWorm[0] - 1][cursorWorm[1]] == 1) {
							baechuFarm[cursorWorm[0] - 1][cursorWorm[1]] = 0;
							next.push({ cursorWorm[0] - 1, cursorWorm[1] });
						}
						// 오른쪽
						if (cursorWorm[0] != m - 1 && baechuFarm[cursorWorm[0] + 1][cursorWorm[1]] == 1) {
							baechuFarm[cursorWorm[0] + 1][cursorWorm[1]] = 0;
							next.push({ cursorWorm[0] + 1, cursorWorm[1] });
						}
					}

					// 필요한 지렁이 수
					whiteWorm++;
				}
			}
		}

		cout << whiteWorm << '\n';
		whiteWorm = 0;

		for (int i = 0; i < m; i++) {
			delete[] baechuFarm[i];
		}
		delete[] baechuFarm;

	}



	return 0;
}