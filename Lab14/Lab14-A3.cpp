#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

class Cstudent {
private:
	string m_Name;
	int m_Number;
	string m_Major;
public:
	Cstudent() { }
	~Cstudent() { }
	void setAll(string _name, int _num, string _maj) {
		m_Name = _name;
		m_Number = _num;
		m_Major = _maj;
	}
	void Display() {
		cout << "이름: " << m_Name << endl;
		cout << "학번: " << m_Number << endl;
		cout << "전공: " << m_Major << endl << endl;
	}
};

vector<Cstudent> read_file(string& filename) {
	ifstream fin(filename);
	if (!fin)
		throw FileNotFoundException(filename);

	vector<Cstudent> numbers;

	string name;
	int number;
	string major;

	int num, cnt = 0;
	fin >> num;

	while (cnt++ < num) {
		fin >> name >> number >> major;
		Cstudent temp;
		temp.setAll(name, number, major);
		numbers.push_back(temp);
	}

	return numbers;
}

int main() {
	string str;

	cout << "파일 이름: ";
	cin >> str;

	try {
		vector<Cstudent> numbers = read_file(str);
		for (Cstudent value : numbers)
			value.Display();
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	return 0;
}