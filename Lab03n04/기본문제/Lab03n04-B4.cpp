#include <iostream>
using namespace std;

void applePrice(int n = 1000); // default argument�� ����κп��� ����ؾ��Ѵ�.

int main()
{
	applePrice(1500);
	applePrice(500);
	applePrice(1000);
	applePrice();
	return 0;
}

void applePrice(int n)
{
	cout << "Apple price = " << n << endl;
}