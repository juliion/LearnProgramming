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
	cout << "Заполните файл " << endl;
	writeToFile(f);
	system("cls");
	readFile(f);
	cout << "Длина самой длинной строки: " << maxLengthLine(f) << endl;
	return 0;
}