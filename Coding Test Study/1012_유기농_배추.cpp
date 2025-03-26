#include<iostream>
#include<queue>
using namespace std;

int main() {
	// 테스트 케이스 t, 가로 m, 세로 n, 배추 수 k
	int t, m, n, k, x, y, whiteWorm = 0;
	cin >> t;

	for (; t--;) {
		cin >> m >> n >> k;
		whiteWorm = 0;
		queue<pair<int, int>> next;
		// array<int, 2> loc; // 이게 ref라서 값 참조가 일어남...
		pair<int, int> loc;

		// 배추밭 생성
		int** baechuFarm = new int* [n];
		for (int i = 0; i < n; i++) {
			baechuFarm[i] = new int[m](); // 초기화
		}

		// 배추 심기
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			baechuFarm[y][x] = 1; 
		}

		// cursor ( i, j ), bfs( loc[0], loc[1] )
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (baechuFarm[i][j] == 1) {
					// bfs
					baechuFarm[i][j] = 0;
					loc.first = j; loc.second =i;
					next.push(loc);

					while (!next.empty()) {
						loc.first = next.front().first;
						loc.second = next.front().second;
						next.pop();

						// 왼
						if (loc.first != 0 && baechuFarm[loc.second][loc.first - 1] == 1) {
							next.push({ loc.first - 1, loc.second });
							baechuFarm[loc.second][loc.first - 1] = 0;
						}
						// 오
						if (loc.first != m - 1 && baechuFarm[loc.second][loc.first + 1] == 1) {
							next.push({loc.first + 1, loc.second});
							baechuFarm[loc.second][loc.first + 1] = 0;
						}
						// 아래
						if (loc.second != n - 1 && baechuFarm[loc.second + 1][loc.first] == 1) {
							next.push({loc.first, loc.second + 1});
							baechuFarm[loc.second + 1][loc.first] = 0;
						}
						// 위
						if (loc.second != 0 && baechuFarm[loc.second - 1][loc.first]) {
							next.push({ loc.first, loc.second - 1 });
							baechuFarm[loc.second - 1][loc.first] = 0;
						}
					}

					whiteWorm++;
				}
			}
		}
		cout << whiteWorm << '\n';

		for (int i = 0; i < n; i++){
			delete[] baechuFarm[i];
		}
		delete[] baechuFarm;

	}

	return 0;
}