#include <iostream>
using namespace std;

//선언 (main함수 위에, prototyping)
int square(int a);

int main()
{
	int x;
	x = 5;
	cout << square(x) << endl;
	return 0;
}

//정의(main함수 아래에, 구현)
int square(int a)
{
	return a * a;
}