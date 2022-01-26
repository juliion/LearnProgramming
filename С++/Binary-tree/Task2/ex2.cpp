#include <iostream>
#include <string>
#include "Tree.h"
using namespace std;

Date* createDate()
{
	int year, mounth, day, hours, minutes;
	cout << "yeer: ";
	cin >> year;
	cout << "mounth: ";
	cin >> mounth;
	cout << "day: ";
	cin >> day;
	cout << "hours: ";
	cin >> hours;
	cout << "minutes: ";
	cin >> minutes;
	system("cls");
	return new Date(year, mounth, day, hours, minutes);
}

Offense* createOffense()
{
	string type, cost;
	cout << "Enter date: " << endl;
	Date* date = createDate();
	cout << "Eter type of offense: ";
	cin.ignore();
	getline(cin, type);
	cout << "Eter cost of the fine: ";
	getline(cin, cost);
	system("cls");
	return new Offense(date, type, cost);
}


int main()
{
	Tree t;
	int choice, cont;
	do
	{
		do
		{
			cout << "Enter action number:" << endl
				<< "1 - add offense" << endl
				<< "2 - print all offenses" << endl
				<< "3 - print offenses related to the car number" << endl
				<< "4 - print with car numbers range" << endl;
			cin >> choice;
			system("cls");
		} while (choice < 1 && choice > 4);
		switch (choice)
		{
			case 1:
			{
				string carNum;
				cout << "Enter car number: ";
				cin.ignore();
				getline(cin, carNum);
				Offense* o = createOffense();
				t.addOffense(carNum, *o);
				cout << "Offense added!" << endl;
			}
			break;
			case 2: t.printAll(); break;
			case 3:
			{
				string carNum;
				cout << "Enter car number: ";
				cin.ignore();
				getline(cin, carNum);
				system("cls");
				cout << "Offenses related to this car number: " << endl << endl;
				t.printOne(carNum);
				cout << endl;
			}
			break;
			case 4:
			{
				string carNumStart, carNumEnd;
				cout << "Enter start car number: ";
				cin.ignore();
				getline(cin, carNumStart);
				cout << "Enter end car number: ";
				getline(cin, carNumEnd);
				system("cls");
				t.printRangeNumber(carNumStart, carNumEnd);
			}
			break;

		}
		cout << "Enter 1 to continue: ";
		cin >> cont;
		system("cls");
	} while (cont == 1);
	return 0;
}