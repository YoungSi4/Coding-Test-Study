#include <iostream>
using namespace std;

int find_min_score(int* one_jump, int* two_jump, int n, int w);
int section_min_score(int* one_jump, int* two_jump, int start, int end);
//int use_w(int w, int n, int* min);

int main() {
	int n, w;
	int one_jump[20]{ 0 }, two_jump[20]{ 0 }; // 0�� �ε����� ��� ���ϹǷ� �ʱ�ȭ
	 
	// ����� �Է�
	// �迭�� 0�� �ε����� ������� �ʰ� 1 ~ 20�� ���
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> one_jump[i] >> two_jump[i];
	}

	cin >> w;

	int min = find_min_score(one_jump, two_jump, n, w); // �� ȣ����
	
	cout << min << '\n';

	return 0;
}



int section_min_score(int* one_jump, int* two_jump, int start, int end) {
	int min[20]{ 0 }; // 2 ~ 20�� ��ϵ�

	// ��尡 ���� ��� ó��
	if (end - start <= 0) return 0;

	// 2��ĭ�� ���� ó������� ��
	if (min[start + 1] == 0) {
		min[start + 1] = one_jump[start];
	}

	// top - down ������� ó��
	// �̹� 2��ĭ���� ������ ��������� 3��ĭ���� ���
	for (int node = start + 2; node <= end; node++) {
		int one_jump_value = min[node - 1] + one_jump[node - 1];
		int two_jump_value = min[node - 2] + two_jump[node - 2];

		if (one_jump_value > two_jump_value)
			min[node] = two_jump_value;
		else
			min[node] = one_jump_value;
	}
	
	return min[end];
}

int find_min_score(int* one_jump, int* two_jump, int n, int w) {
	int minimum = section_min_score(one_jump, two_jump, 1, n);

	for (int thresh = 1; thresh <= n - 3; thresh++) {
		int tmp = section_min_score(one_jump, two_jump, 1, thresh) + w + section_min_score(one_jump, two_jump, thresh + 3, n);

		if (minimum > tmp)
			minimum = tmp;
	}

	return minimum;
}