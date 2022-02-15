#include "CFixedText.h"

FixedText::FixedText() : Text::Text("Fixed") { }
string FixedText::get() {
	return Text::text;
}
void FixedText::append(string _extra) {
	NULL;
}