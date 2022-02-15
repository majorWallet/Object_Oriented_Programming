#include <iostream>
#include <cmath>
using namespace std;

class Polygon {
public:
	Polygon() {}
	Polygon(int point, float length) { mPoint = point, mLength = length; }
	~Polygon() {}
	virtual void calcPerimeter() { cout << "Perimeter: empty" << endl; }
	virtual void calcArea() { cout << "Area: empty" << endl; }
protected:
	int mPoint;
	double mLength;
};

class Rectangle : public Polygon {
public:
	Rectangle() { }
	Rectangle(int point, float length) : Polygon(point, length) { }
	~Rectangle() { }
	void calcPerimeter() override { cout << "Perimeter: " << Polygon::mPoint * Polygon::mLength << endl; }
	void calcArea() override { cout << "Area: " << Polygon::mLength * Polygon::mLength << endl; }
};

int main() {
	Polygon pol;
	Rectangle rec(4, 10);

	cout << "--- Polygon class ---" << endl;
	pol.calcPerimeter();
	pol.calcArea();

	cout << "--- Rectangle class ---" << endl;
	rec.calcPerimeter();
	rec.calcArea();

	return 0;
}