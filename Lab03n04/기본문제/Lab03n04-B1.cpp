#include <iostream>
using namespace std;

//���� (main�Լ� ����, prototyping)
int square(int a);

int main()
{
	int x;
	x = 5;
	cout << square(x) << endl;
	return 0;
}

//����(main�Լ� �Ʒ���, ����)
int square(int a)
{
	return a * a;
}