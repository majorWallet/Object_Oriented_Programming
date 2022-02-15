#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Text {
protected:
	string text;
public:
	Text(string _t) : text(_t) { }
	//virtual string get() = 0;  //���� ���� �Լ�
	virtual string get() {
		return text;
	}
	//virtual void append(string _extra) = 0;  //���� ���� �Լ�
	virtual void append(string _extra) { text += _extra; }
};

class FancyText : public Text {
private:
	string left_brac;
	string right_brac;
	string connector;
public:
	FancyText(string _t, string _lb, string _rb, string _con) : Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_con) { }
	string get() override {
		return left_brac + Text::text + right_brac;
	} //���� ���� �Լ�
	void append(string _extra) override {
		Text::text += connector + _extra;
	}
};

class FixedText : public Text {
public:
	FixedText() : Text::Text("Fixed") { }
	string get() override {
		return Text::text;
	}
	void append(string _extra) override {
		NULL;
	}
};

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