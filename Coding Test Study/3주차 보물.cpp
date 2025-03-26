#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���� 1026�� ����

// �� �� ������������ �����ϰ�
// �ϳ��� �������, �ٸ� �ϳ��� �������� �����ؼ� ���Ͽ� ó���Ѵ�.


int main() {
	// ���� ���� ����
	vector<int> first_line, second_line;
	int length;

	// ���� ����� �Է�
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

	// ����
	sort(first_line.begin(), first_line.end());
	sort(second_line.begin(), second_line.end());

	// S ���
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += first_line[i] * second_line[length - 1 - i];
	}

	cout << sum;
	
	return 0;
}