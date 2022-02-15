#include <iostream>
using namespace std;

class Account {
private:
	string name, id;
	int balance;
public:
	Account(string name, string id, int balance) : name(name), id(id), balance(balance) { }
	string getID() {
		return id;
	}
	int getBalance() {
		return balance;
	}
	Account operator+(Account& acc) {
		Account result(this->name, this->id, this->balance + acc.balance);
		return result;
	}
	Account operator-(Account& acc) {
		Account result(this->name, this->id, this->balance - acc.balance);
		return result;
	}
	friend ostream& operator<<(ostream& cout, const Account& acc);
};

ostream& operator<<(ostream& cout, const Account& acc) {
	cout << "�й�: " << acc.id << ", �̸�: " << acc.name << ", �ܾ�: " << acc.balance;
	return cout;
}

int main() {
	Account acc[3] = {
		Account("����ȣ", "2014", 10000),
		Account("������", "2019", 0),
		Account("������", "2013", 5000)
	};
	string withdrawID;
	string depositID;
	int withdraw_idx = -1;
	int deposit_idx = -1;
	while(true) {
		withdraw_idx = -1;
		deposit_idx = -1;
		cout << "���� ���� �л��� �й��� �Է��ϼ���: ";
		cin >> withdrawID;
		if (withdrawID == "����") {
			cout << "�����մϴ�." << endl;
			for (int i = 0; i < 3; i++)
				cout << acc[i] << endl;
			break;
		}
		cout << "���� ���� �л��� �й��� �Է��ϼ���: ";
		cin >> depositID;
		for (int i = 0; i < 3; i++)
			if (withdrawID == acc[i].getID())
				withdraw_idx = i;
		for (int i = 0; i < 3; i++)
			if (depositID == acc[i].getID())
				deposit_idx = i;
		if (withdrawID == depositID) {
			cout << "���� ���� �л��� �й��� ���� ���� �л��� �й��� �����մϴ�." << endl;
			continue;
		}
		else if (withdraw_idx == -1 || deposit_idx == -1) {
			cout << "������ �л� Ȥ�� �޴� �л��� �й��� �������� �ʽ��ϴ�. �ٽ� �Է����ּ���." << endl;
			continue;
		}
		else if (acc[withdraw_idx].getBalance() == 0) {
			cout << "������ �л��� �ܾ��� �����մϴ�." << endl;
			continue;
		}
		else {
			acc[deposit_idx] = acc[deposit_idx] + acc[withdraw_idx];
			acc[withdraw_idx] = acc[withdraw_idx] - acc[withdraw_idx];
			cout << "���� �л��� �ܾ� => " << acc[withdraw_idx] << endl;
			cout << "���� �л��� �ܾ� => " << acc[deposit_idx] << endl;
			continue;
		}
	}
	return 0;
}