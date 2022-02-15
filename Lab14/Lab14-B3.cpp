#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> v1 = { 1, 2, 3, 4 };
	for (int& elem : v1) {
		cout << elem << '\t';
	}
	cout << endl;

	for_each(begin(v1), end(v1), [v1](int elem) { cout << elem << '\t'; });
	cout << endl;

	for_each(begin(v1), end(v1), [&v1](int& elem) { elem++; });
	for_each(begin(v1), end(v1), [v1](int elem) { cout << elem << '\t'; });
	cout << endl;

	int a = 10;
	for_each(begin(v1), end(v1), [&v1, a](int& elem) { elem += a; });
	for_each(begin(v1), end(v1), [v1](int elem) { cout << elem << '\t'; });
	cout << endl;

	vector<int> v2(v1.size());
	copy(begin(v1) + 1, end(v1) - 1, begin(v2) + 2);
	for_each(begin(v2), end(v2), [v2](int elem) { cout << elem << '\t'; });
	cout << endl;

	transform(begin(v1), end(v1), begin(v2), [&v1](int& elem) {return elem * elem; });
	for_each(begin(v2), end(v2), [v2](int elem) { cout << elem << '\t'; });
	cout << endl;

	return 0;
}