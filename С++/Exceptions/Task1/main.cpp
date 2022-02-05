#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	//test
	List l;
	try
	{
		//l.pop();
		for (int i = 0; i < 10; i++)
			l.push_back(i);
		l.print();
		l.insert(1, -1);
		l.print();
		l.print(1);
		l.pop();
		l.print();
		//l.print(-5);
		//l.insert(20, 10);
	}
	catch (const char* error)
	{
		cout << "Error: " << error;
	}
	return 0;
}