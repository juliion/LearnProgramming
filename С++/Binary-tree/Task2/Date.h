#pragma once
#include <iostream>
using namespace std;

class Date
{
	int year;
	int mounth;
	int day;
	int hours;
	int minutes;
public:
	Date(int year, int mounth, int day, int hours, int minutes);
	Date() : Date(0, 0, 0, 0, 0) { }
	void print();
};

