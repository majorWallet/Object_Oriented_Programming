#include <iostream>
using namespace std;

class CStudent
{
private:
	int id;
	string name, major;
public:
	CStudent() : id(2018000000), name("홍길동"), major("컴퓨터공학과") { }
	CStudent(int id, string name, string major) : id(id), name(name), major(major) { }
	void Display()
	{
		cout << "학번: " << id << endl;
		cout << "이름: " << name << endl;
		cout << "전공: " << major << endl << endl;
	}
	void setNumber(int id)
	{
		this->id = id;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setMajor(string major)
	{
		this->major = major;
	}
	int getNumber()
	{
		return id;
	}
	string getName()
	{
		return name;
	}
	string getMajor()
	{
		return major;
	}
};

int main() {
	CStudent s[3]; // 3명의 학생정보를 저장할 class 배열
	int inputNumber; // 키보드로 학번을 입력 받을 변수
	string inputName, inputMajor; // 키보드로 이름, 전공을 입력 받을 변수
	int length = 0; // 현재 입력된 학생의 수
	while (1) {
		bool chkDuple = false;
		cout << length + 1 << " 번째 학생 입력" << endl;
		cout << "학번: ";
		cin >> inputNumber;
		cout << "이름: ";
		cin >> inputName;
		cout << "전공: ";
		cin >> inputMajor;
		for (int i = 0; i < 3; i++)
			if (s[i].getNumber() == inputNumber)
				chkDuple = true;
		if(chkDuple)
			cout << "*중복된 학번이 존재합니다." << endl;
		else
		{
			s[length].setNumber(inputNumber);
			s[length].setName(inputName);
			s[length++].setMajor(inputMajor);
			cout << "*입력 완료" << endl << endl;
		}
		if (length == 3)
		{
			cout << "----모든입력이 완료되었습니다----" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << i + 1 << "학생정보" << endl;
				s[i].Display();
			}
			break;
		}
	}
	return 0;
}