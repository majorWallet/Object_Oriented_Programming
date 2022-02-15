#include <iostream>
using namespace std;

int main() {
	int sum = 0, n;
	cout << "number : ";
	cin >> n;
	for (int i = 0; i < n;)
		sum += ++i;
	cout << "Sum of 1 to " << n << " = " << sum << endl;
	return 0;
}