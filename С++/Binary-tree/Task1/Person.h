#pragma once
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person
{
	string surname;
	string name;
	string middlename;
	string phoneNumber;
public:
	Person(string surname, string name, string middlename, string phoneNumber);
	Person() : Person("", "", "", "") { }
	void print();
	void changeData();
	string getPhoneNumber();
	string getSurname();
	void writeToFile(const char* name);
	friend bool operator> (const Person& p1, const Person& p2);
	friend bool operator< (const Person& p1, const Person& p2);
	friend bool operator== (const Person& p1, const Person& p2);
};

