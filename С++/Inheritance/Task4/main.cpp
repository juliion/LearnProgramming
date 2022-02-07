#include <iostream>

using namespace std;

class Point 
{
	int x;
	int y;
public:
	Point();
	void setPoint(int x, int y);
	void print();
};

Point::Point()
{
	x = y = 0;
}

void Point::setPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Point::print()
{
	cout << "----------------------------" << endl << endl;
	cout << x << "\t" << y << endl << endl;
	cout << "----------------------------" << endl << endl;
}

class Figura 
{
	Point* points;
	int count;
	int color;
public:
	Figura();
	void createFigura(int color, int count);
	void printFigura();
	~Figura();
};

Figura::Figura()
{
	count = color = 0;
	points = nullptr;
}

void Figura::createFigura(int color, int count)
{
	if (count < 3)
		exit(0);
	this->count = count;
	this->color = color;
	points = new Point[count];
	if (!points)
		exit(1);
	int tempX, tempY;
	for (int i = 0; i < count; i++)
	{
		cout << "Set x" << i+1 << ": ";
		cin >> tempX;
		cout << "Set y" << i+1 << ": ";
		cin >> tempY;
		cout << endl;
		points[i].setPoint(tempX, tempY);
	}
}

void Figura::printFigura()
{
	cout << "============================" << endl;
	cout << "Color: " << color << endl << endl
		<< "Points: " << count << endl << endl;
	for (int i = 0; i < count; i++)
	{
		points[i].print();
	}
}

Figura::~Figura()
{
	if (points != nullptr)
		delete[] points;
}

class Picture
{
	Figura* figures;
	int countFigures;
public:
	Picture();
	void createPicture(int countFigures);
	void printPicture();
	~Picture();
};

Picture::Picture()
{
	figures = nullptr;
	countFigures = 0;
}

void Picture::createPicture(int countFigures)
{
	if (countFigures < 1)
		exit(2);
	this->countFigures = countFigures;
	figures = new Figura[countFigures];
	if (!figures)
		exit(3);
	int count, color;
	for (int i = 0; i < countFigures; i++)
	{
		cout << "Figura " << i + 1 << endl;
		cout << "Enter count of corners: ";
		cin >> count;
		cout << "Enter color: ";
		cin >> color;
		figures[i].createFigura(color, count);
		system("cls");
	}
}

void Picture::printPicture()
{
	for (int i = 0; i < countFigures; i++)
	{
		cout << "Figura " << i + 1 << endl;
		figures[i].printFigura();
	}
}

Picture::~Picture()
{
	if (figures != nullptr)
		delete[] figures;
}

int main()
{
	Picture picture;
	picture.createPicture(2);
	picture.printPicture();
	return 0;
}