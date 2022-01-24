#pragma once
#include "Letter.h" 
using std::cout;
using std::endl;

class Application
{
public:
	virtual void printNotification(Letter* letter) = 0;
};

