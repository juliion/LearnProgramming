#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
	string surname;
	string name;
	string university;
	int averMark;
public:
	Student(string surname, string name, string university, int averMark);
};

Student::Student(string surname, string name, string university, int averMark)
{
	this->surname = surname;
	this->name = name;
	this->university = university;
	this->averMark = averMark;
}

class Aspirant : public Student
{
	string topicPhD;
	bool workIsDefended;
	int markForPhD;
public:
	Aspirant(string surname, string name, string university, int averMark, string topicPhD) : Student(surname, name, university, averMark)
	{
		this->topicPhD = topicPhD;
		workIsDefended = false;
		markForPhD = 0;
	}
	void defendPhDWork();
	void print();
};

void Aspirant::defendPhDWork()
{
	workIsDefended = true;
	cout << "Enter mark for PhD work: ";
	cin >> markForPhD;
}

void Aspirant::print()
{
	cout << "Surname: " << surname << endl;
	cout << "Name: " << name << endl;
	cout << "University: " << university << endl;
	cout << "Average mark: " << averMark << endl;
	cout << "PhD topic: " << topicPhD << endl;
	if (workIsDefended)
	{
		cout << "PhD work is defended" << endl;
		cout << "Mark for PhD work: " << markForPhD << endl;
	}
	else
		cout << "PhD work is not defended" << endl;
}

int main()
{
	string surname, name, university, topicPhD;
	int averMark;
	cout << "Enter information about aspirant: " << endl;
	cout << "Surname: ";
	getline(cin, surname);
	cout << "Name: ";
	getline(cin, name);
	cout << "University: ";
	getline(cin, university);
	cout << "Average mark: ";
	cin >> averMark;
	cout << "PhD topic: ";
	cin.ignore();
	getline(cin, topicPhD);
	system("cls");
	Aspirant a(surname, name, university, averMark, topicPhD);
	a.print();
	cout << "Press any key to defend the PhD work: " << endl;
	system("pause");
	system("cls");
	a.defendPhDWork();
	system("cls");
	a.print();
	return 0;
}