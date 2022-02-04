#pragma once
#include <iostream>
#include "Date.h"
using namespace std;

class Person
{
	string name;
	int priority;
	Date* printDate;
public:
	Person(string name, int priority, Date* printDate);
	Person() : Person(" ", -1, nullptr) { }
	int getPriority();
	Date getPrintDate();
	void print();

};

