#include <iostream>
#include <cstdlib>
using namespace std;

// 2차원 리스트로 푸는 게 더 편할 듯
int main() {
	// 변수 입력
	int num1, num2;
	cin >> num1 >> num2;
	
	// num1 num2 순서대로 정렬
	if (num1 > num2) {
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}

	// 변수 선언: 동서거리 남북거리, 4로 나눈 몫
	int NS_distance, EW_distance, num1_share = num1 / 4, num2_share = num2 / 4;
	
	// 4의 배수일 경우 몫에서 -1 해줌
	if (num1 % 4 == 0) {
		num1_share -= 1;
	}
	if (num2 % 4 == 0) {
		num2_share -= 1;
	}

	// 동서거리 계산
	EW_distance = num2_share - num1_share;
	// cout << "EW" << EW_distance << endl;

	// 나머지 선언
	int num1_left = num1 % 4, num2_left = num2 % 4;

	// 4의 배수일 경우 4로 설정해줌
	if (num1_left == 0) {
		num1_left = 4;
	}
	if(num2_left == 0){
		num2_left = 4;
	}

	// 남북거리 계산. 절대값 이용해줌. 이를 위해 cstdlib 불러왔음
	NS_distance = abs(num1_left - num2_left);
	// cout << "NS" << NS_distance << endl << endl;

	cout << NS_distance + EW_distance;
	
	return 0;
}