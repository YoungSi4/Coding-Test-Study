#include<iostream>
#include<vector>
using namespace std;

int main() {
	// n : 참가자 수, s : 사이즈 수
	int n, s;
	cin >> n;

	// 티셔츠 사이즈 입력 받기
	vector<int> TshirtsSize;
	for (int i = 0; i < 6; i++) {
		cin >> s;
		TshirtsSize.push_back(s);
	}

	// 티셔츠 묶음 수, 펜 묶음 수
	int t, p;
	cin >> t >> p;

	int tshirtSet = 0;
	for (int i = 0; i < 6; i++) {
		if (TshirtsSize[i] % t != 0) {
			tshirtSet += (TshirtsSize[i] / t) + 1;
		}
		else {
			tshirtSet += TshirtsSize[i] / t;
		}
	}

	int penSet, pen;
	penSet = n / p;
	pen = n % p;

	// 출력
	cout << tshirtSet << '\n' << penSet << " " << pen << '\n';

	return 0;
}