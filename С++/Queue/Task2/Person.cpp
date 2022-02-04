#include "Person.h"
using namespace std;

enum Priority
{
	small,
	average,
	high
};

Person::Person(string name, int priority, Date* printDate)
{
	this->name = name;
	this->priority = priority;
	this->printDate = printDate;
}

int Person::getPriority()
{
	return priority;
}

Date Person::getPrintDate()
{
	return *printDate;
}

void Person::print()
{
	cout << "Name: " << name << endl;
	cout << "Priority: ";
	switch (priority)
	{
		case small: cout << "small" << endl; break;
		case average: cout << "average" << endl; break;
		case high: cout << "high" << endl; break;
	}
	printDate->print();
}