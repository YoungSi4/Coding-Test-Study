#include<iostream>
#include<string>
#include<vector>
using namespace std;

/********************************************************************
*	같은 시간대에 게임 이용자 m명 증가마다 서버 1대 추가 필요
*	m명 미만이라면 증설이 필요 없음
* 
* 어느 시간대의 이용자가 n x m명 이상 (n+1) x m명 미만이라면
* 최소 n대의 증설 서버가 운영 중이어야 한다.
* 
* 한 번 증설한 서버는 k 시간 운영하고 그 이후 반납한다
* k = 5일 때 10시에 증설한 서버는 10 ~ 15 까지 운영된다
* 
* 문제 : 하루 동안 모든 게임 이용자가 게임을 하기 위해
* 서버를 최소 몇 번 증설해야 하는가?
* 
* 입력
* 0 ~ 23시 시간대별 게임 이용자 수 1차원 정수 배열 players
* 서버 한 대 최대 이용자 수 m, 서버 운영시간 k
* 출력
* 최소 서버 증설 횟수를 return하도록 solution 함수 조정하기
*********************************************************************/

int solution(vector<int> players, int m, int k) {
    // vector는 레퍼런스로 전달
    int answer = 0; // 마지막에 합산
    
    int currentServer[24]{}; // 해당 인덱스 때 열린 서버
    int whenServerOpen[24]{}; // 서버가 열린 시점

    /*
        1. player를 받는다
        2. player의 수를 체크
            2-1. 플레이어 수 / m = n : 서버 수
        3. n -> 서버 열린 시점, 현재 열린 서버 기록
        4. timeServerOpen을 기준으로 currentServer인덱스 k개 수정
            4-1. 만약, out of range라면 예외
        5. timeServerOpen에서 합산하여 answer에 할당
    */

    for (int i = 0; i < 24; i++) {
        int currentServerNeed = players[i] / m;
        if (currentServerNeed > currentServer[i]) {
            whenServerOpen[i] = currentServerNeed - currentServer[i];

            // 현재 오픈된 서버 수
            for (int t = i; t < i + k; t++) {
                if (t > 24) break; // index 밖 예외처리
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

    int m, k; // 서버 최대 이용자수, 서버 증설 시간

    cin >> m >> k;

    int result = solution(players, m, k);

    cout << result << endl;

	return 0;
}