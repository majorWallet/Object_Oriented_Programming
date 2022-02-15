#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "cItem.h"
using namespace std;

class OfficeItem : public Item {
private:
	string company;
public:
	void displayItem() const override;
	bool readItemFromFile(ifstream& fin) override;
	void writeItemToFile(ofstream& fout) override;
};