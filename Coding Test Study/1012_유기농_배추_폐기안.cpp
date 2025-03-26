#include<iostream>
#include<queue>
#include<array>
using namespace std;

int main() {
	/*
		��� 1 ) visited
		��� 2 ) 0 ���� �ٲٱ�
	*/

	// t: �׽�Ʈ ���̽� ��
	// m: ���� , n : ����
	// k : ���� ��
	int t, m, n, k;
	cin >> t;
	
	// test case �� ��ŭ
	for (; t--;) {
		cin >> m >> n >> k;

		int whiteWorm = 0;
		int cursorWorm[2] = { 0, 0 }; // cursor ��ġ

		queue<array<int, 2>> next;

		// ���߹� �����
		int** baechuFarm = new int* [n];
		for (int i = 0; i < n; i++) {
			baechuFarm[i] = new int[m];
		}

		// �ʱ�ȭ
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				baechuFarm[i][j] = 0;
			}
		}

		// ���� �ɱ�
		for (int i = 0; i < k; i++) {
			int p, q; // x y
			cin >> p >> q;

			baechuFarm[q][p] = 1;
		}

		// �˻�
		// queue.front() == cursor ���� Ȯ�� �� pop �ʿ�
		// cursorWorm[2], cursorCount[2]

		// i, j �� Ŀ�� ��ġ
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {

				// ���߰� �ɾ��� �ִٸ�

				if (baechuFarm[i][j] == 1) {
					// �����¿� Ȯ��
					// ��: Ȯ�� ���ʿ�
					// ��: (i, j+1), ��(i-1, j), ��(i+1, j)
					// out of range�� ���
					// ��: j != n, �� i != 0, �� i != m

					// ���� 1ȸ ���� (queue ä��� ����)
					// cursor ��ġ ����
					cursorWorm[0] = i, cursorWorm[1] = j;

					// �ֺ� �˻� - �̹� �� �ڸ��� 1 �ΰ� Ȯ���ϰ� �������Ƿ� �� �ص� ��
					// �Ʒ�
					if (j != n - 1 && baechuFarm[i][j + 1] == 1) {
						next.push({ i, j + 1 });
					}
					// ����
					if (i != 0 && baechuFarm[i - 1][j] == 1) {
						next.push({ i - 1, j });
					}
					// ������
					if (i != m - 1 && baechuFarm[i + 1][j] == 1) {
						next.push({ i + 1, j });
					}

					baechuFarm[i][j] = 0; // üũ

					// �ݺ�  - �ֺ��� ������ �׳� �ٷ� �Ʒ���
					while (!next.empty()) {
						// Ŀ�� �̵�
						cursorWorm[0] = next.front()[0];
						cursorWorm[1] = next.front()[1];
						next.pop();
						// �̵� �� üũ
						baechuFarm[cursorWorm[0]][cursorWorm[1]] = 0;

						if (next.empty()) {}
						else if (cursorWorm[0] == next.front()[0] && cursorWorm[1] == next.front()[1]) {
							// �̵��� ��ġ�� ���� �̵��� ��ġ�� �����ϴٸ�
							next.pop(); // ����
						}
						
						// �Ʒ�
						if (cursorWorm[1] != n - 1 && baechuFarm[cursorWorm[0]][cursorWorm[1] + 1] == 1) {
							baechuFarm[cursorWorm[0]][cursorWorm[1] + 1] = 0;
							next.push({ cursorWorm[0], cursorWorm[1] + 1});
						}
						// ����
						if (cursorWorm[0] != 0 && baechuFarm[cursorWorm[0] - 1][cursorWorm[1]] == 1) {
							baechuFarm[cursorWorm[0] - 1][cursorWorm[1]] = 0;
							next.push({ cursorWorm[0] - 1, cursorWorm[1] });
						}
						// ������
						if (cursorWorm[0] != m - 1 && baechuFarm[cursorWorm[0] + 1][cursorWorm[1]] == 1) {
							baechuFarm[cursorWorm[0] + 1][cursorWorm[1]] = 0;
							next.push({ cursorWorm[0] + 1, cursorWorm[1] });
						}
					}

					// �ʿ��� ������ ��
					whiteWorm++;
				}
			}
		}

		cout << whiteWorm << '\n';
		whiteWorm = 0;

		for (int i = 0; i < m; i++) {
			delete[] baechuFarm[i];
		}
		delete[] baechuFarm;

	}



	return 0;
}