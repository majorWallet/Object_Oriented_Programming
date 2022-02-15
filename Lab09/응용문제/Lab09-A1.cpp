#include <vector>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>
using namespace std;

void getMat(vector<vector<int>>& v)
{
	for (auto& row : v)
		for (auto& col : row)
			col = (rand() % 19) - 9;
}

void print(const vector<vector<int>>& v)
{
	for (const auto& row : v)
	{
		for (const auto& col : row)
			cout << setw(4) << col;
		cout << endl;
	}
}

vector<vector<int>> mulMat(vector<vector<int>>& v1, vector<vector<int>>& v2)
{
	vector<vector<int>> v(v1.size(), vector<int>(v2[0].size()));
	for (int k = 0; k < v1.size(); k++)
	{
		for (int l = 0; l < v2[0].size(); l++)
		{
			int mulMatElem = 0;
			for (int i = 0; i < v1[0].size(); i++)
			{
				mulMatElem += v1[k][i] * v2[i][l];
			}
			v[k][l] = mulMatElem;
		}
	}
	return v;
}

int main()
{
	srand(time(NULL));
	int rowA, colA;
	int rowB, colB;
	cout << "A�� ��, ���� ũ�⸦ �Է��� �ּ��� : ";
	cin >> rowA >> colA;
	vector<vector<int>> A (rowA, vector<int> (colA));
	cout << "B�� ��, ���� ũ�⸦ �Է��� �ּ��� : ";
	cin >> rowB >> colB;
	vector<vector<int>> B (rowB, vector<int> (colB));
	if (rowA < 1 || colA < 1 || rowB < 1 || colB < 1)
		cout << "����� ������ �� �����ϴ�." << endl;
	else
	{
		getMat(A);
		cout << "A ��� : " << endl;
		print(A);

		getMat(B);
		cout << "B ��� : " << endl;
		print(B);

		if (colA != rowB)
			cout << "�� ����� ���� �� �����ϴ�." << endl;
		else
		{
			vector<vector<int>> v;
			v = mulMat(A, B);
			cout << "AB �����: " << endl;
			print(v);
		}
	}
	return 0;
}