#include <iostream>
#include <cmath>
#include <fstream>
#include "FileExceptions.h"
#include "MemoryExceptions.h"
#include "MathematicalExceptions.h"
using namespace std;

int main()
{
	//test
	try
	{
		/*int a = 2;
		int b = 0;
		if (b == 0)
			throw DivisionByZero();
		cout << a/b << endl;*/

		/*int a = -2;
		if (a < 0)
			throw RootOfNegNum();
		cout << sqrt(a) << endl;*/

		/*int a = -2;
		if (a < 0)
			throw WrongLogArg();
		cout << log(a) << endl;*/

		/*int size = 3;
		int* array = new int[size];
		int ind = 5;
		if (ind >= size || ind < 0)
			throw ArrayOverflow();
		array[ind] = 10;*/

		/*int size = 3;
		int* array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = i + 1;
		for (int j = 0; j < 10; j++)
		{
			if (j >= size)
				throw OutOfBounds();
				cout << array[j] << endl;
		}*/

		ifstream file("test.txt");
		if (!file.is_open())
			throw OpenFile();
		cout << "File is open" << endl;
	}
	catch (Exception& e)
	{
		e.print();
	}
	return 0;
}