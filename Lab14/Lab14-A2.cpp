#include <iostream>
#include <vector>
#include <ctime>
#include <random>
using namespace std;

int main() {
	srand(time(NULL));
	vector<int> list(rand()%100+1);
	int cnt = -1;
	while (1) {
		cnt++;
		try {
			list.at(cnt);
		}
		catch (exception& e) {
			cout << "���� list�� " << cnt << "�� ũ�⸦ ������ �ִ�." << endl;
			break;
		}
	}
	return 0;
}