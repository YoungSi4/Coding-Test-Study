#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 백준 1026번 보물

// 둘 다 오름차순으로 정렬하고
// 하나는 순서대로, 다른 하나는 역순으로 접근해서 곱하여 처리한다.


int main() {
	// 지역 변수 선언
	vector<int> first_line, second_line;
	int length;

	// 변수 사용자 입력
	cin >> length;
	for (int i = 0; i < length; i++) {
		int input;
		cin >> input;
		first_line.emplace_back(input);
	}
	for (int i = 0; i < length; i++) {
		int input;
		cin >> input;
		second_line.emplace_back(input);
	}

	// 정렬
	sort(first_line.begin(), first_line.end());
	sort(second_line.begin(), second_line.end());

	// S 계산
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += first_line[i] * second_line[length - 1 - i];
	}

	cout << sum;
	
	return 0;
}