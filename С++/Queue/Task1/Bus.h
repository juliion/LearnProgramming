#pragma once
class Bus
{
	int freePlaces;
public:
	static int maxFreePlaces;
	Bus();
	void setRandomFreePlaces();
	int getFreePlaces();
};

