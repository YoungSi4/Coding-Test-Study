#include<iostream>
#include<string>
#include<vector>
using namespace std;

/********************************************************************
*	���� �ð��뿡 ���� �̿��� m�� �������� ���� 1�� �߰� �ʿ�
*	m�� �̸��̶�� ������ �ʿ� ����
* 
* ��� �ð����� �̿��ڰ� n x m�� �̻� (n+1) x m�� �̸��̶��
* �ּ� n���� ���� ������ � ���̾�� �Ѵ�.
* 
* �� �� ������ ������ k �ð� ��ϰ� �� ���� �ݳ��Ѵ�
* k = 5�� �� 10�ÿ� ������ ������ 10 ~ 15 ���� ��ȴ�
* 
* ���� : �Ϸ� ���� ��� ���� �̿��ڰ� ������ �ϱ� ����
* ������ �ּ� �� �� �����ؾ� �ϴ°�?
* 
* �Է�
* 0 ~ 23�� �ð��뺰 ���� �̿��� �� 1���� ���� �迭 players
* ���� �� �� �ִ� �̿��� �� m, ���� ��ð� k
* ���
* �ּ� ���� ���� Ƚ���� return�ϵ��� solution �Լ� �����ϱ�
*********************************************************************/

int solution(vector<int> players, int m, int k) {
    // vector�� ���۷����� ����
    int answer = 0; // �������� �ջ�
    
    int currentServer[24]{}; // �ش� �ε��� �� ���� ����
    int whenServerOpen[24]{}; // ������ ���� ����

    /*
        1. player�� �޴´�
        2. player�� ���� üũ
            2-1. �÷��̾� �� / m = n : ���� ��
        3. n -> ���� ���� ����, ���� ���� ���� ���
        4. timeServerOpen�� �������� currentServer�ε��� k�� ����
            4-1. ����, out of range��� ����
        5. timeServerOpen���� �ջ��Ͽ� answer�� �Ҵ�
    */

    for (int i = 0; i < 24; i++) {
        int currentServerNeed = players[i] / m;
        if (currentServerNeed > currentServer[i]) {
            whenServerOpen[i] = currentServerNeed - currentServer[i];

            // ���� ���µ� ���� ��
            for (int t = i; t < i + k; t++) {
                if (t > 24) break; // index �� ����ó��
                currentServer[t] += whenServerOpen[i];
            }
        }

    }

    for (int i = 0; i < 24; i++) {
        answer += whenServerOpen[i];
    }

    return answer;
}

int main() {
    vector<int> players = { 0, 2, 3, 3, 1, 2, 0, 0, 0, 0, 4, 2, 0, 6, 0, 4, 2, 13, 3, 5, 10, 0, 1, 5 };

    int m, k; // ���� �ִ� �̿��ڼ�, ���� ���� �ð�

    cin >> m >> k;

    int result = solution(players, m, k);

    cout << result << endl;

	return 0;
}