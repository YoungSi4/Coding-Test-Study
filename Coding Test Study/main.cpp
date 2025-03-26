#include <iostream>
#include <cstdlib>
using namespace std;

// 2���� ����Ʈ�� Ǫ�� �� �� ���� ��
int main() {
	// ���� �Է�
	int num1, num2;
	cin >> num1 >> num2;
	
	// num1 num2 ������� ����
	if (num1 > num2) {
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}

	// ���� ����: �����Ÿ� ���ϰŸ�, 4�� ���� ��
	int NS_distance, EW_distance, num1_share = num1 / 4, num2_share = num2 / 4;
	
	// 4�� ����� ��� �򿡼� -1 ����
	if (num1 % 4 == 0) {
		num1_share -= 1;
	}
	if (num2 % 4 == 0) {
		num2_share -= 1;
	}

	// �����Ÿ� ���
	EW_distance = num2_share - num1_share;
	// cout << "EW" << EW_distance << endl;

	// ������ ����
	int num1_left = num1 % 4, num2_left = num2 % 4;

	// 4�� ����� ��� 4�� ��������
	if (num1_left == 0) {
		num1_left = 4;
	}
	if(num2_left == 0){
		num2_left = 4;
	}

	// ���ϰŸ� ���. ���밪 �̿�����. �̸� ���� cstdlib �ҷ�����
	NS_distance = abs(num1_left - num2_left);
	// cout << "NS" << NS_distance << endl << endl;

	cout << NS_distance + EW_distance;
	
	return 0;
}