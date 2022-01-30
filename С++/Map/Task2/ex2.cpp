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
			cout << "������� ����� ��������:" << endl
				<< "1 - �������� ����� � �������" << endl
				<< "2 - ������� �����" << endl
				<< "3 - ������������� �����" << endl
				<< "4 - ������� �� ����� ��� �����" << endl
				<< "5 - ������� �����" << endl
				<< "6 - ������ �� �����" << endl
				<< "7 - ������ � ����" << endl;
			cin >> choice;
			system("cls");
		} while (choice < 1 || choice > 7);
		switch (choice)
		{
			case 1: 
			{
				string word, mean;
				cout << "������� ����� �� ��������: ";
				cin.ignore();
				getline(cin, word);
				cout << "������� �������: ";
				getline(cin, mean);
				EngRusVoc.addWord(word, mean);
				system("cls");
				cout << "����� ���������!" << endl;
			}
			break;
			case 2: 
			{
				string word;
				cout << "������� �����, ������� ����� �������: ";
				cin.ignore();
				getline(cin, word);
				EngRusVoc.removeWord(word);
			}
			break;
			case 3:
			{
				string word;
				cout << "������� �����, ������� ����� ��������: ";
				cin.ignore();
				getline(cin, word);
				EngRusVoc.editWord(word);
			}
			break;
			case 4:EngRusVoc.printAll();break;
			case 5:
			{
				string word;
				cout << "������� �����, ������� ����� ������� �� �����: ";
				cin.ignore();
				getline(cin, word);
				EngRusVoc.printWord(word);
			}
			break;
			case 6:
			{
				string fname;
				cout << "������� ��� �����(test.txt ��� �����): ";
				cin.ignore();
				getline(cin, fname);
				EngRusVoc.readFromFile(fname.c_str());
				system("cls");
				cout << "����� �� ����� �������� � �������." << endl;
			}
			break;
			case 7:
			{
				string fname;
				cout << "������� ��� �����(test_w.txt ��� �����): ";
				cin.ignore();
				getline(cin, fname);
				EngRusVoc.writeToFile(fname.c_str());
				system("cls");
				cout << "����� �������� � ����" << endl;
			}
			break;
		}
		cout << endl << "������� 1, ����� ����������: ";
		cin >> cont;
		system("cls");
	} while (cont == 1);
	return 0;
}