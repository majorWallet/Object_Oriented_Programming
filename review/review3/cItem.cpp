#include "cItem.h"

Item::Item(string code, string name, int price)
	: code(code), name(name), price(price) { }

void Item::setCode(string code) {
	this->code = code;
}

void Item::setName(string name) {
	this->name = name;
}

void Item::setPrice(int price) {
	this->price = price;
}

string Item::getCode() {
	return code;
}

string Item::getName() {
	return name;
}

int Item::getPrice() {
	return price;
}

void Item::setItem(string code, string name, int price) {
	this->code = code;
	this->name = name;
	this->price = price;
}