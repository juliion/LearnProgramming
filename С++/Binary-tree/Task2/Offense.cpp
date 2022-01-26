#include "Offense.h"

Offense::Offense(Date* date, string type, string cost)
{
	this->date = date;
	this->type = type;
	this->cost = cost;
}

void Offense::print()
{
	cout << "Date of offense: ";
	date->print();
	cout << endl;
	cout << "Type: " << type << endl;
	cout << "Cost of the fine: " << cost << endl;
}