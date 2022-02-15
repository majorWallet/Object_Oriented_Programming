#include <iostream>
#include <vector>
using namespace std;

// private(class �� ���ٰ���), protected(class �� ���� ����), public(class ��/�� ���� ����)
// -protected : Base class���� ����� ���� ���

// base type	|	inheritance type	|	derived type
// -------------|-----------------------|----------------
// private		|	��� ����			|	���� �Ұ�(Base�� �ٸ� ���� ������ method�� ���� ����)
// protected	|	��� ����			|	private
// public		|	private/protected	|	private
// public		|	public				|	public

class Base {
protected:
	void print_base() {
		cout << "Base" << endl;
	}
	/*
	virtual void print() {
		cout << "Base::print()" << endl;
	}*/
};

class Derived : public Base {
public:
	void print_derived() {
		print_base();
		cout << "Derived" << endl;
	}
	/*
	//	���������� �߰��Ǿ� ����!!
	//void print_base() {
	//	cout << "Base" << endl;
	//}
	void print() override {	//function overrideing, base class�� method�� derived class���� ���� �������� ������
		cout << "Derived::print()" << endl;
	}*/
};

int main() {
	Base base;
	Derived derived;
	derived.print_derived();
	//���� ���ε�(static binding): compile�� �� ��ü�� � method�� ȣ������ ����
	//���� ���ε�(dynamic binding): run-time�� ȣ���� method�� ��Ȳ�� �°� ����
	//-�θ�Ŭ������ pointer�� �ڽ�Ŭ���� ��ü�� �ּҰ��� �Ҵ�
	//-�ٽ� Ű���� : virtual, override
	//-����: ������ - single interface(�θ�Ŭ���� pointer)�� �پ��� �ڽ�Ŭ������ ���
	/*Base* pBase = &derived;
	pBase->print();
	pBase = &base;
	pBase->print();
	cout << endl;

	vector<Base*> vec{ new Base, new Derived, new Base };
	pBase = new Derived;
	vec.push_back(pBase);

	for (auto& elem : vec)
		elem->print();
	for (auto& elem : vec)
		delete elem;*/
	return 0;
}