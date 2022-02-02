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
		cout << "Введите строку, которую нужно записать в файл:" << endl;
		getline(cin, str);
		fout << str << endl;
		cout << "Чтобы продолжить запись с  новой строки введите 1" << endl
			<< "или любую другую цифру, чтобы закончить" << endl;
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
		cout << "Файл не открыт!" << endl;
	}
	else
	{
		string str;
		cout << "Содержимое файла " << name << ":" << endl;
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

string changeWordInString(string str, string word, string change_word)
{
	string changed_string = str;
	int pos = 0;
	int ind = 0;
	while ((pos = changed_string.find(word, pos)) != string::npos)
	{
		ind = pos;
		pos++;
		changed_string = changed_string.substr(0, ind - 1) + change_word + changed_string.substr(ind + word.length());
	}
	return changed_string;
}

void copyFile(const char* name, const char* copy_name)
{
	ifstream fin(name);
	ofstream fout(copy_name);
	string str;
	if (!fin.is_open())
		cout << "Не удалось открыть файл" << name << endl;
	else if (!fout.is_open())
		cout << "Не удалось открыть файл" << copy_name << endl;
	while (getline(fin, str))
	{
		fout << str << endl;
	}
	fin.close();
	fout.close();
}

void changeWordInFile(const char* name, string word, string change_word)
{
	ifstream fin(name);
	ofstream fout("temp.txt");
	string str;
	while (getline(fin, str))
	{
		fout << changeWordInString(str, word, change_word) << endl;
	}
	fin.close();
	fout.close();
	copyFile("temp.txt", name);
}

int main()
{
	setlocale(0, "");
	string word;
	string change_word;
	char f[] = "file.txt";
	cout << "Заполните файл " << endl;
	writeToFile(f);
	system("cls");
	readFile(f);
	cout << "Введите слово: ";
	cin.ignore();
	getline(cin, word);
	cout << "Введите слово, на которое нужно заменить предыдущее: ";
	getline(cin, change_word);
	changeWordInFile(f, word, change_word);
	system("cls");
	readFile(f);
	return 0;
}