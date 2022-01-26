#include "Date.h"

Date::Date(int year, int mounth, int day, int hours, int minutes)
{
	this->year = year;
	this->mounth = mounth;
	this->day = day;
	this->hours = hours;
	this->minutes = minutes;
}

void Date::print()
{
	if (day < 10)
		cout << 0 << day;
	else
		cout << day;
	cout << ".";
	if (mounth < 10)
		cout << 0 << mounth;
	else
		cout << mounth;
	cout << "." << year << "  ";
	if (hours < 10)
		cout << 0 << hours;
	else
		cout << hours;
	cout << ":";
	if (minutes < 10)
		cout << 0 << minutes;
	else
		cout << minutes;
}