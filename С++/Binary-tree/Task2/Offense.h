#pragma once
#include "Date.h"

class Offense
{
	Date* date;
	string type;
	string cost;
public:
	Offense(Date* date, string type, string cost);
	void print();
};

