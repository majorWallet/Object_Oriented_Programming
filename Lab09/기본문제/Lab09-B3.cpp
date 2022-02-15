#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

bool is_prime(int n)
{
	if (n <= 1)
		return false;

	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;
	return true;
}

vector<int> primes(int low, int high)
{
	vector<int> vec;
	for (int i = low; i <= high; i++)
		if (is_prime(i))
			vec.push_back(i);
	return vec;
}

void print(const vector<int>& v)
{
	for (const int& elem : v)
		cout << setw(4) << elem;
	cout << endl;
}

int main()
{
	int low, high;
	cin >> low >> high;
	vector<int> vec = primes(low, high);
	print(vec);
	return 0;
}