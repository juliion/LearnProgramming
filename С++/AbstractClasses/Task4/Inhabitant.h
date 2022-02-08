#pragma once
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
 
class Inhabitant
{
protected:
	bool isAlive;
public:
	Inhabitant() : isAlive{ true } { }
	int getLive()
	{
		return isAlive;
	}
	void die()
	{
		isAlive = false;
	}
};

class Fox : public Inhabitant
{
	int age;
	static int maxFoxAge;
public:
	Fox() : Inhabitant()
	{
		age = 1 + rand() % maxFoxAge;
	}
	int getAge();
	bool checkAge();
};

class Rabbit : public Inhabitant
{
	int age;
	static int maxRabbitAge;
public:
	Rabbit() : Inhabitant()
	{
		age = 1 + rand() % maxRabbitAge;
	}
	int getAge();
	bool checkAge();
};

class Grass : public Inhabitant
{
public:
	Grass() : Inhabitant() { }
};
