#include <iostream>
#include "Person.h"
#include "Phonebook.h"

using namespace std;

Person* createPerson()
{
	string surname, name, middlename, phoneNumber;
	cout << "Surname: ";
	cin.ignore();
	getline(cin, surname);
	cout << "Name: ";
	getline(cin, name);
	cout << "Middlename: ";
	getline(cin, middlename);
	cout << "Phone number: ";
	getline(cin, phoneNumber);
	return new Person(surname, name, middlename, phoneNumber);
}

int main()
{
	setlocale(0, "");
	Phonebook phonebook;
	int choice, cont;
	do
	{
		do
		{
			cout << "Enter action number:" << endl
				<< "1 - add person" << endl
				<< "2 - remove person " << endl
				<< "3 - change a person's data" << endl
				<< "4 - search" << endl
				<< "5 - print" << endl
				<< "6 - saving the database in a file." << endl;
			cin >> choice;
			system("cls");
		} while (choice < 1 && choice > 6);

		switch (choice)
		{
			case 1:
			{
				Person* person = createPerson();
				system("cls");
				phonebook.addPerson(person);
				cout << "Person added!" << endl;
			}
			break;
			case 2:
			{
				Person* person = createPerson();
				system("cls");
				phonebook.removePerson(person);
				cout << "Person removed!" << endl;
			}
			break;
			case 3:
			{
				cout << "Enter the person you want to change: " << endl;
				Person* person = createPerson();
				system("cls");
				phonebook.changePerson(person);
				cout << "Person changed!" << endl;
			}
			break;
			case 4: phonebook.search(); break;
			case 5: phonebook.print(); break;
			case 6:
			{
				char fname[256];
				cout << "Enter file name: ";
				cin.getline(fname, 256);
				phonebook.writeToFile(fname);
			}
			break;
		}

		cout << "Enter 1 to continue: ";
		cin >> cont;
		system("cls");
	} while (cont == 1);
	return 0;
}