#pragma once
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
	friend bool operator< (const Date &d1, const Date &d2);
	void print();
};

