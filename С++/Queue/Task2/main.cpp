#include <iostream>
#include "Person.h"
#include "Date.h"
#include "PrintQueue.h"
using namespace std;

enum Priority
{
	small,
	average,
	high
};

int main()
{
	//test
	PrintQueue printQ;
	Person p1("Ivan", high, new Date(2021, 6, 18, 15, 48));
	Person p2("Alex", small, new Date(2021, 6, 18, 15, 20));
	Person p3("Maria", average, new Date(2021, 6, 18, 15, 40));
	Person p4("Alisa", high, new Date(2021, 6, 18, 14, 47));
	Person p5("Ivan", high, new Date(2021, 6, 18, 13, 40));
	Person p6("Maria", average, new Date(2021, 6, 18, 14, 40));
	printQ.push(p1);
	printQ.push(p2);
	printQ.push(p3);
	printQ.push(p4);
	printQ.push(p5);
	printQ.push(p6);
	printQ.printStatistics();
	printQ.pop();
	cout << "After pop():" << endl;
	printQ.printStatistics();
	return 0;
}