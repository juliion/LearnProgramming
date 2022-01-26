#include "Person.h"

Person::Person(string surname, string name, string middlename, string phoneNumber)
{
	this->surname = surname;
	this->name = name;
	this->middlename = middlename;
	this->phoneNumber = phoneNumber;
}

void Person::print()
{
	cout << "Surname: " << surname << endl;
	cout << "Name: " << name << endl;
	cout << "Middlename: " << middlename << endl;
	cout << "Phone number: " << phoneNumber << endl;
}

void Person::changeData()
{
	cout << "Enter new surname: ";
	getline(cin, surname);
	cout << "Enter new name: ";
	getline(cin, name);
	cout << "Enter new middlename: ";
	getline(cin, middlename);
	cout << "Enter new phone number: ";
	getline(cin, phoneNumber);
}

string Person::getPhoneNumber()
{
	return phoneNumber;
}

string Person::getSurname()
{
	return surname;
}

void Person::writeToFile(const char* name)
{
	ofstream fout(name, ios::app);
	fout << "Surname: " << surname << endl;
	fout << "Name: " << this->name << endl;
	fout << "Middlename: " << middlename << endl;
	fout << "Phone number: " << phoneNumber << endl;
	fout.close();
}

bool operator> (const Person& p1, const Person& p2)
{
	if (p1.surname != p2.surname)
		return p1.surname > p2.surname;
	else if (p1.name != p2.name)
		return p1.name > p2.name;
	else if (p1.middlename != p2.middlename)
		return p1.middlename > p2.middlename;
	else if (p1.phoneNumber != p2.phoneNumber)
		return p1.phoneNumber > p2.phoneNumber;
	return false;
}

bool operator< (const Person& p1, const Person& p2)
{
	return p2 > p1;
}

bool operator== (const Person& p1, const Person& p2)
{
	return(p1.name == p2.name && p1.surname == p2.surname
		&& p1.middlename == p2.middlename && p1.phoneNumber == p2.phoneNumber);
}