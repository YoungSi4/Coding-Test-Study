#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	// ������ ��ǥ ����
	int n;
	cin >> n;

	vector<pair<int, int>> grid(n);



	// ��ǥ �Է� �ޱ�
	for (int i = 0; i < n; i++) {
		cin >> grid[i].first >> grid[i].second;
	}
	
	// �����ϱ�
	sort(grid.begin(), grid.end());

	// ����ϱ�
	for (int i = 0; i < n; i++) {
		cout << grid[i].first << " " << grid[i].second << '\n';
	}

	return 0;
}