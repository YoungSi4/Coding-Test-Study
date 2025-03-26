#include<iostream>
#include<string>
#include<stack>
using namespace std;

/************
1. 받을 스트링 개수를 받기
2. while(cin >> )으로 스트링 입력 받기 (이건 for로 감싸고)
3. stack에 받아야해!!!
4. 꺼내면서 검사
  4-1. ' ) ' 가 부족한 경우
  4-2. ' ) ' 가 많은 경우
  4-3. 딱 맞는 경우
5. 결과 출력
6. 반복.
*************/

int main() {
	stack<char> parenthesisStack; // push top pop
	bool isVPS;

	// 입력 받기
	int n;
	cin >> n;
	cin.ignore();

	// 입력 받기
	for (int i = 0; i < n; i++) {
		string parenthesisString;
		if (!getline(cin, parenthesisString)) break;
		isVPS = true; // 초기화

		// 검사 루프
		for (int j = 0; j < parenthesisString.length(); j++) {
			if (parenthesisString[j] == '(') {
				parenthesisStack.push('(');
			}
			// 많은 경우 거르기
			else if (parenthesisString[j] == ')') {
				if (parenthesisStack.empty()) {
					isVPS = false;
					break;
				}
				else { // 어차피 ( 만 들어가기 때문
					parenthesisStack.pop();
				}
			}
		}

		if (!parenthesisStack.empty() && isVPS) {
			// 스택 안에 남은 경우
			isVPS = false;
		}

		// 결과 출력
		if (isVPS) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

		// 스택, 문자열 초기화
		while (!parenthesisStack.empty()) parenthesisStack.pop();
		parenthesisString = "";
	}

	return 0;
}