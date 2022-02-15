#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

bool getStu(ifstream& fin, int& id, int& exam1, int& exam2, int& exam3) {
	fin >> id >> exam1 >> exam2 >> exam3;
	if (!fin)
		return false;
	return true;
}

void calcAvgGrade(int& avg, int& exam1, int& exam2, int& exam3, char& grade) {
	avg = (exam1 + exam2 + exam3) / 3;
	if (avg >= 90)
		grade = 'A';
	else if (avg >= 80)
		grade = 'B';
	else
		grade = 'F';
}

void writeStu(ofstream& fout, int& id, int& avg, char& grade) {
	fout.fill('0');
	fout << setw(4) << id;
	fout.fill(' ');
	fout << setw(4) << avg;
	fout << setw(4) << grade << endl;
}

int main() {
	ifstream fin("ch7STUFL.DAT");
	ofstream fout("grade.txt");
	string str;
	int id, exam1, exam2, exam3, avg;
	char grade;

	while (getStu(fin, id, exam1, exam2, exam3))
	{
		calcAvgGrade(avg, exam1, exam2, exam3, grade);
		writeStu(fout, id, avg, grade);
	}

	fin.close();
	fout.close();
	cout << "end";
	return 0;
}