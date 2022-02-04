#pragma once
#include "Person.h"
class PrintQueue
{
	Person* requests;
	int size;
	void resize(int size, int newSize);
	void insert(int pos, Person request);
public:
	PrintQueue();
	~PrintQueue();
	void push(Person request);
	void pop();
	void printStatistics();
};

