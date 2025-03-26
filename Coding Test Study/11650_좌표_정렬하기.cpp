#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	// 정렬할 좌표 갯수
	int n;
	cin >> n;

	vector<pair<int, int>> grid(n);



	// 좌표 입력 받기
	for (int i = 0; i < n; i++) {
		cin >> grid[i].first >> grid[i].second;
	}
	
	// 정렬하기
	sort(grid.begin(), grid.end());

	// 출력하기
	for (int i = 0; i < n; i++) {
		cout << grid[i].first << " " << grid[i].second << '\n';
	}

	return 0;
}