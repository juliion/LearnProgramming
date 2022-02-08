#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Equation
{
protected:
	vector<double> roots;
	virtual void calculateRoots() = 0;
public:
	virtual void setData() = 0;
	virtual void printRoots() = 0;
};

class QuadraticEquation : public Equation
{
	double a;
	double b;
	double c;
	virtual void calculateRoots() override;
public:
	QuadraticEquation() : a{ 0 }, b{ 0 }, c{ 0 } {}
	virtual void setData() override;
	virtual void printRoots() override;
};

void QuadraticEquation::calculateRoots()
{
	if (a != 0)
	{
		double D = b * b - 4 * a * c;
		if (D < 0)
			return;
		if (D == 0)
		{
			double x = (-1 * b) / (2 * a);
			roots.push_back(x);
		}
		else
		{
			double x1 = (-1 * b + sqrt(D)) / (2 * a);
			double x2 = (-1 * b - sqrt(D)) / (2 * a);
			roots.push_back(x1);
			roots.push_back(x2);
		}
	}
	else
	{
		if (b == 0)
			return;
		double x = -1 * c / b;
		roots.push_back(x);
	}
}

void QuadraticEquation::setData()
{
	cout << "quadratic equation: " << endl;
	cout << "ax^2 + bx + c = 0" << endl;
	cout << "Enter a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;
	calculateRoots();
}

void QuadraticEquation::printRoots()
{
	int countRoots = roots.size();
	if (a == -1)
		cout << "-";
	else if (a != 1)
		cout << a;
	cout << "x^2 ";
	if(b == -1)
		cout << "- ";
	else if (b == 1)
		cout << "+ ";
	else if (b < 0)
		cout << b;
	else
		cout << "+ " << b;
	cout << "x ";
	if (c < 0)
		cout << c;
	else
		cout << "+ " << c;
	cout << " = 0" << endl;

	if (countRoots == 0)
		cout << "Equation has no roots" << endl;
	else
	{
		for (int i = 0; i < countRoots; i++)
			cout << "x" << i + 1 << " = " << roots[i] << endl;
	}
}

class LinearEquation : public Equation
{
	double a;
	double b;
	virtual void calculateRoots() override;
public:
	LinearEquation() : a{ 0 }, b{ 0 } {}
	virtual void setData() override;
	virtual void printRoots() override;
};

void LinearEquation::calculateRoots()
{
	if (a == 0)
		return;
	double x = -1 * b / a;
	roots.push_back(x);
}

void LinearEquation::setData()
{
	cout << "linear equation: " << endl;
	cout << "ax + b = 0" << endl;
	cout << "Enter a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	calculateRoots();
}

void LinearEquation::printRoots()
{
	int countRoots = roots.size();
	if (a == -1)
		cout << "-";
	else if (a != 1)
		cout << a;
	cout << "x ";
	if (b < 0)
		cout << b;
	else
		cout << "+ " << b;
	cout << " = 0" << endl;

	if (countRoots == 0)
		cout << "Equation has no roots" << endl;
	else
		cout << "x = " << roots[0] << endl;
}

int main()
{
	const int countE = 2;
	Equation* e[countE] = { new QuadraticEquation(), new LinearEquation() };
	for (int i = 0; i < countE; i++)
	{
		e[i]->setData();
		system("cls");
		e[i]->printRoots();
		cout << endl;
	}
	return 0;
}