#include <iostream>
#include "Queue.h"

Queue::Queue()
{
	elements = nullptr;
	size = 0;
}

Queue::~Queue()
{
	if (elements != nullptr)
		delete[] elements;
}

void Queue::resize(int size, int newSize)
{
	int* newElements = new int[newSize];
	for (int i = 0; i < size; i++)
		newElements[i] = elements[i];
	if (elements != nullptr)
		delete[] elements;
	elements = newElements;
}

void Queue::push(int element)
{
	resize(size++, size);
	elements[size - 1] = element;
}

void Queue::pop()
{
	if (size == 0)
		exit(1);
	size--;
	int* newElements = new int[size];
	for (int i = 0; i < size; i++)
		newElements[i] = elements[i + 1];
	if (elements != nullptr)
		delete[] elements;
	elements = newElements;
}

void Queue::increaseElements(int n)
{
	for (int i = 0; i < size; i++)
		elements[i] += n;
}

int Queue::getSize()
{
	return size;
}

double Queue::countAverage(int n)
{
	if(n > size)
		exit(2);
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += elements[i];
	return sum /= n;
}

void Queue::clear()
{
	size = 0;
	if (elements != nullptr)
		delete[] elements;
	elements = nullptr;
}