#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v; // int�� ���� ����
	vector<int> v(4); // ���� �� ũ�� 4�� �Ҵ� (���� �Ҵ�?)
	vector<int> v = { 1, 2, 3 };
	vector<int> v[] = {{1, 2}, {3, 4}}; // int�� ���� �迭 ����
	vector<vector<int>> v; // 2���� ���� ����
	
	vector<int> v = { 1, 2, 3, 4, 5 };
	v.assign(5, 10); // 10 10 10 10 10

	v.begin(); // ������ �ּҰ� ��ȯ
	v.end(); // �� + 1 �ּҰ� ��ȯ...?
	v.rbegin(); // �� ������ ���������� ��ȯ (r : reverse)
	v.rend(); // ���� + 1 ������ ���κ����� ��ȯ..?



}