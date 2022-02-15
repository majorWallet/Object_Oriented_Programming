#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void get_command(string& command);
void get_size(int& size);
int** gen_matrix(int& size);
void swap(int* a, int* b);
void sort_array(int* ary, int size);
void sort_matrix_row(int** matrix, int size);
void print_matrix(int** matrix, int size);
void save_matrix(int** matrix, int size);
void free_matrix(int** matrix, int size);

int main()
{
	string command;
	int** matrix = NULL;
	int size = 0;
	while (1)
	{
		get_command(command);
		if (command == "1") {
			get_size(size);
			matrix = gen_matrix(size);
		}
		else if (command == "2") {
			print_matrix(matrix, size);
		}
		else if (command == "3") {
			sort_matrix_row(matrix, size);
		}
		else if (command == "4") {
			save_matrix(matrix, size);
		}
		else if (command == "0") {
			free_matrix(matrix, size);
			cout << "Exit the program..." << endl;
			exit(104);
		}
		else {
			cout << "Wrong command" << endl << endl;
		}
	}

	return 0;
}

void get_command(string& command)
{
	cout << "1. Generate matrix" << endl;
	cout << "2. Print matrix" << endl;
	cout << "3. Sort matrix" << endl;
	cout << "4. Save matrix" << endl;
	cout << "0. Exit Program" << endl;
	cout << ">> ";
	cin >> command;
}

void get_size(int& size)
{
	cout << "Enter the size in (size x size): ";
	cin >> size;
	cout << endl;
}

int** gen_matrix(int& size)
{
	int** arr = new int*[size];
	for (int i = 0; i < size; i++)
		arr[i] = new int[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arr[i][j] = rand() % 101;
	return arr;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort_array(int* ary, int size)
{
	for (int i = size; i > 0; i--)
		for (int j = 1; j < i; j++)
			if (ary[j] < ary[j - 1])
				swap(ary[j], ary[j - 1]);
}

void sort_matrix_row(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
		sort_array(matrix[i], size);
	cout << "Completed" << endl << endl;
}

void print_matrix(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << setw(4) << matrix[i][j];
		cout << endl;
	}
	cout << endl;
}

void save_matrix(int** matrix, int size)
{
	ofstream fout;
	fout.open("matrix.txt");
	fout << size << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			fout << setw(4) << matrix[i][j];
		fout << endl;
	}
	cout << "Saved" << endl << endl;
	fout.close();
}

void free_matrix(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;
}