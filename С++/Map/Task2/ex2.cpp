#include "Vocabulary.h"
#include "windows.h"
using std::cin;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Vocabulary EngRusVoc;
	int choice, cont;
	do
	{
		do
		{
			cout << "¬ведите номер действи€:" << endl
				<< "1 - добавить слово в словарь" << endl
				<< "2 - удалить слово" << endl
				<< "3 - редактировать слово" << endl
				<< "4 - вывести на экран все слова" << endl
				<< "5 - вывести слово" << endl
				<< "6 - запись из файла" << endl
				<< "7 - запись в файл" << endl;
			cin >> choice;
			system("cls");
		} while (choice < 1 || choice > 7);
		switch (choice)
		{
			case 1: 
			{
				string word, mean;
				cout << "¬ведите слово на руссоком: ";
				cin.ignore();
				getline(cin, word);
				cout << "¬ведите перевод: ";
				getline(cin, mean);
				EngRusVoc.addWord(word, mean);
				system("cls");
				cout << "—лово добавлено!" << endl;
			}
			break;
			case 2: 
			{
				string word;
				cout << "¬ведите слово, которое нужно удалить: ";
				cin.ignore();
				getline(cin, word);
				EngRusVoc.removeWord(word);
			}
			break;
			case 3:
			{
				string word;
				cout << "¬ведите слово, которое нужно изменить: ";
				cin.ignore();
				getline(cin, word);
				EngRusVoc.editWord(word);
			}
			break;
			case 4:EngRusVoc.printAll();break;
			case 5:
			{
				string word;
				cout << "¬ведите слово, которое нужно вывести на экран: ";
				cin.ignore();
				getline(cin, word);
				EngRusVoc.printWord(word);
			}
			break;
			case 6:
			{
				string fname;
				cout << "¬ведите им€ файла(test.txt дл€ теста): ";
				cin.ignore();
				getline(cin, fname);
				EngRusVoc.readFromFile(fname.c_str());
				system("cls");
				cout << "—лова из файла записаны в словарь." << endl;
			}
			break;
			case 7:
			{
				string fname;
				cout << "¬ведите им€ файла(test_w.txt дл€ теста): ";
				cin.ignore();
				getline(cin, fname);
				EngRusVoc.writeToFile(fname.c_str());
				system("cls");
				cout << "—лова записаны в файл" << endl;
			}
			break;
		}
		cout << endl << "¬ведите 1, чтобы продолжить: ";
		cin >> cont;
		system("cls");
	} while (cont == 1);
	return 0;
}