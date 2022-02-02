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

int countWordInString(string str, string word)
{
	int count = 0;
	int pos = 0;

	while ((pos = str.find(word, pos)) != string::npos)
	{
		count++;
		pos++;
	}
	return count;
}

int countWordInFile(const char* name, string word)
{
	ifstream fin(name);
	int count = 0;
	string str;
	while (getline(fin, str))
	{
		count += countWordInString(str, word);
	}
	fin.close();
	return count;
}

int main()
{
	setlocale(0, "");
	string word;
	char f[] = "file.txt";
	cout << "��������� ���� " << endl;
	writeToFile(f);
	system("cls");
	readFile(f);
	cout << "������� �����: ";
	cin.ignore();
	getline(cin, word);
	cout << "���������� ����� � �����: " << countWordInFile(f, word) << endl;
	return 0;
}