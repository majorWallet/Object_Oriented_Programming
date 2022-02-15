#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "cItem.h"
#include "cOfficeItem.h"
#include "cFoodItem.h"
#include "ApplicationClass.h"
using namespace std;

/*int main() {
	Item item1("C1001", "계산기", 14000);
	Item item2;
	item2.setCode("F1002");
	item2.setName("계산기");
	item2.setPrice(1000);

	cout << item1.getCode() << setw(10) << item1.getName() << setw(10) << item1.getPrice() << endl;
	cout << item2.getCode() << setw(10) << item2.getName() << setw(10) << item2.getPrice() << endl;

	return 0;
}*/

/*int main() {
	Item temp;
	vector<Item> vItem;
	string inFileName = "item.txt";
	string outFileName = "item_output.txt";

	ifstream fin;
	fin.open(inFileName);
	if (!fin) {
		cout << "File open failed!" << endl;
		return 0;
	}

	while (temp.readItemFromFile(fin))
		vItem.push_back(temp);
	fin.close();

	temp.setItem("E1002", "박카스", 1000);
	vItem.push_back(temp);

	ofstream fout;
	fout.open(outFileName);

	for (auto elem : vItem)
		elem.writeItemToFile(fout);
	fout.close();

	return 0;
}*/

/*int main() {
	vector<Item*> vItem;
	Item* pItem = new FoodItem;

	ifstream fin;
	fin.open("foodItem.txt");
	if (!fin) {
		cout << "File open failed!" << endl;
		return 0;
	}
	while (pItem->readItemFromFile(fin)) {
		vItem.push_back(pItem);
		pItem = new FoodItem;
	}
	fin.close();

	pItem = new OfficeItem;
	fin.open("officeItem.txt");
	if (!fin) {
		cout << "File open failed!" << endl;
		return 0;
	}
	while (pItem->readItemFromFile(fin)) {
		vItem.push_back(pItem);
		pItem = new OfficeItem;
	}
	fin.close();

	for (Item* elem : vItem) {
		elem->displayItem();
		delete elem;
	}

	return 0;
}*/

int main() {
	ApplicationClass appManager("foodItem.txt", "officeItem.txt");
	appManager.run();

	return 0;
}