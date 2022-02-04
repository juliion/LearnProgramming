#pragma once
#include <iostream>
#include <vector>
#include "Bus.h"
#include "Queue.h"
using namespace std;

class Busstop
{
	int intervalArriveBus;
	int intervalArriveHuman;
	int type;
	int durationTime;
	vector <Bus> busses;
	Queue* timeHumans;
	void pushBus();
public:
	Busstop(int intervalArriveBus, int intervalArriveHuman, int type, int durationTime);
	void averHumanTime();
	void optimalIntArriveBus();
	void printDate();
};



