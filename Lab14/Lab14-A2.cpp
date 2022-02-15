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
			cout << "현재 list는 " << cnt << "의 크기를 가지고 있다." << endl;
			break;
		}
	}
	return 0;
}