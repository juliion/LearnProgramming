#pragma once
#include "Tree.h"

class Phonebook
{
	Tree* treeAlphabet;
	Tree* treePhNumbers;
public:
	Phonebook();
	void addPerson(Person* person);
	void removePerson(Person* person);
	void changePerson(Person* person);
	void search();
	void print();
	void writeToFile(const char* name);
};

