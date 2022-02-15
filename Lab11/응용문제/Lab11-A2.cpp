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
	cout << "학번: " << acc.id << ", 이름: " << acc.name << ", 잔액: " << acc.balance;
	return cout;
}

int main() {
	Account acc[3] = {
		Account("장윤호", "2014", 10000),
		Account("김유진", "2019", 0),
		Account("박진배", "2013", 5000)
	};
	string withdrawID;
	string depositID;
	int withdraw_idx = -1;
	int deposit_idx = -1;
	while(true) {
		withdraw_idx = -1;
		deposit_idx = -1;
		cout << "돈을 보낼 학생의 학번을 입력하세요: ";
		cin >> withdrawID;
		if (withdrawID == "종료") {
			cout << "종료합니다." << endl;
			for (int i = 0; i < 3; i++)
				cout << acc[i] << endl;
			break;
		}
		cout << "돈을 받을 학생의 학번을 입력하세요: ";
		cin >> depositID;
		for (int i = 0; i < 3; i++)
			if (withdrawID == acc[i].getID())
				withdraw_idx = i;
		for (int i = 0; i < 3; i++)
			if (depositID == acc[i].getID())
				deposit_idx = i;
		if (withdrawID == depositID) {
			cout << "돈을 보낼 학생의 학번과 돈을 받을 학생의 학번이 동일합니다." << endl;
			continue;
		}
		else if (withdraw_idx == -1 || deposit_idx == -1) {
			cout << "보내는 학생 혹은 받는 학생의 학번이 존재하지 않습니다. 다시 입력해주세요." << endl;
			continue;
		}
		else if (acc[withdraw_idx].getBalance() == 0) {
			cout << "보내는 학생의 잔액이 부족합니다." << endl;
			continue;
		}
		else {
			acc[deposit_idx] = acc[deposit_idx] + acc[withdraw_idx];
			acc[withdraw_idx] = acc[withdraw_idx] - acc[withdraw_idx];
			cout << "보낸 학생의 잔액 => " << acc[withdraw_idx] << endl;
			cout << "받은 학생의 잔액 => " << acc[deposit_idx] << endl;
			continue;
		}
	}
	return 0;
}