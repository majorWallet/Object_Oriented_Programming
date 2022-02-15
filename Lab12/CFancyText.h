#pragma once
#include <iostream>
#include <string>
#include "CText.h"
using namespace std;

class FancyText : public Text {
private:
	string left_brac;
	string right_brac;
	string connector;
public:
	FancyText(string _t, string _lb, string _rb, string _con);
	string get() override; //순수 가상 함수
	void append(string _extra) override;
};