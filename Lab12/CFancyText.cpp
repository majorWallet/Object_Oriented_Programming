#include "CFancyText.h"

FancyText::FancyText(string _t, string _lb, string _rb, string _con)
	: Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_con) { }
string FancyText::get() {
	return left_brac + Text::text + right_brac;
} //순수 가상 함수
void FancyText::append(string _extra) {
	Text::text += connector + _extra;
}