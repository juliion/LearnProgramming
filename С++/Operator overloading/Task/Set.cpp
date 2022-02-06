#include "Set.h"

Set::Set(int* elements, int size)
{
	this->size = size;
	this->elements = new int[size];
	int ind = 0;
	for (int i = 0; i < this->size; i++)
	{
		if (!has(elements[ind]))
			this->elements[i] = elements[ind];
		else
		{
			resize(--this->size);
			i--;
		}
		ind++;
	}
}

Set::~Set()
{
	delete[] elements;
}

bool Set::has(int num)
{
	for (int i = 0; i < size; i++)
	{
		if (elements[i] == num)
			return true;
	}
	return false;
}

bool Set::has(int num) const
{
	for (int i = 0; i < size; i++)
	{
		if (elements[i] == num)
			return true;
	}
	return false;
}

void Set::resize(int newSize)
{
	int* newElements = new int[newSize];
	int minSize = size > newSize ? newSize : size;
	for (int i = 0; i < minSize; i++)
		newElements[i] = elements[i];
	delete[] elements;
	elements = newElements;
}

Set& Set::operator+=(const Set& s)
{
	size += s.size;
	resize(size);
	int ind = 0;
	for (int i = size - s.size; i < size; i++)
	{
		if(!has(s.elements[ind]))
			elements[i] = s.elements[ind];
		else
		{
			resize(--size);
			i--;
		}
		ind++;
	}
	return *this;
}

Set& Set::operator+=(int element)
{
	if (!has(element))
	{
		resize(++size);
		elements[size - 1] = element;
	}
	return *this;
}

Set& Set::operator-=(const Set& s)
{
	int ind = 0;
	for (int i = 0; i < s.size; i++)
	{
		int elementOfS = s.elements[i];
		if (has(elementOfS))
			*this -= elementOfS;
	}
	return *this;
}

Set& Set::operator-=(int element)
{
	if (!has(element))
		exit(0);
	int* newElements = new int[size - 1];
	int  ind = 0;
	for (int i = 0; i < size; i++)
	{
		if (elements[ind] == element)
			i--;
		else
			newElements[i] = elements[ind];
		ind++;
	}
	delete[] elements;
	elements = newElements;
	size--;
	return *this;
}

Set& Set::operator*=(const Set& s)
{
	for (int i = 0; i < size; i++)
	{
		int element = elements[i];
		if (!s.has(element))
		{
			*this -= element;
			i--;
		}
	}
	return *this;
}

Set& Set::operator=(const Set& s)
{
	delete[] elements;
	size = s.size;
	elements = new int[size];
	for (int i = 0; i < size; i++)
		elements[i] = s.elements[i];
	return *this;
}