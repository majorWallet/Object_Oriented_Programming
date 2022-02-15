#pragma once

#include <iostream>
#include <string>
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