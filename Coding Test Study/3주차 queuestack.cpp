#include <iostream>
#include <vector>
#include <list>
using namespace std;

// ����
// �Է��� ���� C�� ���̸�ŭ ��µȴ�.
// Queue�� ����ִ� ���ڰ� ���� Queue���� �켱 ��µǰ�
// ���� ���̸�ŭ ���� C�� ���� �پ ���´�.

int main() {
	// ���� ���� �� ����� �Է�
	int DS_length, numbers_length;
	cin >> DS_length;

	vector<int> DS_type = {};
	list<int> print = {};
	// ���� DS_type�� �Է� �ޱ�
	for (int i = 0; i < DS_length; i++) {
		int input;
		cin >> input;
		DS_type.emplace_back(input);
	}
	// ���� DS_value�� �Է� �ޱ�
	for (int i = 0; i < DS_length; i++) {
		int input;
		cin >> input;
		if (DS_type[i] == 0)
			print.emplace_front(input);
	}

	// �ε��� ����, ���� C �Է� �ޱ�
	cin >> numbers_length;
	vector<int> numbers = {};
	for (int i = 0; i < numbers_length; i++) {
		int input;
		cin >> input;
		numbers.emplace_back(input);
	}

	// print ������ capacity�� numbers_length�� �� ������
	// print�� �Է� ����.
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