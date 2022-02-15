#include <iostream>
#include <vector>
using namespace std;
//정적 배열(static array):프로그램 실행중 크기가 고정되어 변경 불가
//동적 배열(dynamic array): 프로그램 실행중(run time) 할당/해제가 가능

int main() {
	const int size = 3;
	int list[size] = { 10, 20, 30 };
	int length = 3;
	cin >> length; // 키보드로부터 배열의 크기를 입력받음
	int* list2 = new int[length];
	// double* list2 = new double[length]
	int* begin = list2;
	int* end = list2 + length;
	for (int* curr = begin; curr != end; curr++)
		cin >> *curr;
	for (int* curr = begin; curr != end; curr++)
		cout << *curr << '\t';
	cout << endl;
	delete[] list2;
	return 0;
}