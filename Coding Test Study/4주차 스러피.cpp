#include <iostream>
using namespace std;

string slurpys_inspection(string letters) {

	// 스럼프인지 검사, 아니면 넘어감. 맞으면 리턴

	// 스림프인지 검사, 아니면 NO 리턴. 맞으면 검사
	// 중간에 스럼프 검사를 위해 맨 마지막 글자를 제외한 string을
	// 다시 스스로를 호출해서 보냄
	// return slurpys_inspection(해당 문자열)

}



int main() {
	int repeat;
	char input[60];


	cin >> repeat;

	cout << "SLURPYS OUTPUT\n";

	// 입력 처리
	for (int i = 0; i < repeat; i++) {
		while (not cin.eof()) {
			cin >> input;
		}


		if (input[0] == 'D' or input[0] == 'E') {

		}

	}

	cout << "END OF OUTPUT";

	return 0;
}