#include <iostream>
#include "Set.h"
using namespace std;

int* resizeArr(int* arr, int size, int newSize)
{
	int* newArr = new int[newSize];
	int minSize = size > newSize ? newSize : size;
	for (int i = 0; i < minSize; i++)
		newArr[i] = arr[i];
	delete[] arr;
	return newArr;
}

const Set operator+(const Set& s1, const Set& s2)
{
	int newSize = s1.size + s2.size;
	int* newElements = new int[newSize];
	for (int i = 0; i < newSize; i++)
	{
		if(i < s1.size)
			newElements[i] = s1.elements[i];
		else if(i >= s1.size)
			newElements[i] = s2.elements[i - s1.size];
	}
	return Set(newElements, newSize);
}

const Set operator+(const Set& s, int element)
{
	int* elements = s.elements;
	int size = s.size;
	int newSize = size + 1;
	int* newElements = new int[newSize];
	for (int i = 0; i < size; i++)
		newElements[i] = elements[i];
	newElements[size] = element;
	return Set(newElements, newSize);
}

const Set operator-(const Set& s1, const Set& s2)
{
	int newSize = s1.size;
	int* newElements = new int[newSize];
	int ind = 0;
	for (int i = 0; i < newSize; i++)
	{
		if (!s2.has(s1.elements[ind]))
			newElements[i] = s1.elements[ind];
		else
		{
			newElements = resizeArr(newElements, newSize, --newSize);
			i--;
		}
		ind++;
	}
	return Set(newElements, newSize);
}

const Set operator-(const Set& s, int element)
{
	if (!s.has(element))
		exit(0);
	int* elements = s.elements;
	int size = s.size;
	int newSize = size - 1;
	int* newElements = new int[newSize];
	int  ind = 0;
	for (int i = 0; i < size; i++)
	{
		if (elements[ind] == element)
			i--;
		else
			newElements[i] = elements[ind];
		ind++;
	}
	return Set(newElements, newSize);
}

const Set operator*(const Set& s1, const Set& s2)
{
	Set minSet, maxSet;
	minSet = s1.size < s2.size ? s1 : s2;
	maxSet = s1.size < s2.size ? s2 : s1;
	int newSize = minSet.size;
	int* newElements = new int[newSize];
	int ind = 0;
	for (int i = 0; i < newSize; i++)
	{
		int element = minSet.elements[ind];
		if (maxSet.has(element))
			newElements[i] = element;
		else
		{
			newElements = resizeArr(newElements, newSize, --newSize);
			i--;
		}
		ind++;
	}
	return Set(newElements, newSize);
}

bool operator==(const Set& s1, const Set& s2)
{
	if (s1.size != s2.size)
		return false;
	else
	{
		for (int i = 0; i < s1.size; i++)
		{
			if (s1.elements[i] != s2.elements[i])
				return false;
		}
	}
	return true;
}

ostream& operator<<(ostream& output, const Set& s)
{
	output << "{ ";
	for (int i = 0; i < s.size; i++)
		output << s.elements[i] << " ";
	output << "}";
	return output;
}

int main()
{
	cout << "Test:" << endl;
	int sizeA = 5;
	int sizeB = 5;
	Set A(new int[sizeA] {3, 8, 46, 5, 11}, sizeA);
	Set B(new int[sizeB] {18, 8, 90, 11, 2}, sizeB);
	Set C;
	cout << "A = " << A << endl;
	cout << "B = " << B << endl;
	A += 4;
	cout << " A + 4 = " << A << endl;
	A -= 4;
	cout << " A - 4 = " << A << endl;
	A += 3;
	cout << " A + 3 = " << A << endl;
	cout << " A == B is ";
	if (A == B)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	C = A;
	cout << "C = " << C << endl;
	cout << " A == C is ";
	if (A == C)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << " A + B = " << A + B << endl;
	cout << " A - B = " << A - B << endl;
	cout << " A * B = " << A * B << endl;
	return 0;
}