#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void print(int* begin, int* end)
{
	int* curr = begin;

	for (curr = begin; curr != end; curr++)
		cout << setw(4) << *curr;

	//	while (curr != end)
	//	{
	//		cout << setw(4) << *curr;
	//		curr++; // 0x00->0x01
	//	}
	cout << endl;
}

int main()
{
	int list[3] = { 10, 20 ,30 };

	cout << list << '\t' << *list << endl;
	cout << (list + 1) << '\t' << *(list + 1) << endl;
	cout << (list + 2) << '\t' << *(list + 2) << endl;

	int* begin = list;
	int* end = list + 3;
	print(begin, end);

	return 0;
}