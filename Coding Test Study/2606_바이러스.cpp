#include<iostream>
#include<queue>
using namespace std;

int main() {
	int numCom, comPair;
	int start = 0; // 시작 위치 지정
	cin >> numCom >> comPair;

	/*************************************
	
	numCom : 컴퓨터 수 -  1 ~ n
	numPair : 컴퓨터 쌍 수
	
	필요한 것 : 컴퓨터 쌍을 저장할 배열?
	map 자료구조 필요할 것?
	 ㄴ 그냥 배열로 표현할까

	항상 1번 컴퓨터가 바이러스에 걸린다
	(인덱스 상에선 0으로 표현)

	***************************************/

	// 2차원 배열로 그래프 표현 // 0 : 연결없음, 1 : 이어짐
	int** node = new int* [numCom];
	for (int i = 0; i < numCom; i++) {
		node[i] = new int[numCom];

		for (int j = 0; j < numCom; j++) {
			node[i][j] = 0; // 초기화
		}
	}


	// 입력 받아 그래프 연결 표현
	int row, col;
	for (int i = 0; i < comPair; i++) {
		cin >> row >> col;
		
		row--; // 0번 인덱스에 1번 컴퓨터가 들어감
		col--;

		node[row][col] = 1; // 연결 있음
		node[col][row] = 1; // 양방향 연결이니까
	}

	

	// 감염 계산 - bfs dfs
	// 필요한 것
	// 감염 여부 : bool isInfected
	// 방문 기록 : bool isVisited -- 둘 중 하나만 있어도 되겠는데
	// 주변 노드 : queue<int> nextNode
	// stack - dfs, queue - bfs

	bool* isInfected = new bool[numCom];
	for (int i = 0; i < numCom; i++) {
		isInfected[i] = false;
	}

	queue<int> nextNode;

	// 시작 - 초기 1회
	int cur = start; // 시작 위치
	isInfected[cur] = true;
	for (int i = 0; i < numCom; i++) {
		if (node[cur][i] == 1) { // 두 노드가 이어졌다면
			if(!isInfected[i]) nextNode.push(i); // 감염되지 않았다면 방문
		}
	}
	// 반복
	while (!nextNode.empty()) { // 방문할 노드가 없어질 때까지
		cur = nextNode.front(); // 다음 노드로 이동
		nextNode.pop(); // 방문할 노드에서 제거
		isInfected[cur] = true; // 방문 기록 남기기

		// 노드 탐색
		for (int i = 0; i < numCom; i++) {
			if (node[cur][i] == 1) { // 두 노드가 이어졌는지?
				// 방문한 적이 없다면 방문할 노드에 추가
				if (!isInfected[i]) nextNode.push(i); 
			}
		}

		// 이미 방문한 노드가 앞에 있다면 제거

		// 다음 방문할 노드 큐가 있다면 && 해당 노드를 이미 방문했다면
		// 앞 조건이 false가 되는 순간 뒤의 조건은 확인하지 않으므로 오류를 던지지 않는다.
		// SCR?인가 아마 그럴거임 --> Short Circuit Evaluation 단락평가 라고 함
		while (!nextNode.empty() && isInfected[nextNode.front()]) nextNode.pop();
	}

	int count = 0;
	for (int i = 1; i < numCom; i++) { // 1번 컴퓨터는 무조건 감염
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