#include <iostream>
using namespace std;

int gcd(int val1, int val2)
{
	return val1 % val2 == 0 ? val2 : gcd(val2, val1 % val2);
}

int main()
{
	int x, y;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << "gcd(" << x << ", " << y << ")" << " = " << gcd(x, y) << endl;
	return 0;
}