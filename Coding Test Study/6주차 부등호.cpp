// 2529�� �ε�ȣ
#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>
using namespace std;

// ������Ÿ�� ����
// ���� ū ������ ��ȯ
string find_biggest(int cursor, long used_num, int total, char* unequal, int prev_num, int pres_num);
// ���� ���� ������ ��ȯ
string find_smallest(int cursor, long used_num, int total, char* unequal, int prev_num, int pres_num);
bool is_exist_number(long used_num, int target); // �̹� �ִ� �������� �˻�
bool is_valid_unequal(char unequal, int prev_num, int pres_num); // �ε�ȣ�� �´��� �˻�.


// ���� �Լ�
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

bool is_valid_unequal(char unequal, int prev_num, int pres_num) { // �ε�ȣ ��ȿ�� �˻�
	if (unequal == '<')
		return prev_num < pres_num;
	else
		return prev_num > pres_num;
}

string find_biggest(int cursor, long used_num, int total, char* unequal, int prev_num, int pres_num) { // 9 ~ 0 ������ ����.
	bool validiation = false;
	
	// ��ȿ�� �˻�
	if (cursor > 1) { // ���̰� 2 �̻��� ���� �˻�
		validiation = is_valid_unequal(unequal[cursor - 2], prev_num, pres_num);
		if (!validiation) return "-1";
	}
	
	// Base Case
	if (cursor > total) return "";

	// 9 ~ 0 ���� ����
	for (int i = 9; 0 <= i; i--) {
		if (is_exist_number(used_num, i)) continue;

		string tmp = find_biggest(cursor + 1, used_num | (1 << i), total, unequal, pres_num, i);

		if ((tmp.size() == total - cursor) && (tmp != "-1"))
			return to_string(i) + tmp;
	}

	return "";
}

string find_smallest(int cursor, long used_num, int total, char* unequal, int prev_num, int pres_num) { // 9 ~ 0 ������ ����.
	bool validiation = false;

	// ��ȿ�� �˻�
	if (cursor > 1) { // ���̰� 2 �̻��� ���� �˻�
		validiation = is_valid_unequal(unequal[cursor - 2], prev_num, pres_num);
		if (!validiation) return "-1";
	}

	// Base Case
	if (cursor > total) return "";

	// 9 ~ 0 ���� ����
	for (int i = 0; i <= 9; i++) {
		if (is_exist_number(used_num, i)) continue;

		string tmp = find_smallest(cursor + 1, used_num | (1 << i), total, unequal, pres_num, i);
		
		if ((tmp.size() == total - cursor) && (tmp != "-1"))
			return to_string(i) + tmp;
	}

	return "";
}