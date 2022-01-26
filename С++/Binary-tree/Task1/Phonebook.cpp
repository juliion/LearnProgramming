#include "Phonebook.h"

Phonebook::Phonebook()
{
	treeAlphabet = new Tree(alphabet);
	treePhNumbers = new Tree(phNumber);
}

void Phonebook::addPerson(Person* person)
{
	treeAlphabet->addNode(person);
	treePhNumbers->addNode(person);
}

void Phonebook::removePerson(Person* person)
{
	if (treeAlphabet->search(person->getSurname()) == nullptr)
		cout << "No such person!" << endl;
	else
	{
		treeAlphabet->removeNode(person);
		treePhNumbers->removeNode(person);
	}
}

void Phonebook::changePerson(Person* person)
{
	if (treeAlphabet->search(person->getSurname()) == nullptr)
		cout << "No such person!" << endl;
	else
	{
		treeAlphabet->removeNode(person);
		treePhNumbers->removeNode(person);
		person->changeData();
		treeAlphabet->addNode(person);
		treePhNumbers->addNode(person);
	}
}

void Phonebook::search()
{
	int choice;
	string str;
	do
	{
		cout << "Enter search way: " << endl
			<< "1 - with surname" << endl
			<< "2 - with phone number" << endl;
		cin >> choice;
		system("cls");
	} while (choice != 1 && choice != 2);
	switch(choice)
	{
		case 1: 
		{
			cout << "Enter surname: ";
			cin.ignore();
			getline(cin, str);
			system("cls");
			Person* foundPerson = treeAlphabet->search(str);
			if (foundPerson == nullptr)
				cout << "Nothing found!" << endl;
			else
			{
				cout << "Found person:" << endl;
				foundPerson->print();
			}
		}
		break;
		case 2:
		{
			cout << "Enter phone number: ";
			cin.ignore();
			getline(cin, str);
			system("cls");
			Person* foundPerson = treePhNumbers->search(str);
			if (foundPerson == nullptr)
				cout << "Nothing found!" << endl;
			else
			{
				cout << "Found person:" << endl;
				foundPerson->print();
			}
		}
		break;
	}
}

void Phonebook::print()
{
	int choice;
	string str1, str2;
	do
	{
		cout << "Enter choice:" << endl
			<< "1 - print all alphabetically" << endl
			<< "2 - print with surnames range" << endl
			<< "3 - print with phone numbers range" << endl;
		cin >> choice;
		system("cls");
	} while (choice > 3 && choice < 1);
	switch (choice)
	{
		case 1: treeAlphabet->printAll(); break;
		case 2: 
		{
			string surnameStart, surnameEnd;
			cout << "Enter start surname: ";
			cin.ignore();
			getline(cin, surnameStart);
			cout << "Enter end surname: ";
			getline(cin, surnameEnd);
			treeAlphabet->printRange(surnameStart, surnameEnd);
		}
		break;
		case 3:
		{
			string phNumStart, phNumEnd;
			cout << "Enter start phone number: ";
			cin.ignore();
			getline(cin, phNumStart);
			cout << "Enter end phone number: ";
			getline(cin, phNumEnd);
			treePhNumbers->printRange(phNumStart, phNumEnd);
		}
		break;
	}
}

void Phonebook::writeToFile(const char* name)
{
	treeAlphabet->writeToFile(name);
}