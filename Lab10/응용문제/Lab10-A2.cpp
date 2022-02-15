#include <iostream>
using namespace std;

class CStudent
{
private:
	int id;
	string name, major;
public:
	CStudent() : id(2018000000), name("ȫ�浿"), major("��ǻ�Ͱ��а�") { }
	CStudent(int id, string name, string major) : id(id), name(name), major(major) { }
	void Display()
	{
		cout << "�й�: " << id << endl;
		cout << "�̸�: " << name << endl;
		cout << "����: " << major << endl << endl;
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
	CStudent s[3]; // 3���� �л������� ������ class �迭
	int inputNumber; // Ű����� �й��� �Է� ���� ����
	string inputName, inputMajor; // Ű����� �̸�, ������ �Է� ���� ����
	int length = 0; // ���� �Էµ� �л��� ��
	while (1) {
		bool chkDuple = false;
		cout << length + 1 << " ��° �л� �Է�" << endl;
		cout << "�й�: ";
		cin >> inputNumber;
		cout << "�̸�: ";
		cin >> inputName;
		cout << "����: ";
		cin >> inputMajor;
		for (int i = 0; i < 3; i++)
			if (s[i].getNumber() == inputNumber)
				chkDuple = true;
		if(chkDuple)
			cout << "*�ߺ��� �й��� �����մϴ�." << endl;
		else
		{
			s[length].setNumber(inputNumber);
			s[length].setName(inputName);
			s[length++].setMajor(inputMajor);
			cout << "*�Է� �Ϸ�" << endl << endl;
		}
		if (length == 3)
		{
			cout << "----����Է��� �Ϸ�Ǿ����ϴ�----" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << i + 1 << "�л�����" << endl;
				s[i].Display();
			}
			break;
		}
	}
	return 0;
}