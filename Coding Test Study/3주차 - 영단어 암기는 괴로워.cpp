#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 1. 입력: 최소 길이보다 짧으면 입력 X -> map에 등록, value를 +1
// ( = 이미 논리적으로 빈도수 정렬이 됨 ) -> 데이터의 단순화

// 2. 정렬: string은 단어, int는 빈도수
bool sorting_rule(pair<string, int> a, pair<string, int> b) {
	// 1. 빈도 (이중 if라 마음에는 안 듭니다)
	if (a.second == b.second) {
		// 2. 길이
		if (a.first.size() == b.first.size()) {
			// 3. 사전 순
			return a.first < b.first;
		}
		else {
			return a.first.size() > b.first.size();
		}
	}
	else {
		return a.second > b.second; // 빈도가 더 많은 게 앞에 오도록
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int amount_of_words, length_standard;
	cin >> amount_of_words >> length_standard;

	string input;
	unordered_map<string, int> vocas;

	// vocas에 단어를 저장. value를 ++ 해줘서 빈도가 value에 카운팅됨
	for (int i = 0; i < amount_of_words; i++) {
		cin >> input;
		// 1. 길이 조건
		if (length_standard <= input.size()) {
			vocas[input]++;
		}
	}

	// 정렬
	vector<pair<string, int>> vocas_freq(vocas.begin(), vocas.end());
	sort(vocas_freq.begin(), vocas_freq.end(), sorting_rule);

	// 출력
	for (auto& voca : vocas_freq) {
		cout << voca.first << '\n'; // 출력 속도를 위해 endl 대신 '\n' 사용
	}
}