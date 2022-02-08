#include <iostream>
#define PI 3.14
using namespace std;

class Figure
{
public:
	virtual void setData() = 0;
	virtual void countArea() = 0;
};

class Rectangle : public Figure
{
	int a;
	int b;
public:
	Rectangle(int a1, int b1) : a{ a1 }, b{ b1 } { }
	Rectangle() : Rectangle(0, 0) { }
	virtual void setData() override
	{
		cout << "Rectangle:" << endl;
		cout << "Enter the first side: ";
		cin >> a;
		cout << "The second side: ";
		cin >> b;
	}
	virtual void countArea() override
	{
		cout << "Rectangle:" << endl;
		cout << "Area: " << a * b << endl;
	}
};

class Circle : public Figure
{
	int radius;
public:
	Circle(int r) : radius{ r } { }
	Circle() : Circle(0) { }
	virtual void setData() override
	{
		cout << "Circle:" << endl;
		cout << "Enter radius: ";
		cin >> radius;
	}
	virtual void countArea() override
	{
		cout << "Circle:" << endl;
		cout << "Area: " << PI * radius * radius << endl;
	}
};

class RightTriangle : public Figure
{
	int a;
	int b;
public:
	RightTriangle(int a1, int b1) : a{ a1 }, b{ b1 } { }
	RightTriangle() : RightTriangle(0, 0) { }
	virtual void setData() override
	{
		cout << "Right triangle:" << endl;
		cout << "Enter the first leg: ";
		cin >> a;
		cout << "The second leg: ";
		cin >> b;
	}
	virtual void countArea() override
	{
		cout << "Right triangle:" << endl;
		cout << "Area: " <<  a * b / 2 << endl;
	}
};

class Trapezoid : public Figure
{
	int a;
	int b;
	int h;
public:
	Trapezoid(int a1, int b1, int h1) : a{ a1 }, b{ b1 }, h{ h1 } { }
	Trapezoid() : Trapezoid(0, 0, 0) { }
	virtual void setData() override
	{
		cout << "Trapezoid: " << endl;
		cout << "Enter the first base: ";
		cin >> a;
		cout << "The second base: ";
		cin >> b;
		cout << "Height: ";
		cin >> h;
	}
	virtual void countArea() override
	{
		cout << "Trapezoid: " << endl;
		cout << "Area: " << (a + b) * h / 2 << endl;
	}
};

int main()
{
	const int countFig = 4;
	Figure* figures[countFig] = {new Rectangle, new Circle, new RightTriangle, new Trapezoid};
	for (int i = 0; i < countFig; i++)
	{
		cout << "Create figures: " << endl;
		figures[i]->setData();
		system("cls");
	}
	cout << "Areas of figures: " << endl;
	for (int i = 0; i < countFig; i++)
	{
		cout << endl;
		figures[i]->countArea();
	}
	return 0;
}