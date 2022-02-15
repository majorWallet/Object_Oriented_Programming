#include <iostream>
#include <vector>
using namespace std;

// private(class 내 접근가능), protected(class 내 점근 가능), public(class 내/외 점근 가능)
// -protected : Base class에서 상속을 위해 사용

// base type	|	inheritance type	|	derived type
// -------------|-----------------------|----------------
// private		|	상관 없음			|	접근 불가(Base의 다른 접근 가능한 method를 통해 접근)
// protected	|	상관 없음			|	private
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
	//	가상적으로 추가되어 있음!!
	//void print_base() {
	//	cout << "Base" << endl;
	//}
	void print() override {	//function overrideing, base class의 method를 derived class에서 같은 선언으로 재정의
		cout << "Derived::print()" << endl;
	}*/
};

int main() {
	Base base;
	Derived derived;
	derived.print_derived();
	//정적 바인딩(static binding): compile할 때 객체가 어떤 method를 호출할지 결정
	//동적 바인딩(dynamic binding): run-time시 호출할 method가 상황에 맞게 결정
	//-부모클래스의 pointer에 자식클래스 객체의 주소값을 할당
	//-핵심 키워드 : virtual, override
	//-응용: 다형성 - single interface(부모클래스 pointer)로 다양한 자식클래슬를 사용
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