#pragma once
#include "Inhabitant.h"
class Forest
{
	vector <Fox*> foxes;
	vector <Rabbit*> rabbits;
	vector <Grass*> grass;
	void rabbitsEatGrass();
	void rabbitHunting();
	int countDeadFoxes();
	int countDeadRabbits();
	int countDeadGrass();
public:
	Forest();
	void setFoxes();
	void setRabbits();
	void setGrass();
	void count();
};

