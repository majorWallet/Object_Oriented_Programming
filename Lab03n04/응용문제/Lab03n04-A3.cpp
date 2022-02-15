#include <cmath>
#include <iostream>
using namespace std;

int main() {
	double x, y;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	cout << "Rounding up number of " << x << ": " << ceil(x) << endl;
	cout << "Rounding down number of " << x << ": " << floor(x) << endl;
	cout << "Rounding number of " << x << ": " << round(x) << endl;
	cout << "Maximum number between " << x << " and " << y << ": " << fmax(x, y) << endl;
	cout << y << "-th root of" << x << ": " << pow(x, 1/y) << endl;
	cout << "|" << x << " - " << y << "|" << " = " << abs(x - y) << endl;
	return 0;
}