// 2529번 부등호
#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>
using namespace std;

// 프로토타입 선언
// 가장 큰 수열을 반환
string find_biggest(int cursor, long used_num, int total, char* unequal, int prev_num, int pres_num);
// 가장 작은 수열을 반환
string find_smallest(int cursor, long used_num, int total, char* unequal, int prev_num, int pres_num);
bool is_exist_number(long used_num, int target); // 이미 있는 숫자인지 검사
bool is_valid_unequal(char unequal, int prev_num, int pres_num); // 부등호에 맞는지 검사.


// 메인 함수
int main() {
	int n;
	cin >> n;

	char* unequal = new char[n];

	for (int i = 0; i < n; i++) {
		cin >> unequal[i];
	}

	string biggest = find_biggest(0, 0, n, unequal, -1, -1);
	string smallest = find_smallest(0, 0, n, unequal, -1, -1);
	cout << biggest << '\n' << smallest << '\n';

	delete unequal;
	return 0;
}

bool is_exist_number(long used_num, int target) {
	return used_num & (1 << target);
}

bool is_valid_unequal(char unequal, int prev_num, int pres_num) { // 부등호 유효성 검사
	if (unequal == '<')
		return prev_num < pres_num;
	else
		return prev_num > pres_num;
}

string find_biggest(int cursor, long used_num, int total, char* unequal, int prev_num, int pres_num) { // 9 ~ 0 순으로 대입.
	bool validiation = false;
	
	// 유효성 검사
	if (cursor > 1) { // 길이가 2 이상일 때만 검사
		validiation = is_valid_unequal(unequal[cursor - 2], prev_num, pres_num);
		if (!validiation) return "-1";
	}
	
	// Base Case
	if (cursor > total) return "";

	// 9 ~ 0 까지 대입
	for (int i = 9; 0 <= i; i--) {
		if (is_exist_number(used_num, i)) continue;

		string tmp = find_biggest(cursor + 1, used_num | (1 << i), total, unequal, pres_num, i);

		if ((tmp.size() == total - cursor) && (tmp != "-1"))
			return to_string(i) + tmp;
	}

	return "";
}

string find_smallest(int cursor, long used_num, int total, char* unequal, int prev_num, int pres_num) { // 9 ~ 0 순으로 대입.
	bool validiation = false;

	// 유효성 검사
	if (cursor > 1) { // 길이가 2 이상일 때만 검사
		validiation = is_valid_unequal(unequal[cursor - 2], prev_num, pres_num);
		if (!validiation) return "-1";
	}

	// Base Case
	if (cursor > total) return "";

	// 9 ~ 0 까지 대입
	for (int i = 0; i <= 9; i++) {
		if (is_exist_number(used_num, i)) continue;

		string tmp = find_smallest(cursor + 1, used_num | (1 << i), total, unequal, pres_num, i);
		
		if ((tmp.size() == total - cursor) && (tmp != "-1"))
			return to_string(i) + tmp;
	}

	return "";
}