#include "cFoodItem.h"

void FoodItem::displayItem() const {
	cout << code << '\t' << name << '\t' << price << '\t' << dueDate << endl;
}

bool FoodItem::readItemFromFile(ifstream& fin) {
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
		string _dueDate;
		while (str[idx] != '\0')
			_dueDate += str[idx++];
		dueDate = stoi(_dueDate);
		return true;
	}
	else
		return false;
}

void FoodItem::writeItemToFile(ofstream& fout) {
	fout << code << '\t' << name << '\t' << price << dueDate << '\n';
}