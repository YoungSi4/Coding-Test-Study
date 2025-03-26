#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	/*
		n명이 있고 Pi가 있다
		
		P : 3 1 4 3 2
		순서 1 2 3 4 5 -> SUM( 3*5 + 1*4 + 4*3 + 4*2 + 2*1 )

		즉 앞에 있을수록 자주 계산됨 -> 오름차순 정렬 필요
		그 후 계산
	*/

	int n; // 사람 수

	int timeSumMin = 0; // 시간 합계

	// input
	cin >> n;
	int* time = new int[n];
	// Pi : i번이 돈을 인출하는데 걸리는 시간
	
	for (int i = 0; i < n; i++) {
		cin >> time[i];
	}

	// 오름차순으로 정렬
	sort(time, time+n); // start() -> end()
	for (int i = 0; i < n; i++) {
		timeSumMin += time[i] * (n - i);
	}

	// 결과 출력
	cout << timeSumMin << '\n';

	// 메모리 회수
	delete[] time;

	return 0;
}