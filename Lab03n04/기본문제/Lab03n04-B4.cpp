#include <iostream>
using namespace std;

void applePrice(int n = 1000); // default argument는 선언부분에만 명시해야한다.

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