#include "cOfficeItem.h"

void OfficeItem::displayItem() const {
	cout << code << '\t' << name << '\t' << price << '\t' << company << endl;
}

bool OfficeItem::readItemFromFile(ifstream& fin) {
	string str;
	if (getline(fin, str)) {
		int idx = 0;
		while (str[idx] != '\t')
			code += str[idx++];
		idx++;
		while (str[idx] != '\t')
			name += str[idx++];
		idx++;
		string _price;
		while (str[idx] != '\t')
			_price += str[idx++];
		price = stoi(_price);
		idx++;
		while (str[idx] != '\0')
			company += str[idx++];
		return true;
	}
	else
		return false;
}

void OfficeItem::writeItemToFile(ofstream& fout) {
	fout << code << '\t' << name << '\t' << price << company << '\n';
}