#include<iostream>
using namespace std;


int main() {
	int n, k, coinNum = 0; // n: 동전 종류,  k : 동전 가치의 합
	cin >> n >> k;

	int* coinValue = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> coinValue[i]; // 오름차순
	}

	/*
		Ex ) k : 4200
		coinValue < k 인 가장 작은 coinValue 값 확인
		/ 연산 : 개수 확인
		% 연산 : 남은 값 확인

		위의 과정을 반복
		단. 값이 딱 맞아 떨어져야 한다
	*/

	for (int i = n - 1; 0 <= i; i--) {
		if (coinValue[i] <= k) {
			coinNum += k / coinValue[i];
			k = k % coinValue[i];
		}
	}
	
	cout << coinNum;

	return 0;
}