#include <iostream>
#include <ctime>
#include "Bus.h"

int Bus::maxFreePlaces = 20;

Bus::Bus()
{
	freePlaces = maxFreePlaces;
}

void Bus::setRandomFreePlaces()
{
	srand(time(0));
	freePlaces = 1 + rand() % maxFreePlaces;
}

int Bus::getFreePlaces()
{
	return freePlaces;
}