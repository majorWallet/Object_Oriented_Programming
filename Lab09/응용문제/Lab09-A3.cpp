#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>
using namespace std;

bool chkDupli(const int* ar, const int arSize)
{
	for (int i = 0; i < arSize; i++)
		for (int j = 0; j < arSize; j++)
			if (ar[i] == ar[j] && i != j)
				return true;
	return false;
}

int main()
{
	srand(time(NULL));
	int n;
	int arSize;
	while(true)
	{
		cout << "Please enter a number: ";
		cin >> n;
		if (n < 2)
		{
			cout << "Wrong number!!!" << endl;
			break;
		}
		arSize = n / 2;
		cout << "Size of random array: " << arSize << endl;
		int* ar = new int[arSize];
		for (int i = 0; i < arSize; i++)
			ar[i] = rand() % n + 1;
		cout << "[ Array ]" << endl;
		for (int i = 0; i < arSize; i++)
			cout << setw(3) << ar[i];
		cout << endl;
		if (chkDupli(ar, arSize))
			cout << "Duplicates found." << endl;
		else
			cout << "Duplicates not found." << endl;
	}
	return 0;
}