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
int maxLengthLine(const char* name)
{
	ifstream fin(name);
	int maxLength = 0;
	string str;
	while (getline(fin, str))
	{
		maxLength = str.length() > maxLength ? str.length() : maxLength;
	}
	fin.close();
	return maxLength;
}

int main()
{
	setlocale(0, "");
	char f[] = "file.txt";
	cout << "��������� ���� " << endl;
	writeToFile(f);
	system("cls");
	readFile(f);
	cout << "����� ����� ������� ������: " << maxLengthLine(f) << endl;
	return 0;
}