#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeToFile(const char* name)
{
	ofstream fout(name);
	int c;
	string str;
	do
	{
		cout << "������� ������, ������� ����� �������� � ����:" << endl;
	    getline(cin, str);
		fout << str << endl;
		cout << "����� ���������� ������ �  ����� ������ ������� 1" << endl
			<< "��� ����� ������ �����, ����� ���������" << endl;
		cin >> c;
		cout << endl;
		cin.ignore();
	} while (c == 1);
	fout.close();
}

void readFile(const char* name)
{
	ifstream fin(name);
	if (!fin.is_open())
	{
		cout << "���� �� ������!" << endl;
	}
	else
	{
		string str;
		cout << "���������� ����� " << name << ":" << endl;
		cout << "-----------------------------------------------" << endl;
		while (getline(fin, str))
		{
			cout << str << endl;
		}
		cout << "-----------------------------------------------" << endl;
		cout << endl;
	}
	fin.close();
}

int countLines(const char* name)
{
	ifstream fin(name);
	int count = 0;
	string str;
	while (getline(fin, str))
	{
		count++;
	}
	fin.close();
	return count;
}


void removeLastLine(const char* name, const char* new_name)
{
	ifstream fin(name);
	ofstream fout(new_name);
	string str;
	int n = countLines(name);
	int i = 0;
	if (!fin.is_open())
	{
		cout << "���� " << name << " �� ������!" << endl;
	}
	else
	{
		while (getline(fin, str) && i < n - 1)
		{

			fout << str << endl;
			i++;
		}
	}
	fin.close();
	fout.close();
}

int main()
{
	setlocale(0, "");
	char f[] = "file.txt";
	char new_f[] = "new_file.txt";
	cout << "��������� ���� " << endl;
	writeToFile(f);
	system("cls");
	readFile(f);
	removeLastLine(f, new_f);
	readFile(new_f);
	return 0;
}