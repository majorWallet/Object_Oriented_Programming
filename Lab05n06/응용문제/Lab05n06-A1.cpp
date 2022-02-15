#include <iostream>
using namespace std;

int main()
{
	int cnt = 0, num;
	while (cnt < 5)
	{
		cout << ++cnt << "번째 정수 : ";
		cin >> num;
		num % 2 == 0 ? (cout << num << "은(는) 짝수입니다." << endl) : (cout << num << "은(는) 홀수 입니다." << endl);
	}
	return 0;
}