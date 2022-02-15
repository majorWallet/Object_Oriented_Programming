#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) { }
	void setPoint(int x, int y) { this->x = x; this->y = y; }
	int getX() const { return x; }
	int getY() const { return y; }
	Point operator-(const Point pt) {
		Point result(this->x - pt.x, this->y - pt.y);
		return result;
	}
	Point operator*(const Point pt) {
		Point result(this->x * pt.x, this->y * pt.y);
		return result;
	}
	Point& operator=(const Point& pt) {
		this->x = pt.x;
		this->y = pt.y;
		return *this;
	}
};

int main() {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	Point* pP1, * pP2, * pP3;

	cout << "첫번째 좌표(x1, y1)를 입력하세요: ";
	cin >> x1 >> y1;
	cout << "두번째 좌표(x2, y2)를 입력하세요: ";
	cin >> x2 >> y2;

	pP1 = new Point(x1, y1);
	pP2 = new Point(x2, y2);
	pP3 = new Point();

	pP1->setPoint(x1, y1);
	pP2->setPoint(x2, y2);

	*pP3 = (*pP1 - *pP2) * (*pP1 - *pP2);
	cout << "두 좌표 사이의 거리는 " << sqrt(pP3->getX() + pP3->getY()) << "입니다." << endl;

	return 0;
}