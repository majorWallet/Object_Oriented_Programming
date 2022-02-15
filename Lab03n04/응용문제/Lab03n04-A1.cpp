#include <iostream>
using namespace std;

int get_data();
int sum(int a, int b);
int sub(int a, int b);
int mult(int a, int b);
float divi(int a, int b);
int addmul(int a, int b, int c);
float muldiv(int a, int b, int c);
int addmuladd(int a, int b, int c);
float subdivsub(int a, int b, int c);

int main()
{
	int x, y, z;
	x = get_data();
	y = get_data();
	z = get_data();
	cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
	cout << "(x + y) * z = " << addmul(x, y, z) << endl;
	cout << "(x * y) / z = " << muldiv(x, y, z) << endl;
	cout << "(x + y) * (y + z) = " << addmuladd(x, y, z) << endl;
	cout << "(x - y) / (y - z) = " << subdivsub(x, y, z) << endl;

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

int addmul(int a, int b, int c)
{
	return mult(sum(a, b), c);
}


float muldiv(int a, int b, int c)
{
	return divi(mult(a, b), c);
}

int addmuladd(int a, int b, int c)
{
	return mult(sum(a, b), sum(a, b));
}

float subdivsub(int a, int b, int c)
{
	return divi(sub(a, b), sub(b, c));
}