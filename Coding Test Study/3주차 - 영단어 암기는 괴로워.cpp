#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 1. �Է�: �ּ� ���̺��� ª���� �Է� X -> map�� ���, value�� +1
// ( = �̹� �������� �󵵼� ������ �� ) -> �������� �ܼ�ȭ

// 2. ����: string�� �ܾ�, int�� �󵵼�
bool sorting_rule(pair<string, int> a, pair<string, int> b) {
	// 1. �� (���� if�� �������� �� ��ϴ�)
	if (a.second == b.second) {
		// 2. ����
		if (a.first.size() == b.first.size()) {
			// 3. ���� ��
			return a.first < b.first;
		}
		else {
			return a.first.size() > b.first.size();
		}
	}
	else {
		return a.second > b.second; // �󵵰� �� ���� �� �տ� ������
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int amount_of_words, length_standard;
	cin >> amount_of_words >> length_standard;

	string input;
	unordered_map<string, int> vocas;

	// vocas�� �ܾ ����. value�� ++ ���༭ �󵵰� value�� ī���õ�
	for (int i = 0; i < amount_of_words; i++) {
		cin >> input;
		// 1. ���� ����
		if (length_standard <= input.size()) {
			vocas[input]++;
		}
	}

	// ����
	vector<pair<string, int>> vocas_freq(vocas.begin(), vocas.end());
	sort(vocas_freq.begin(), vocas_freq.end(), sorting_rule);

	// ���
	for (auto& voca : vocas_freq) {
		cout << voca.first << '\n'; // ��� �ӵ��� ���� endl ��� '\n' ���
	}
}