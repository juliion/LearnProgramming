#include <iostream>

using namespace std;

class Employer
{
protected:
	int minSalary;
	Employer(int minSal) : minSalary{ minSal } { }
public:
	virtual void print() = 0;
};

class President : public Employer
{
public:
	President(int minSal) : Employer(minSal) 
	{
		minSalary *= 4;
	}
	virtual void print() override
	{
		cout << "Position: President" << endl;
		cout << "Salary: " << minSalary << endl;
	}
};

class Manager : public Employer
{
public:
	Manager(int minSal) : Employer(minSal)
	{
		minSalary *= 2;
	}
	virtual void print() override
	{
		cout << "Position: Manager" << endl;
		cout << "Salary: " << minSalary << endl;
	}
};

class Worker : public Employer
{
public:
	Worker(int minSal) : Employer(minSal) { }
	virtual void print() override
	{
		cout << "Position: Worker" << endl;
		cout << "Salary: " << minSalary << endl;
	}
};

int main()
{
	int minSal;
	cout << "Enter min salary: ";
	cin >> minSal;
	system("cls");
	const int countEmp = 3;
	Employer* employers[countEmp] = {new President(minSal), new Manager(minSal), new Worker(minSal)};
	cout << "Employers:" << endl;
	cout << "----------------------------------" << endl;
	for (int i = 0; i < countEmp; i++)
	{
		employers[i]->print();
		cout << "----------------------------------" << endl;
	}
	return 0;
}