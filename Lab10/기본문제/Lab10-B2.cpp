#include <string>
#include <iostream>
using namespace std;
class Account {
private: //멤버변수
	string name;
	string id;
	double balance;
public: // 멤버함수(method)
// 3개의 생성자 구현
/*구현*/ // 기본생성자. name : "", id : "", balance : 0 으로 초기화
/*구현*/ // name, id 받아오고, balance는 0으로 초기화
/*구현*/ // name, id , balance 받아와서 초기화, balance < 0 인 경우 0으로 초기화
	Account() :	name(""), id(""), balance(0) { }
	Account(string name, string id) : name(name), id(id), balance(0) { }
	Account(string name, string id, int balance) : name(name), id(id), balance(balance < 0 ? 0 : balance) { }
	void deposit(double _amt) { balance += _amt; }
	bool withdraw(double _amt) {
		if (balance - _amt < 0)
			return false;
		balance -= _amt;
		return true;
	}
	void print() {
		cout << name << ", " << id << ", " << balance << endl;
	}
};
int main() {
	Account ac1("배성호", "1002", 5000);
	Account ac2;
	ac2.print();
	ac1.print();
	int depo;
	cout << "예금할 금액을 입력하세요 : ";
	cin >> depo;
	ac1.deposit(depo);
	ac1.print();
	int wdrw;
	cout << "출금할 금액을 입력하세요 : ";
	cin >> wdrw;
	if (!ac1.withdraw(wdrw))
		cout << "잔액이 부족합니다." << endl;
	ac1.print();
	return 0;
}