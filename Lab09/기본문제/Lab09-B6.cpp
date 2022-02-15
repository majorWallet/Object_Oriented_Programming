#include <iostream>
#include <vector>
using namespace std;

bool found_char(const char* s, char ch) {
	for (int i = 0; *(s + i) != '\0'; i++)
	{
		if (ch == *(s + i))
			return true;
	}
	return false;
}

int main() {
	// 012345(6)
	const char* phrase = "this is a phrase";// ch[]
	// phrase(\0)==NULL
	for (char ch = 'a'; ch <= 'z'; ch++) { // 'a' == 97, 'z' == 122
		cout << ch << " is ";
		if (!found_char(phrase, ch))
			cout << "NOT";
		cout << " in (" << phrase << ")" << endl;
	}
	return 0;
}