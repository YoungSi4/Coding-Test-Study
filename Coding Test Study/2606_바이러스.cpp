#include<iostream>
#include<queue>
using namespace std;

int main() {
	int numCom, comPair;
	int start = 0; // ���� ��ġ ����
	cin >> numCom >> comPair;

	/*************************************
	
	numCom : ��ǻ�� �� -  1 ~ n
	numPair : ��ǻ�� �� ��
	
	�ʿ��� �� : ��ǻ�� ���� ������ �迭?
	map �ڷᱸ�� �ʿ��� ��?
	 �� �׳� �迭�� ǥ���ұ�

	�׻� 1�� ��ǻ�Ͱ� ���̷����� �ɸ���
	(�ε��� �󿡼� 0���� ǥ��)

	***************************************/

	// 2���� �迭�� �׷��� ǥ�� // 0 : �������, 1 : �̾���
	int** node = new int* [numCom];
	for (int i = 0; i < numCom; i++) {
		node[i] = new int[numCom];

		for (int j = 0; j < numCom; j++) {
			node[i][j] = 0; // �ʱ�ȭ
		}
	}


	// �Է� �޾� �׷��� ���� ǥ��
	int row, col;
	for (int i = 0; i < comPair; i++) {
		cin >> row >> col;
		
		row--; // 0�� �ε����� 1�� ��ǻ�Ͱ� ��
		col--;

		node[row][col] = 1; // ���� ����
		node[col][row] = 1; // ����� �����̴ϱ�
	}

	

	// ���� ��� - bfs dfs
	// �ʿ��� ��
	// ���� ���� : bool isInfected
	// �湮 ��� : bool isVisited -- �� �� �ϳ��� �־ �ǰڴµ�
	// �ֺ� ��� : queue<int> nextNode
	// stack - dfs, queue - bfs

	bool* isInfected = new bool[numCom];
	for (int i = 0; i < numCom; i++) {
		isInfected[i] = false;
	}

	queue<int> nextNode;

	// ���� - �ʱ� 1ȸ
	int cur = start; // ���� ��ġ
	isInfected[cur] = true;
	for (int i = 0; i < numCom; i++) {
		if (node[cur][i] == 1) { // �� ��尡 �̾����ٸ�
			if(!isInfected[i]) nextNode.push(i); // �������� �ʾҴٸ� �湮
		}
	}
	// �ݺ�
	while (!nextNode.empty()) { // �湮�� ��尡 ������ ������
		cur = nextNode.front(); // ���� ���� �̵�
		nextNode.pop(); // �湮�� ��忡�� ����
		isInfected[cur] = true; // �湮 ��� �����

		// ��� Ž��
		for (int i = 0; i < numCom; i++) {
			if (node[cur][i] == 1) { // �� ��尡 �̾�������?
				// �湮�� ���� ���ٸ� �湮�� ��忡 �߰�
				if (!isInfected[i]) nextNode.push(i); 
			}
		}

		// �̹� �湮�� ��尡 �տ� �ִٸ� ����

		// ���� �湮�� ��� ť�� �ִٸ� && �ش� ��带 �̹� �湮�ߴٸ�
		// �� ������ false�� �Ǵ� ���� ���� ������ Ȯ������ �����Ƿ� ������ ������ �ʴ´�.
		// SCR?�ΰ� �Ƹ� �׷����� --> Short Circuit Evaluation �ܶ��� ��� ��
		while (!nextNode.empty() && isInfected[nextNode.front()]) nextNode.pop();
	}

	int count = 0;
	for (int i = 1; i < numCom; i++) { // 1�� ��ǻ�ʹ� ������ ����
		if (isInfected[i]) count++;
	}

	cout << count << '\n';

	delete[] isInfected;
	for (int i = 0; i < numCom; i++) {
		delete[] node[i];
	}
	delete node;


	return 0;
}