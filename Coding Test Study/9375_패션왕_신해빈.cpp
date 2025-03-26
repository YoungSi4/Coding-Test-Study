#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	/*
		t : 테스트 케이스
		n : 의상 수
		str1, str2 : 의상 이름, 의상 종류
	*/

	// 조합
	// 각 파츠에서 옷 가지수 n+1C1 x n+1C1 x ... x n+1Cr - 1 (아무것도 안 입은 경우)
	// 
	//
	
	int t; // 테스트 케이스
	cin >> t;

	for (; t--;) {
		int n; // 의상 수
		cin >> n;

		map<string, int> closet;

		// 받기
		for (int i = 0; i < n; i++) {
			string clothName, clothPart;
			cin >> clothName >> clothPart;

			closet[clothPart]++;
		}

		// 입을 옷 조합
		int combination = 1;
		for (const auto &pair : closet) {
			combination *= (pair.second + 1);
		}

		combination--;

		cout << combination << '\n';
	}



	return 0;
}