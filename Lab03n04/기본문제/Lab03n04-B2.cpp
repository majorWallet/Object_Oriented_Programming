#include <iostream>
using namespace std; 

int get_data();
int sum(int a, int b);
int sub(int a, int b);
int mult(int a, int b);
float divi(int a, int b);

int main()
{
	int x, y;
	x = get_data();
	y = get_data();
	cout << "x = " << x << ", y = " << y << endl;
	cout << "x + y = " << sum(x, y) << endl;
	cout << "x - y = " << sub(x, y) << endl;
	cout << "x * y = " << mult(x, y) << endl;
	cout << "x / y = " << divi(x, y) << endl;

	return 0;
}

int get_data()
{
	int a;
	cout << "Enter a number: ";
	cin >> a;
	return a;
}

int sum(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mult(int a, int b)
{
	return a * b;
}

float divi(int a, int b)
{
	return (float)a / b;
}