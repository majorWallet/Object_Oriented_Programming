#include <iostream>
#include <fstream>
#include <string>
#include "cFoodItem.h"
#include "cOfficeItem.h"
#include "ApplicationClass.h"
using namespace std;

ApplicationClass::ApplicationClass(string name1, string name2)
	:foodItemFileName(name1), officeItemFileName(name2) {
	ifstream fin;

	Item* pItem = new FoodItem;
	fin.open("foodItem.txt");
	if (!fin) {
		cout << "File open failed!" << endl;
		exit(100);
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
		exit(100);
	}
	while (pItem->readItemFromFile(fin)) {
		vItem.push_back(pItem);
		pItem = new OfficeItem;
	}
	fin.close();
}

string getCommand() {
	string item;
	cout << "1. Display all items." << endl;
	cout << "2. Display food items." << endl;
	cout << "3. Display office items." << endl;
	cout << "4. Search item by code." << endl;
	cout << "5. Quit." << endl;
	cout << "Input>";
	cin >> item;
	return item;
}

void ApplicationClass::run() {
	string sOption;
	while (1) {
		sOption = getCommand();
		if (sOption == "1")			displayAllItems();
		else if (sOption == "2")	displayFoodItems();
		else if (sOption == "3")	displayOfficeItems();
		else if (sOption == "4")	searchItemByCode();
		else if (sOption == "5")	break;
	}
	cout << "Exit the program..." << endl;
}

void ApplicationClass::displayAllItems() const {
	for (Item* elem : vItem)
		elem->displayItem();
}

void ApplicationClass::displayFoodItems() const {
	for (Item* elem : vItem)
		if (elem->getCode()[0] == 'F')
			elem->displayItem();
}

void ApplicationClass::displayOfficeItems() const {
	for (Item* elem : vItem)
		if (elem->getCode()[0] == 'C')
			elem->displayItem();
}

void ApplicationClass::searchItemByCode() const {
	string code;
	cout << "Enter the code: ";
	cin >> code;
	bool chk = false;
	for (Item* elem : vItem)
		if (elem->getCode() == code) {
			elem->displayItem();
			chk = true;
		}
	if (!chk)
		cout << "No items found." << endl;
}