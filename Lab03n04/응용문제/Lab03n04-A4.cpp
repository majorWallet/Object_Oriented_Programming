#include <iostream>
using namespace std;

void getData(int& x, int& y)
{
	cout << "x입력: ";
	cin >> x;
	cout << "y입력: ";
	cin >> y;
}

void swap_call_by_value(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}

void swap_call_by_reference(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

int main()
{
	int x, y;
	getData(x, y);
	cout << "swap_call_by_value함수 사용 전: ";
	cout << "x = " << x << ", y = " << y << endl;
	swap_call_by_value(x, y);
	cout << "swap_call_by_value함수 사용 후: ";
	cout << "x = " << x << ", y = " << y << endl;

	cout << "swap_call_by_reference함수 사용 전: ";
	cout << "x = " << x << ", y = " << y << endl;
	swap_call_by_reference(x, y);
	cout << "swap_call_by_reference함수 사용 후: ";
	cout << "x = " << x << ", y = " << y << endl;

	return 0;
}