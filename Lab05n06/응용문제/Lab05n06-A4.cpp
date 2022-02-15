#include <iostream>
using namespace std;

int main()
{
	int dan = 0, cnt = 0;
	while (dan != -1)
	{
		cout << "단 수를 입력하세요: ";
		cin >> dan;
		if (dan == -1)
			break;
		if (dan >= 1 && dan <= 9)
			while (cnt < 9)
				cout << dan << "*" << ++cnt << " = " << dan * cnt << endl;
		else
			cout << "1부터 9까지의 정수를 입력해주세요.";
		cnt = 0;
		cout << endl;
	}
	cout << "종료합니다." << endl;
	return 0;
}