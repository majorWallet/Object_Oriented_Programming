#include <iostream>
using namespace std;

int main()
{
	int dan = 0, cnt = 0;
	while (dan != -1)
	{
		cout << "�� ���� �Է��ϼ���: ";
		cin >> dan;
		if (dan == -1)
			break;
		if (dan >= 1 && dan <= 9)
			while (cnt < 9)
				cout << dan << "*" << ++cnt << " = " << dan * cnt << endl;
		else
			cout << "1���� 9������ ������ �Է����ּ���.";
		cnt = 0;
		cout << endl;
	}
	cout << "�����մϴ�." << endl;
	return 0;
}