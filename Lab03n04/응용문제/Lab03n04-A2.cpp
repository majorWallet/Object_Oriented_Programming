#include <iostream>
using namespace std;

void print_DOB(int y = 1900, int m = 1, int d = 1);

int main()
{
	int y, m, d;
	print_DOB();
	cout << "year입력: ";
	cin >> y;
	cout << "month입력: ";
	cin >> m;
	cout << "day입력: ";
	cin >> d;
	print_DOB(y, m, d);
	return 0;
}

void print_DOB(int y, int m, int d)
{
	cout << "생년월일은 " << y << "년 " << m << "월 " << d << "일입니다." << endl;
}