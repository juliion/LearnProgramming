#include "Inhabitant.h"

int Fox::maxFoxAge{ 10 };

int Rabbit::maxRabbitAge{ 7 };

int  Fox::getAge()
{
	return age;
}

int  Rabbit::getAge()
{
	return age;
}

bool Fox::checkAge()
{
	return age < maxFoxAge;
}

bool Rabbit::checkAge()
{
	return age < maxRabbitAge;
}