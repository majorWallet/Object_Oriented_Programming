#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int num = 1;
	int count = 1;
	cout.imbue(locale(""));
	while (count <= 20)
		cout << count++ << "\t" << (num *= 2) << endl;
	return 0;
}