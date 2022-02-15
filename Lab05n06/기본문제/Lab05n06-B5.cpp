#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char key;
	cout << "Enter a keky (p or q): ";
	cin >> key;
	switch (key)
	{
	case 'p':
		cout << "Pause" << endl;
		break;
	case 'q':
		cout << "Quit" << endl;
		break;
	default:
		cout << "Default" << endl;
	}
	return 0;
}