#include "Forest.h"

Forest::Forest()
{
	setFoxes();
	setRabbits();
	setGrass();
}

void Forest::setFoxes()
{
	int n;
	cout << "Enter number of foxes: ";
	cin >> n;
	cout << "Foxes in the forest:" << endl;
	for (int i = 0; i < n; i++)
	{
		Fox* newFox = new Fox();
		foxes.push_back(newFox);
		cout << "Fox " << i + 1 << endl;
		cout << "age: " << newFox->getAge() << endl << endl;
	}
}

void Forest::setRabbits()
{
	int n;
	cout << "Enter number of rabbits: ";
	cin >> n;
	cout << "Rabbits in the forest:" << endl;
	for (int i = 0; i < n; i++)
	{
		Rabbit* newRab = new Rabbit();
		rabbits.push_back(newRab);
		cout << "Rabbit " << i + 1 << endl;
		cout << "age: " << newRab->getAge() << endl << endl;
	}
}

void Forest::setGrass()
{
	int n;
	cout << "Enter number of grass: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Grass* newGrass = new Grass();
		grass.push_back(newGrass);
	}
}

void Forest::rabbitsEatGrass()
{
	int numOfRabbits = rabbits.size();
	int numOfGrass = grass.size();
	if (numOfRabbits > numOfGrass)
	{
		for (int i = 0; i < numOfGrass; i++)
			grass[i]->die();
	}
}

void Forest::rabbitHunting()
{
	int numOfRabbits = rabbits.size();
	int numOfFoxes = foxes.size();
	if (numOfRabbits <= numOfFoxes)
	{
		for (int i = 0; i < numOfRabbits; i++)
			rabbits[i]->die();
	}
}

int Forest::countDeadFoxes()
{
	int count = 0;
	for (int i = 0; i < foxes.size(); i++)
	{
		if (!foxes[i]->getLive())
			count++;
	}
	return count;
}

int Forest::countDeadRabbits()
{
	int count = 0;
	for (int i = 0; i < rabbits.size(); i++)
	{
		if (!rabbits[i]->getLive())
			count++;
	}
	return count;
}

int Forest::countDeadGrass()
{
	int count = 0;
	for (int i = 0; i < grass.size(); i++)
	{
		if (!grass[i]->getLive())
			count++;
	}
	return count;
}

void Forest::count()
{
	int numOfRabbits = rabbits.size();
	int numOfFoxes = foxes.size();
	int numOfGrass = grass.size();
	for (int i = 0; i < numOfFoxes; i++)
	{
		if (!foxes[i]->checkAge())
			foxes[i]->die();
	}
	for (int i = 0; i < numOfRabbits; i++)
	{
		if (!rabbits[i]->checkAge())
			rabbits[i]->die();
	}
	rabbitsEatGrass();
	rabbitHunting();
	cout << endl << "---------------------------------" << endl;
	cout << "Dead foxes: " << countDeadFoxes() << endl;
	cout << "Dead rabbits: " << countDeadRabbits() << endl;
	cout << "Eaten grass: " << countDeadGrass() << endl;
}