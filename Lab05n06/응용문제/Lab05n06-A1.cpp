#include <iostream>
using namespace std;

int main()
{
	int cnt = 0, num;
	while (cnt < 5)
	{
		cout << ++cnt << "��° ���� : ";
		cin >> num;
		num % 2 == 0 ? (cout << num << "��(��) ¦���Դϴ�." << endl) : (cout << num << "��(��) Ȧ�� �Դϴ�." << endl);
	}
	return 0;
}