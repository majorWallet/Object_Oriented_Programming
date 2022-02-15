#pragma once

#include <iostream>
#include <string>
using namespace std;

class Text {
protected:
	string text;
public:
	Text(string _t) : text(_t) { }
	//virtual string get() = 0;  //순수 가상 함수
	virtual string get() {
		return text;
	}
	//virtual void append(string _extra) = 0;  //순수 가상 함수
	virtual void append(string _extra) { text += _extra; }
};