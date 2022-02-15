#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "cItem.h"
using namespace std;

class FoodItem : public Item {
private:
	int dueDate;
public:
	void displayItem() const override;
	bool readItemFromFile(ifstream& fin) override;
	void writeItemToFile(ofstream& fout) override;
};