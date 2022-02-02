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
	cout << "Заполните файл " << endl;
	writeToFile(f);
	system("cls");
	readFile(f);
	cout << "Введите слово: ";
	cin.ignore();
	getline(cin, word);
	cout << "Количество слова в файле: " << countWordInFile(f, word) << endl;
	return 0;
}