#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v; // int형 벡터 생성
	vector<int> v(4); // 생성 후 크기 4로 할당 (정적 할당?)
	vector<int> v = { 1, 2, 3 };
	vector<int> v[] = {{1, 2}, {3, 4}}; // int형 벡터 배열 생성
	vector<vector<int>> v; // 2차원 벡터 생성
	
	vector<int> v = { 1, 2, 3, 4, 5 };
	v.assign(5, 10); // 10 10 10 10 10

	v.begin(); // 시작점 주소값 반환
	v.end(); // 끝 + 1 주소값 반환...?
	v.rbegin(); // 끝 지점을 시작점으로 반환 (r : reverse)
	v.rend(); // 시작 + 1 지점을 끝부분으로 반환..?



}