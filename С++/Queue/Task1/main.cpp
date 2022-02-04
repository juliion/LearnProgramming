#include <iostream>
#include "Busstop.h"
#include "Bus.h"
using namespace std;

enum DurationTime
{
	morning = 240,
	day = 420,
	evening = 300,
	night = 250
};

enum TypeBusstop
{
	start,
	other
};

int main()
{
	//test
	setlocale(0, "");
	Busstop b (30, 1, start, morning);
	//Busstop b(20, 1, start, morning);
	//Busstop b(30, 1, start, day);
	//Busstop b(30, 1, start, evening);
	//Busstop b(30, 1, start, night);
	//Busstop b(30, 1, other, morning);
	//Busstop b(30, 1, other, day);
	//Busstop b(30, 1, other, evening);
	//Busstop b(30, 1, other, night);
	b.printDate();
	return 0;
}