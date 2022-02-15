#include <iostream>
using namespace std;

int main()
{
	int num, sum = 0, cnt = 0;
	cout << "number : ";
	cin >> num;
	while (cnt < num)
		(cnt + 1) % 2 != 0 && (cnt + 1) % 3 != 0 ? sum -= -(cnt -= -1) : cnt -= -1;
	cout << "sum : " << sum << endl;
	return 0;
}