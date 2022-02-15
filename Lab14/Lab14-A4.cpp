#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <random>
using namespace std;

class FileNotFoundException : public exception {
	string message;
public:
	FileNotFoundException(const string& fname) :
		message("File \"" + fname + "\" not found") { }
	virtual const char* what() const throw() {
		return message.c_str();
	}
};

int main() {
	srand(time(NULL));

	ofstream fout("temp.txt");

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			fout << rand() % 101 << ' ';
		fout << endl;
	}

	fout.close();

	vector<vector<int>> v(10);
	for (vector<int>& elem : v)
		elem = vector<int>(10);

	try {
		string filename;
		int rowSize;
		int colSize;
		cout << "파일 이름: ";
		cin >> filename;
		ifstream fin(filename);
		if (!fin)
			throw FileNotFoundException(filename);

		int val;
		for (vector<int>& row : v)
			for (int& elem : row) {
				fin >> val;
				elem = val;
			}
		
		fin.close();

		cout << "출력할 행 크기: ";
		cin >> rowSize;
		cout << "출력할 열 크기: ";
		cin >> colSize;
		for (int i = 0; i < rowSize; i++) {
			for (int j = 0; j < colSize; j++) {
				cout << v.at(i).at(j) << ' ';
			}
			cout << endl;
		}
	}
	catch (exception& e) {
		cout << endl;
		cout << e.what() << endl;
	}
	
	return 0;
}