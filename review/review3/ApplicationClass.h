#pragma once
#include <string>
#include <vector>
#include "cItem.h"

class ApplicationClass {
private:
	vector<Item*> vItem;
	string officeItemFileName;
	string foodItemFileName;
public:
	ApplicationClass(string name1, string name2);
	void run();
	void displayAllItems() const;
	void displayFoodItems() const;
	void displayOfficeItems() const;
	void searchItemByCode() const;
};