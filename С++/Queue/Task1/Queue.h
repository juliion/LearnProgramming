#pragma once
class Queue
{
	int* elements;
	int size;
	void resize(int size, int newSize);
public:
	Queue();
	~Queue();
	void push(int element);
	void pop();
	void increaseElements(int n);
	int getSize();
	double countAverage(int n);
	void clear();
};

