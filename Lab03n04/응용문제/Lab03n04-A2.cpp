#include <iostream>
using namespace std;

void print_DOB(int y = 1900, int m = 1, int d = 1);

int main()
{
	int y, m, d;
	print_DOB();
	cout << "year�Է�: ";
	cin >> y;
	cout << "month�Է�: ";
	cin >> m;
	cout << "day�Է�: ";
	cin >> d;
	print_DOB(y, m, d);
	return 0;
}

void print_DOB(int y, int m, int d)
{
	cout << "��������� " << y << "�� " << m << "�� " << d << "���Դϴ�." << endl;
}