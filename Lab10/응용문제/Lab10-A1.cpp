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
	CStudent s1; // A
	s1.Display();
	CStudent s2(1999000000, "����ö", "���ؿ�ȭ��"); // B
	s2.Display();
	// C
	s1.setNumber(2006000000);
	s1.setName("�ΰ���");
	s1.setMajor("����Ʈ���");
	cout << "�й� :" << s1.getNumber() << endl;
	cout << "�̸� :" << s1.getName() << endl;
	cout << "���� :" << s1.getMajor() << endl;
	return 0;
}