#include <iostream>
#include <vector>
using namespace std;

int main() {
	int count = 0, n, m;

	cin >> n >> m;

	vector<vector<int>> micro{ 0 };
	vector<vector<int>> loc{ 0 };

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> micro[i][j];
			if (micro[i][j] == 1) {
				vector<int> temp = { i, j };
				loc.emplace_back(temp);
			}
		}
	}


	//for (int i = 0; i < 8; i++) {
	//	// micro[][] = 1; // 주위 8칸에 1 확장
	//	count++;
	//}

	cout << 3;

	return 0;
}