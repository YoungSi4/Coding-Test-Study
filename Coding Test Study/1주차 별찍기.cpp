#include <iostream>
using namespace std;

int pyramid(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n - 1; j++) {
			cout << ' ';
		}
		for (int k = 2*(n - i - 1); k < 2 * n - 1; k++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}
int reverse_pyramid(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << ' ';
		}
		for (int k = 2 * i; k < 2*(n-1)-1; k++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}

int main() {
	int n;
	cin >> n;

	pyramid(n);
	reverse_pyramid(n);
}