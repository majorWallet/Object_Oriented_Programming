#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
using Matrix = vector<vector<int>>;

void print(const Matrix& v)
{
/*	for (const vector<int>& row : v)  //for (const auto& row : v)
	{
		for (const int& col : row)	//for (const auto& col : row)
			cout << setw(4) << col;
		cout << endl;
	}

	for (int row = 0; row < v.size(); row++)
	{
		for (int col = 0; col < v[col].size(); col++)
			cout << setw(4) << v[row][col];
		cout << endl;
	}*/

	for (const auto& row : v)	//교수님 이거 작동하는데요??
	{							//잠결에 수업을 잘못 들었나??
		for (const auto& col : row)
			cout << setw(4) << col;
		cout << endl;
	}
}

int main()
{
	Matrix mat{ {1, 2, 3},
				{4, 5, 6} };
	mat[0][0] = 1;
	mat[0][1] = 2;
	mat[0][2] = 3;
	mat[1][0] = 4;
	mat[1][1] = 5;
	mat[1][2] = 6;
	print(mat);
	return 0;
}