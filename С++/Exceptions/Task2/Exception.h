#pragma once
#include <iostream>
using namespace std;

class Exception
{
protected:
	string eType;
	string eMessage;
public:
	Exception(string errorType, string errorMessage) : eType{ errorType }, eMessage{ errorMessage } { }
	void print()
	{ 
		cout << eType << ": " << eMessage << endl;
	}
};

