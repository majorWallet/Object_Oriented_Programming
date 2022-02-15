#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class FileNotFoundException : public exception {
	string message;
public:
	FileNotFoundException(string _m) :
		message("File not found: " + _m) { }
	virtual const char* what() const throw() {
		return message.c_str();
	}
};

vector<int> load_vector(string filename) {
	ifstream fin(filename);

	if (!fin) {
		throw FileNotFoundException(filename);
	}

	vector<int> result;
	int num, val;
	fin >> num;

	for (int i = 0; i < num; i++) { 
		fin >> val;
		result.push_back(val);
	}

	return result;
}

int main() {
	try {
		auto v = load_vector("values.dat");
		for (int elem : v)
			cout << elem << ' ';
		cout << endl;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}