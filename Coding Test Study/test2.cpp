// 간수 찾기

#include <iostream>
#include <string>
#include <list>
#include <sstream>
using namespace std;

int main() {
	int a, sum = 0, num;
	list<int> nums = {};
	
	string line, temp_num = "";

	cin >> a >> line;

	for (int i = 0; i < a; i++) {
		char ins = line[i];
		
		if (48 <= ins && ins <= 57) {
			temp_num += line[i];
		}
		else {
			if (temp_num.length() != 0) {
				stringstream stream;
				stream.str(temp_num);
				while (stream >> num) {
					sum += num;
				}
				temp_num = "";
			}
		}

	}

	if (temp_num.length() != 0) {
		stringstream stream;
		stream.str(temp_num);
		while (stream >> num) {
			sum += num;
		}
		temp_num = "";
	}
		

	cout << sum;

	return 0;
}