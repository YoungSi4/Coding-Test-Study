#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 로직
// 입력한 수열 C의 길이만큼 출력된다.
// Queue에 담겨있던 숫자가 뒷쪽 Queue부터 우선 출력되고
// 남은 길이만큼 수열 C의 값이 붙어서 나온다.

int main() {
	// 변수 선언 및 사용자 입력
	int DS_length, numbers_length;
	cin >> DS_length;

	vector<int> DS_type = {};
	list<int> print = {};
	// 벡터 DS_type에 입력 받기
	for (int i = 0; i < DS_length; i++) {
		int input;
		cin >> input;
		DS_type.emplace_back(input);
	}
	// 벡터 DS_value에 입력 받기
	for (int i = 0; i < DS_length; i++) {
		int input;
		cin >> input;
		if (DS_type[i] == 0)
			print.emplace_front(input);
	}

	// 인덱스 길이, 수열 C 입력 받기
	cin >> numbers_length;
	vector<int> numbers = {};
	for (int i = 0; i < numbers_length; i++) {
		int input;
		cin >> input;
		numbers.emplace_back(input);
	}

	// print 벡터의 capacity가 numbers_length가 될 때까지
	// print에 입력 받음.
	int i = 0;
	while (print.size() < numbers_length) {
		print.emplace_back(numbers[i]);
		i++;
	}

	for (int i = 0; i < numbers_length; i++) {
		cout << print.front() << " ";
		print.pop_front();
	}

	return 0;
}