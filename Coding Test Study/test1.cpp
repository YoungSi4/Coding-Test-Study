// ¿ïÅ¸¸®
#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;

	cin >> a >> b >> c >> d;

	int nums[4];
	nums[0] = a;
	nums[1] = b;
	nums[2] = c;
	nums[3] = d;


	int min = a;
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (nums[i] > nums[j]) {
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}
	
	cout << nums[0] * nums[2];

	return 0;
}