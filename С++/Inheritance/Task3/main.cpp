#include <iostream>
#define PI 3.14

using namespace std;

class Square
{
protected:
	double side;
public:
	Square(double side);
	double countAreaSquare();
};

Square::Square(double side)
{
	this->side = side;
}

double Square::countAreaSquare()
{
	return side * side;
}

class Circle
{
protected:
	double radius;
public:
	Circle(double radius);
	double countAreaCircle();
};

Circle::Circle(double radius)
{
	this->radius = radius;
}

double Circle::countAreaCircle()
{
	return PI * radius * radius;
}

class CircleInSquare : public Circle, public Square
{
public:
	CircleInSquare(double radius) : Circle(radius), Square(radius * 2) { }
	void print();
};

void CircleInSquare::print()
{
	cout << "Circle radius: " << radius << endl;
	cout << "Side of a square: " << side << endl;
	cout << "Circle area: " << countAreaCircle() << endl;
	cout << "Square area: " << countAreaSquare() << endl;
}

int main()
{
	double r;
	cout << "Enter radius: ";
	cin >> r;
	system("cls");
	CircleInSquare circleInS(r);
	circleInS.print();
	return 0;
}