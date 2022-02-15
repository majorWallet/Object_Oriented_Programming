#include <iostream>
#include <string>
#include <vector>
#include "CFancyText.h"
#include "CFixedText.h"
using namespace std;

int main() {
	/*
	vector<Text*> vec{
		new FancyText("Fixed", "<<", ">>", "*"),
		new FixedText()
	};

	//Text text;  //�߻� Ŭ������ ��üȭ�� �� ����!!!!!
	Text* pText;
	//pText = new Text();  //�߻� Ŭ������ ��üȭ �� �� ���ٴϱ�!!
	pText = new FancyText("Fancy1", "(", ")", "-");
	vec.push_back(pText);
	pText = new FixedText;
	vec.push_back(pText);

	for (auto elem : vec)  //for (Text* elem : vec)
		elem->append("A");

	for (auto elem : vec)  //for (Text* elem : vec)
		cout << elem->get() << endl;

	for (auto elem : vec)  //for (Text* elem : vec)
		delete elem;*/

	Text t1("Plain");
	t1.append("A");
	cout << t1.get() << endl;

	FancyText t2("Fancy", "<<", ">>", "***");
	t2.append("A");
	cout << t2.get() << endl;

	FixedText t3;
	t3.append("A");
	cout << t3.get() << endl;
	t1 = t2; //Base<-Derived ����
	//t2 = t1 //Derived<-Base �Ұ���

	return 0;
}