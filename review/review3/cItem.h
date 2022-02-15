#pragma once
#include <string>
using namespace std;

class Item {
protected:
	string code;
	string name;
	int price;
public:
	//////////////////////////////////////////////////////////
	Item(string code = "", string name = "", int price = 0);
	void setCode(string code);
	void setName(string name);
	void setPrice(int price);
	string getCode();
	string getName();
	int getPrice();
	//////////////////////////////////////////////////////////
	void setItem(string code, string name, int price);
	/*bool readItemFromFile(ifstream& fin) {
		this->setItem("", "", 0);
		string str;
		if (getline(fin, str)) {
			int idx = 0;
			while (str[idx] != '\t') {
				code += str[idx++];
			}
			idx++;
			while (str[idx] != '\t') {
				name += str[idx++];
			}
			idx++;
			string _price;
			while (str[idx] != '\0') {
				_price += str[idx++];
			}
			price = stoi(_price);
			return true;
		}
		else {
			return false;
		}
	}*/
	/*void writeItemToFile(ofstream& fout) {
		fout << code << '\t' << name << '\t' << price << '\n';
	}*/
	//////////////////////////////////////////////////////////
	virtual void displayItem() const = 0;
	virtual bool readItemFromFile(ifstream& fin) = 0;
	virtual void writeItemToFile(ofstream& fout) = 0;
};