#include <iostream>
#include <list>
using namespace std;

class Student
{
	string surname;
	string name;
	int course;
public:
	Student(string s, string n, int c) : surname{ s }, name{ n }, course{ c } { } 
	friend ostream& operator<<(ostream& output, const Student& s);
	friend bool compAlphabet(const Student& s1, const Student& s2);
	friend bool compCourses(const Student& s1, const Student& s2);
};

ostream& operator<<(ostream& output, const Student& s)
{
	output << "Surname: " << s.surname << endl;
	output << "Name: " << s.name << endl;
	output << "Course: " << s.course << endl;
	return output;
}

class ListStudents
{
	list <Student> students;
public:
	ListStudents() = default;
	void addStudent(Student st);
	void printAll();
	void sortAlphabet();
	void sortCourses();
};

void ListStudents::addStudent(Student st)
{
	students.push_back(st);
}

void ListStudents::printAll()
{
	list<Student>::iterator iter;
	for (iter = students.begin(); iter != students.end(); iter++)
	{
		cout << *iter;
		cout << "-------------------------------" << endl;
	}
}

bool compAlphabet(const Student& s1, const Student& s2)
{
	string surname1 = s1.surname;
	string surname2 = s2.surname;
	string name1 = s1.name;
	string name2 = s2.name;
	if (surname1 == surname2)
		return name1 < name2;
	else
		return surname1 < surname2;
}

bool compCourses(const Student& s1, const Student& s2)
{
	return s1.course < s2.course;
}

void ListStudents::sortAlphabet()
{
	students.sort(compAlphabet);
}

void ListStudents::sortCourses()
{
	students.sort(compCourses);
}

int main()
{
	ListStudents list;
	Student s1("Ivanov", "Ivan", 3);
	Student s2("Baranov", "Anton", 1);
	Student s3("Kuznetsova", "Maria", 2);
	Student s4("Shevchenko", "Oleg", 3);
	Student s5("Trotsenko", "Irina", 4);
	Student s6("Pinchuk", "Anastasia", 1);
	Student s7("Novikov", "Nikita", 2);
	Student s8("Makarenko", "Vlad", 3);
	Student s9("Paschenko", "Roman", 4);
	Student s10("Senchukov", "Ivan", 2);
	list.addStudent(s1);
	list.addStudent(s2);
	list.addStudent(s3);
	list.addStudent(s4);
	list.addStudent(s5);
	list.addStudent(s6);
	list.addStudent(s7);
	list.addStudent(s8);
	list.addStudent(s9);
	list.addStudent(s10);
	list.printAll();
	cout << endl << "===========================================================" << endl;
	cout << "After sorting alphabetically: " << endl << endl;
	list.sortAlphabet();
	list.printAll();
	cout << endl << "===========================================================" << endl;
	cout << "After sorting courses: " << endl << endl;
	list.sortCourses();
	list.printAll();
	
	return 0;
}