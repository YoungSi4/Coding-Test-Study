#include <iostream>
using namespace std;

int main() {	
	// ���� ���� �� �ʱ�ȭ
	int count = 0, M, N;
	cin >> M >> N;

	// �� �� �ϳ��� 0�� �� ������ �ݺ�
	while (M * N > 0) {
		// X�� -1 �ϰ� ī��Ʈ +1
		M = M - 1;
		count = count + 1;
		// cout << "M ���� ����: " << count << endl;

		// ���� X�� 0�� �ƴٸ� ��� Ż��
		if (M <= 0) {
			break;
		}

		// Y�� -1�ϰ� ī��Ʈ +1
		N = N - 1;
		count = count + 1;
		// cout << "N ���� ����: " << count << endl;
	}

	// �������� ���� �ʰ� �ٷ� ���̹Ƿ� -1
	cout << count - 1;

	return 0;
}