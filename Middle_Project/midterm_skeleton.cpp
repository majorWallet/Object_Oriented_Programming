#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Utils
int findStudentById(vector<string> studentIds, string id);
int findLectureByCode(vector<string> lectureCodes, string code);
void deleteElement(vector<string>& v, int index);

// File read
void readStudentFile(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes);
void readLectureFile(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits);

// File write
void writeStudentFile(const vector<string>& studentIds, const vector<string>& passwords, const vector<string>& names, const vector<int>& credits, const vector<vector<string>>& appliedLectureCodes);
void writeLectureFile(const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits);

// Get user input
string getInputId();
string getInputPassword();

// Login
int studentLogin(const vector<string>& studentIds, const vector<string>& passwords);
bool adminLogin();
int login(const vector<string>& studentIds, const vector<string>& passwords);

// Common
void printLectures(const vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits, const int& user = -100);

// Admin
void addStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes);
void addLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits);
void deleteLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, vector<int>& credits, vector<vector<string>>& appliedLectureCodes);
int runAdmin(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits);

// User
void printStudent(const vector<string>& studentIds, const vector<string>& names, const vector<int>& credits, const int& user);
void applyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user);
void disapplyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user);
void changePassword(vector<string>& passwords, const int& user);
int runStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, int user);

int main() {
	int user = -1; //user index
	int status = -1;

	// Student Info
	vector<string> studentIds;
	vector<string> passwords;
	vector<string> names;
	vector<int> credits;
	vector<vector<string>> appliedLectureCodes;

	// Lecture Info
	vector<string> lectureCodes;
	vector<string> lectureNames;
	vector<int> lectureCredits;
	vector<int> limits;

	// Read from files
	readStudentFile(studentIds, passwords, names, credits, appliedLectureCodes);
	readLectureFile(lectureCodes, lectureNames, lectureCredits, limits);

	// Login phase
	while (status == -1) {
		user = login(studentIds, passwords);

		if (user == -999) { // Login fail
			exit(-999);
		}
		else if (user == -1) { // Exit command
			exit(-1);
		}
		else if (user == -100) { // Admin login success
			status = runAdmin(studentIds, passwords, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits);
		}
		else { // Student login success
			status = runStudent(studentIds, passwords, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		}
	}

	// Write to files
	writeStudentFile(studentIds, passwords, names, credits, appliedLectureCodes);
	writeLectureFile(lectureCodes, lectureNames, lectureCredits, limits);

	return 0;
}

int findStudentById(vector<string> studentIds, string id) {
	for (unsigned i = 0; i < studentIds.size(); i++) {
		if (studentIds[i] == id)
			return i;
	}
	return -1;
}

int findLectureByCode(vector<string> lectureCodes, string code) {
	for (unsigned i = 0; i < lectureCodes.size(); i++) {
		if (lectureCodes[i] == code)
			return i;
	}
	return -1;
}

void deleteElement(vector<string>& v, int index) {
	v.erase(v.begin() + index);
}

void readStudentFile(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	string data;
	ifstream fin;
	char ch;
	fin.open("students.txt");
	if (!fin) {
		cout << "Error, no such file exists" << endl;
		exit(100);
	}
	while (fin.get(ch)) {
		data = ch;  //���ǹ����� ���� ch�� data�� ����
		string str;  //operator>>�� ���� ���ڿ��� ������ str ����
		fin >> str;
		data += str;  //data�� operator>>�� ���� str�� �̾� ����
		studentIds.push_back(data);
		fin >> data;
		passwords.push_back(data);
		fin >> data;
		names.push_back(data);
		fin >> data;
		credits.push_back(stoi(data));
		fin >> data;  //just reading, don't save it in vector
		vector<string> userLectureCodes;
		data = "";
		fin.get(ch);
		while (true) {
			fin.get(ch);
			if (ch == '\t') {
				if (data.length() > 0)
					userLectureCodes.push_back(data);
				data = "";
				continue;
			}
			else if (ch == '\n') {
				if (data.length() > 0)
					userLectureCodes.push_back(data);
				data = "";
				break;
			}
			data += ch;
		}
		appliedLectureCodes.push_back(userLectureCodes);
	}
	fin.close();
}

void readLectureFile(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	string data;
	ifstream fin;
	fin.open("lectures.txt");
	if (!fin) {
		cout << "Error, no such file exists" << endl;
		exit(100);
	}
	while (true) {
		fin >> data;
		if (!fin)
			break;
		lectureCodes.push_back(data);
		fin >> data;
		lectureNames.push_back(data);
		fin >> data;
		lectureCredits.push_back(stoi(data));
		fin >> data;
		limits.push_back(stoi(data));
	}
	fin.close();
}

void writeStudentFile(const vector<string>& studentIds, const vector<string>& passwords, const vector<string>& names, const vector<int>& credits, const vector<vector<string>>& appliedLectureCodes) {
	ofstream fout;
	fout.open("students.txt");
	for (int i = 0; i < studentIds.size(); i++) {
		fout << studentIds[i] << '\t' << passwords[i] << '\t' << names[i] << '\t' << credits[i] << '\t' << appliedLectureCodes[i].size() << '\t';
		for (int j = 0; j < appliedLectureCodes[i].size(); j++) {
			if (j != appliedLectureCodes[i].size() - 1)
				fout << appliedLectureCodes[i][j] << '\t';
			else
				fout << appliedLectureCodes[i][j];
		}
		fout << endl;
	}
	fout.close();
}

void writeLectureFile(const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits) {
	ofstream fout;
	fout.open("lectures.txt");
	for (int i = 0; i < lectureCodes.size(); i++)
		fout << lectureCodes[i] << '\t' << lectureNames[i] << '\t' << lectureCredits[i] << '\t' << limits[i] << endl;
	fout.close();
}

string getInputId() {
	string ID;
	cout << "���̵�: ";
	cin >> ID;
	return ID;
}

string getInputPassword() {
	string PW;
	cout << "��й�ȣ: ";
	cin >> PW;
	return PW;
}

int studentLogin(const vector<string>& studentIds, const vector<string>& passwords) {
	int failCnt = 0;
	while (failCnt++ < 3) {
		string ID = getInputId();
		for (int i = 0; i < studentIds.size(); i++) {
			if (ID == studentIds[i]) {
				string PW = getInputPassword();
				if (PW == passwords[i])
					return i;
			}
		}
		cout << "�α��� " << failCnt << "ȸ ���� (3ȸ ���н� ����)" << endl;
	}
	cout << "3ȸ �����Ͽ� �����մϴ�." << endl;
	return -999;
}

bool adminLogin() {
	int failCnt = 0;
	while (failCnt++ < 3) {
		if (getInputId() == "admin" && getInputPassword() == "admin")
			return true;
		cout << "�α��� " << failCnt << "ȸ ���� (3ȸ ���н� ����)" << endl;
	}
	cout << "3ȸ �����Ͽ� �����մϴ�." << endl;
	return false;
}

int login(const vector<string>& studentIds, const vector<string>& passwords) {
	string item;
	do {
		cout << "--------------------------------------------------------" << endl;
		cout << "1. �л� �α���" << endl;
		cout << "2. ������ �α���" << endl;
		cout << "0. ����" << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << ">>";
		cin >> item;
	} while (!(item == "0" || item == "1" || item == "2"));

	if (item == "1")
		return studentLogin(studentIds, passwords);
	else if (item == "2")
	{
		if (adminLogin())
			return -100;
		else
			return -999;
	}
	else if (item == "0")
		return -1;
}

void printLectures(const vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits, const int& user) {
	cout << "--------------------------------------------------------" << endl;
	cout << "�����ڵ�\t���Ǹ�\t\t����\t���������ο�" << endl;
	cout << "--------------------------------------------------------" << endl;
	if (user == -100)
		for(int i = 0; i < lectureCodes.size(); i++)
			cout << lectureCodes[i] << '\t' << lectureNames[i] << '\t' << lectureCredits[i] << '\t' << limits[i] << endl;
	else
		for (int i = 0; i < lectureCodes.size(); i++)
			for(int j = 0; j < appliedLectureCodes[user].size(); j++)
				if (lectureCodes[i] == appliedLectureCodes[user][j])
					cout << lectureCodes[i] << '\t' << lectureNames[i] << '\t' << lectureCredits[i] << '\t' << limits[i] << endl;
	cout << "--------------------------------------------------------" << endl;
}

void addStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	string ID, PW, NAME;
	cout << "--------------------------------------------------------" << endl;
	cout << "�й�: ";
	cin >> ID;
	cout << "��й�ȣ: ";
	cin >> PW;
	cout << "�л� �̸�: ";
	cin >> NAME;
	cout << "--------------------------------------------------------" << endl;
	if (findStudentById(studentIds, ID) == -1) {
		studentIds.push_back(ID);
		passwords.push_back(PW);
		names.push_back(NAME);
		credits.push_back(18);
		vector<string> userLectureCodes;
		appliedLectureCodes.push_back(userLectureCodes);
		cout << "���������� ��ϵǾ����ϴ�." << endl;
	}
	else
		cout << "�̹� �����ϴ� �й��Դϴ�." << endl;
}

void addLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	bool chkDuple = false;
	string LCo, LN;
	int LCr, LL;
	cout << "--------------------------------------------------------" << endl;
	cout << "�����ڵ�: ";
	cin >> LCo;
	cout << "�����: ";
	cin >> LN;
	cout << "����: ";
	cin >> LCr;
	cout << "�����ο�: ";
	cin >> LL;
	cout << "--------------------------------------------------------" << endl;
	for (string elem : lectureCodes)
		if (elem == LCo)
			chkDuple = true;
	if(chkDuple)
		cout << "�̹� �����ϴ� �����ڵ��Դϴ�." << endl;
	else {
		lectureCodes.push_back(LCo);
		lectureNames.push_back(LN);
		lectureCredits.push_back(LCr);
		limits.push_back(LL);
		cout << "���������� ���ǰ� �����Ǿ����ϴ�." << endl;
	}
}

void deleteLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
	printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits);
	string LCo;
	cout << "������ ���� �ڵ� (0: �ڷΰ���) >> ";
	if (LCo == "0")
		return;
	cin >> LCo;
	int LCodeIdx = findLectureByCode(lectureCodes, LCo);
	if (LCodeIdx == -1) {
		cout << "��ġ�ϴ� �ڵ尡 �����ϴ�." << endl;
		return;
	}
	else
	{
		for (int j = 0; j < appliedLectureCodes.size(); j++)
			for (int k = 0; k < appliedLectureCodes[j].size(); k++)
				if (appliedLectureCodes[j][k] == LCo) {
					deleteElement(appliedLectureCodes[j], k);
					credits[j] += lectureCredits[LCodeIdx];
				}
		for (int i = 0; i < lectureCodes.size(); i++)
			if (LCo == lectureCodes[i]) {
				deleteElement(lectureCodes, i);
				deleteElement(lectureNames, i);
				lectureCredits.erase(lectureCredits.begin() + i);
				limits.erase(limits.begin() + i);
				cout << "���������� ���ǰ� ���Ǿ����ϴ�." << endl;
				return;
			}
	}
}

int runAdmin(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
	string item;
	while (true) {
		do {
			cout << "--------------------------------------------------------" << endl;
			cout << "1. �л� �߰�" << endl;
			cout << "2. ���� ����" << endl;
			cout << "3. ���� ����" << endl;
			cout << "4. �α׾ƿ�" << endl;
			cout << "0. ����" << endl;
			cout << "--------------------------------------------------------" << endl;
			cout << ">>";
			cin >> item;
		} while (!(item == "0" || item == "1" || item == "2" || item == "3" || item == "4"));
		if (item == "0")
			return 1;
		else if (item == "1") {
			addStudent(studentIds, passwords, names, credits, appliedLectureCodes);
			system("PAUSE");
		}
		else if (item == "2") {
			addLecture(lectureCodes, lectureNames, lectureCredits, limits);
			system("PAUSE");
		}
		else if (item == "3") {
			deleteLecture(lectureCodes, lectureNames, lectureCredits, limits, credits, appliedLectureCodes);
			system("PAUSE");
		}
		else if (item == "4")
			return -1;
	}
}

void printStudent(const vector<string>& studentIds, const vector<string>& names, const vector<int>& credits, const int& user) {
	cout << "--------------------------------------------------------" << endl;
	cout << "�й�: " << studentIds[user] << '\t' << "�̸�: " << names[user] << '\t' << "������������: " << credits[user] << endl;
	cout << "--------------------------------------------------------" << endl;
}

void applyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {
	string inputLCode;
	int LCodeIdx = -1;
	while (true) {
		printStudent(studentIds, names, credits, user);
		printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits);
		cout << "��û�� ���� �ڵ�(0: �ڷΰ���) >> ";
		cin >> inputLCode;
		if (inputLCode == "0")
			return;
		LCodeIdx = findLectureByCode(lectureCodes, inputLCode);
		if (LCodeIdx == -1) {
			cout << "���� �ڵ尡 �ùٸ��� �ʽ��ϴ�." << endl;
			system("PAUSE");
			continue;
		}
		else
			break;
	}
	bool chkCodeDuplicates = false;  //true: �ߺ� ����, false: �ߺ� ����
	bool chkNameDuplicates = false;  //true: �ߺ� ����, false: �ߺ� ����
	bool chkCredits = (credits[user] < lectureCredits[LCodeIdx]);  //true: ���� �Ұ���, false: ���� ����
	bool chkLimits = (limits[LCodeIdx] < 1);  //true: ���� �Ұ���, false: ���� ����
							/*Finding Code Duplicates*/
	for (string elem : appliedLectureCodes[user])
		if (elem == lectureCodes[LCodeIdx])  //lectureCodes[LCodeIdx]: entered lectureCode
			chkCodeDuplicates = true;
							/*Finding Name Duplicates*/
	vector<string> LCodesWithSameName;
	for (int i = 0; i < appliedLectureCodes.size(); i++)  //push back lecture codes which has same name into vector named LCodesWithSameName
		if (lectureNames[i] == lectureNames[LCodeIdx])
			LCodesWithSameName.push_back(lectureCodes[i]);
	for (string elem1 : LCodesWithSameName)  //find duplicates of the same name which has a same or different LCode
		for(string elem2 : appliedLectureCodes[user])
			if(elem1 == elem2)
				chkNameDuplicates = true;

	if (chkLimits)
		cout << "���� ������ �� á���ϴ�." << endl;
	else if (chkCredits)
		cout << "�������������� �����մϴ�." << endl;
	else if (chkCodeDuplicates)
		cout << "�̹� �ش� ������ ��û�߽��ϴ�." << endl;
	else if (chkNameDuplicates)
		cout << "�̹� ���ϸ��� ������ ��û�߽��ϴ�." << endl;
	else {
		appliedLectureCodes[user].push_back(inputLCode);
		credits[user] -= lectureCredits[LCodeIdx];
		limits[LCodeIdx]--;
		cout << "[" << lectureCodes[LCodeIdx] << "]" << lectureNames[LCodeIdx] << "(��)�� ���������� ��û�Ͽ����ϴ�." << endl;
	}
}

void disapplyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {
	string inputLCode;
	int LCodeIdx = -1;
	while (true) {
		printStudent(studentIds, names, credits, user);
		printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
		cout << "öȸ�� ���� �ڵ�(0: �ڷΰ���) >> ";
		cin >> inputLCode;
		if (inputLCode == "0")
			return;
		LCodeIdx = findLectureByCode(appliedLectureCodes[user], inputLCode);
		if (LCodeIdx == -1) {
			cout << "���� �ڵ尡 �ùٸ��� �ʽ��ϴ�." << endl;
			system("PAUSE");
			continue;
		}
		else
			break;
	}
	LCodeIdx = findLectureByCode(lectureCodes, inputLCode);
	for (int i = 0; i < appliedLectureCodes[user].size(); i++)
		if (inputLCode == appliedLectureCodes[user][i]) {
			deleteElement(appliedLectureCodes[user], i);
			credits[user] += lectureCredits[LCodeIdx];
			limits[LCodeIdx]++;
			cout << "[" << inputLCode << "] " << lectureNames[LCodeIdx] << "(��)�� öȸ�Ͽ����ϴ�." << endl;
			return;
		}
}

void changePassword(vector<string>& passwords, const int& user) {
	string PW;
	cout << "--------------------------------------------------------" << endl;
	cout << "���� Ȯ���� ���� ��й�ȣ�� �� �� �� �Է����ּ���." << endl;
	cout << "��й�ȣ: ";
	cin >> PW;
	cout << "--------------------------------------------------------" << endl;
	if (passwords[user] == PW) {
		cout << "--------------------------------------------------------" << endl;
		cout << "���� ������ ��й�ȣ�� �Է��ϼ���." << endl;
		cout << "��й�ȣ: ";
		cin >> passwords[user];
		cout << "����Ǿ����ϴ�." << endl;
		cout << "--------------------------------------------------------" << endl;
	}
	else
		cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
}

int runStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, int user) {
	string item;
	while (true) {
		do {
			cout << "--------------------------------------------------------" << endl;
			cout << "1. ���� ��û" << endl;
			cout << "2. ���� ��Ȳ" << endl;
			cout << "3. ���� öȸ" << endl;
			cout << "4. ��й�ȣ ����" << endl;
			cout << "5. �α׾ƿ�" << endl;
			cout << "0. ����" << endl;
			cout << "--------------------------------------------------------" << endl;
			cout << ">>";
			cin >> item;
		} while (!(item == "0" || item == "1" || item == "2" || item == "3" || item == "4" || item == "5"));
		if (item == "0")
			return 1;
		else if (item == "1") {
			applyLecture(studentIds, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
			system("PAUSE");
		}
		else if (item == "2") {
			printStudent(studentIds, names, credits, user);
			printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
			system("PAUSE");
		}
		else if (item == "3") {
			disapplyLecture(studentIds, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
			system("PAUSE");
		}
		else if (item == "4") {
			changePassword(passwords, user);
			system("PAUSE");
		}
		else if (item == "5")
			return -1;
	}
}