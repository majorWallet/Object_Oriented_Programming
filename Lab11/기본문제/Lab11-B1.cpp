#include <iostream>
using namespace std;

class Point {
private:
	int x, y;
	static int numCreatedObjects;
public:
	Point() : x(0), y(0) {
		numCreatedObjects++;
	}

	Point(int _x, int _y) : x(_x), y(_y) {
		numCreatedObjects++;
	}

	~Point() {
		cout << "Destructed..." << endl;
	}

	int getX() const { return x; }
	int getY() const { return y; }
	void setXY(int x, int y) { this->x = x; this->y = y; }

	/*
	Point operator+(const Point& pt) {
		return Point(this->x + pt.x, this->y + pt.y);
	}*/

	Point& operator=(const Point& pt) {
		this->x = pt.x;
		this->y = pt.y;
		return *this;
	}

	static int getNumCreatedObject() {
		return numCreatedObjects;
	}

	//friend Point operator+(const Point& pt1, const Point& pt2);
	friend void print(const Point& pt);
	friend ostream& operator<<(ostream& cout, const Point& pt);
	friend class SpyPoint;
};

//static member variable initialization
int Point::numCreatedObjects = 0;

//recommend using call by reference when parameter is object
//const parameter can call only const method

void print(const Point& pt) {
	cout << pt.x << ", " << pt.y << endl;
}

/*
Point operator+(const Point& pt1, const Point& pt2) //operator overloading, same operator name, different operator parameter(object)
{
	Point result(pt1.getX() + pt2.getX(), pt1.getY() + pt2.getY());
	return result;
}*/

ostream& operator<<(ostream& cout, const Point& pt)
{
	cout << pt.x << ", " << pt.y << endl;
	return cout;
}

class SpyPoint {
public:
	void hack_all_info(const Point& pt) {
		cout << "Hacked by SpyPoint" << endl;
		cout << "x: " << pt.x << endl;
		cout << "y: " << pt.y << endl;
		cout << "numCreatedObj: " << pt.numCreatedObjects << endl;
		cout << endl << endl;;
	}
};

int main()
{
	Point pt1(1, 2);
	cout << "pt1 : ";
	print(pt1);
	cout << endl;

	Point* pPt1 = &pt1;
	cout << "pt1 : ";
	cout << (*pPt1).getX() << ", " << (*pPt1).getY() << endl;
	cout << "pt1 : ";
	cout << pPt1->getX() << ", " << pPt1->getY() << endl;
	cout << endl;

	Point* pPt2 = new Point(10, 20);
	cout << "pt2 : ";
	cout << pPt2->getX() << ", " << pPt2->getY() << endl;
	cout << endl;

	pPt1->~Point();
	delete pPt2;

	cout << "pt1 NumCreatedObject : ";
	cout << pt1.getNumCreatedObject() << endl;
	Point pt2(10, 20), pt3(30, 40);
	Point pt4 = pt2 + pt3;  //I don't know exactly but, destructor was called in here
	cout << "pt2: ";
	cout << pt2;
	cout << "pt3: ";
	cout << pt3;
	cout << "pt4: ";
	cout << pt4;

	cout << "pt1 NumCreatedObject : ";
	cout << pt1.getNumCreatedObject() << endl << endl;

	Point* ptAry = new Point[5];
	cout << "pt2 NumCreatedObject: ";
	cout << pt2.getNumCreatedObject() << endl;
	cout << endl;

	delete[] ptAry;
	cout << endl;

	SpyPoint spy;
	cout << "pt1 info" << endl;
	spy.hack_all_info(pt1);
	cout << "pt4 info" << endl;
	spy.hack_all_info(pt4);

	return 0;
}