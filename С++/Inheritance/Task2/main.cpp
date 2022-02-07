#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date
{
	int year;
	int mounth;
	int day;
public:
	Date(int year, int mounth, int day);
	void print();
};

Date::Date(int year, int mounth, int day)
{
	this->year = year;
	this->mounth = mounth;
	this->day = day;
}

void Date::print()
{
	if (day < 10)
		cout << 0 << day;
	else
		cout << day;
	cout << ".";
	if (mounth < 10)
		cout << 0 << mounth;
	else
		cout << mounth;
	cout << "." << year;
}

class Passport
{
protected:
	string surname;
	string name;
	string middlename;
	string nationality;
	string sex;
	Date* dateOfBirth;
public:
	Passport(string surname, string name, string middlename, string nationality, string sex, Date* dateOfBirth);
	void print();
};

Passport::Passport(string surname, string name, string middlename, string nationality, string sex, Date* dateOfBirth)
{
	this->surname = surname;
	this->name = name;
	this->middlename = middlename;
	this->nationality = nationality;
	this->sex = sex;
	this->dateOfBirth = dateOfBirth;
}

void Passport::print()
{
	cout << "Surname: " << surname << endl;
	cout << "Name: " << name << endl;
	cout << "Middlename: " << middlename << endl;
	cout << "Nationality: " << nationality << endl;
	cout << "Sex: " << sex << endl;
	cout << "Date of birth: ";
	dateOfBirth->print();
	cout << endl;
}

class ForeignPassport : public Passport
{
	string id;
	vector <string> visas;
public:
	ForeignPassport(string surname, string name, string middlename, string nationality, string sex, Date* dateOfBirth, string id) : Passport(surname, name, middlename, nationality, sex, dateOfBirth)
	{
		this->id = id;
	}
	void addVisa();
	void print();
};

void ForeignPassport::addVisa()
{
	string visa;
	cout << "Enter data about visa : ";
	cin.ignore();
	getline(cin, visa);
	visas.push_back(visa);
}

void ForeignPassport::print()
{
	cout << "Surname: " << surname << endl;
	cout << "Name: " << name << endl;
	cout << "Middlename: " << middlename << endl;
	cout << "Nationality: " << nationality << endl;
	cout << "Sex: " << sex << endl;
	cout << "Date of birth: ";
	dateOfBirth->print();
	cout << endl;
	cout << "Id: " << id << endl;
	cout << "Data about available visas:" << endl;
	if (visas.size() == 0)
		cout << "No data!" << endl;
	else
	{
		for (int i = 0; i < visas.size(); i++)
			cout << visas[i] << endl;
	}
}

int main()
{
	string surname, name, middlename, nationality, sex, id;
	int year, mounth, day;
	cout << "Enter information about person: " << endl;
	cout << "Surname: ";
	getline(cin, surname);
	cout << "Name: ";
	getline(cin, name);
	cout << "Middlename: ";
	getline(cin, middlename);
	cout << "Nationality: ";
	getline(cin, nationality);
	cout << "Sex: ";
	getline(cin, sex);
	cout << "Date of birth: " << endl;
	cout << "year: ";
	cin >> year;
	cout << "mounth: ";
	cin >> mounth;
	cout << "day: ";
	cin >> day;
	cout << "id foreign passport: ";
	cin.ignore();
	getline(cin, id);
	system("cls");

	Passport passport(surname, name, middlename, nationality, sex, new Date(year, mounth, day));
	ForeignPassport foreignPassport(surname, name, middlename, nationality, sex, new Date(year, mounth, day), id);
	int choice, cont;
	do
	{
		do
		{
			cout << "Enter action number:" << endl
				<< "1 - print passpor" << endl
				<< "2 - print foreign passport" << endl
				<< "3 - add data about visa" << endl;
			cin >> choice;
			system("cls");
		} while (choice < 1 && choice > 3);
		switch (choice)
		{
			case 1: passport.print(); break;
			case 2: foreignPassport.print(); break;
			case 3: foreignPassport.addVisa(); break;
		}
		cout << endl << "Enter 1 to continue: ";
		cin >> cont;
		system("cls");
	} while (cont == 1);
	return 0;
}