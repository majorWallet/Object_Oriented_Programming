#include <iostream>
using namespace std;

class Account {
private:
	string id, name;
	int balance;
	static int sum;
public:
	Account(string id = "", string name = "", int balance = 0) : id(id), name(name), balance(balance) { }
	~Account() {
		sum += balance;
	}
	void setAcc(string id, string name, int balance) {
		this->id = id;
		this->name = name;
		this->balance = balance;
	}
	string getID() {
		return id;
	}
	static int getSum() {
		return sum;
	}
};

int Account::sum = 0;

int main() {
	int accNum = 0;
	cout << "�� �л� �� �Է�: ";
	cin >> accNum;
	Account* acc = new Account[accNum];
	string ID;
	string name;
	int balance;
	for (int i = 0; i < accNum; i++) {
		cout << i + 1 << "��° �л� ���� �Է�" << endl;
		cout << "�й�: ";
		cin >> ID;
		for (int j = 0; j < i; j++)
			if (acc[j].getID() == ID)
				exit(100);
		cout << endl;
		cout << "�̸�: ";
		cin >> name;
		cout << endl;
		cout << "�ܾ�: ";
		cin >> balance;
		acc[i].setAcc(ID, name, balance);
		cout << "==========================" << endl << endl;
	}
	delete[] acc;
	cout << "ȸ���� �ݾ�: " << Account::getSum() << endl;
	return 0;
}