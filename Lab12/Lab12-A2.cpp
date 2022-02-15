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

class Triangle : public Polygon {
public:
	Triangle() { }
	Triangle(int point, float length) : Polygon(point, length) { }
	~Triangle() { }
	void calcPerimeter() override { cout << "Perimeter: " << Polygon::mPoint * Polygon::mLength << endl; }
	void calcArea() override { cout << "Area: " << Polygon::mLength * Polygon::mLength * (sqrt(3) / 4) << endl; }
};

class Circle : public Polygon {
public:
	Circle() { }
	Circle(int point, float length) : Polygon(point, length) { }
	~Circle() { }
	void calcPerimeter() override { cout << "Perimeter: " << 6.28 * Polygon::mLength << endl; }
	void calcArea() override { cout << "Area: " << Polygon::mLength * Polygon::mLength * 3.14 << endl; }
};

int main() {
	Triangle tri(3, 10);
	Rectangle rec(4, 10);
	Circle cir(0, 5);

	cout << "--- Triangle class ---" << endl;
	tri.calcPerimeter();
	tri.calcArea();

	cout << "--- Rectangle class ---" << endl;
	rec.calcPerimeter();
	rec.calcArea();

	cout << "--- Circle class ---" << endl;
	cir.calcPerimeter();
	cir.calcArea();

	return 0;
}