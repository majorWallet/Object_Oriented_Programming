#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int column = 1, row = 1;
	while (column <= 10)
	{
		while (row <= 10)
		{
			cout << setw(4) << (column == row ? 1 : 0);
			row++;
		}
		cout << endl;
		row = 1;
		column++;
	}
	return 0;
}