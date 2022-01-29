#include <iostream>
#include <string>
using namespace std;

struct book
{
	string title;
	string author;
	string publish;
	string genre;
};

void printBook(book b)
{
	cout << "��������: " << "\"" << b.title << "\"" << endl;
	cout << "�����: " << b.author << endl;
	cout << "������������: " << b.publish << endl;
	cout << "����: " << b.genre << endl;
}

void printLibrary(book* library, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "-------------����� #" << (i + 1) << "-------------" << endl;
		printBook(library[i]);
		cout << endl;
	}
}

void editBook(int i, book* library, int n)
{
	book* changeBook = &library[i];
	int ch;
	do
	{
		cout << "�������, ��� �� ������ ��������:" << endl
			<< "1 - ��������" << endl
			<< "2 - �����" << endl
			<< "3 - ������������" << endl
			<< "4 - ����" << endl;
		cin >> ch;
		system("cls");
	} while (ch < 1 || ch > 4);
	switch (ch)
	{
	case 1:
	{
		cout << "������� ����� ���������: ";
		cin.ignore();
		getline(cin, changeBook->title);
	}
	break;
	case 2:
	{
		cout << "������� ������ ������: ";
		cin.ignore();
		getline(cin, changeBook->author);
	}
	break;
	case 3:
	{
		cout << "������� ����� ������������: ";
		cin.ignore();
		getline(cin, changeBook->publish);
	}
	break;
	case 4:
	{
		cout << "������� ����� ����: ";
		cin.ignore();
		getline(cin, changeBook->genre);
	}
	break;
	}
}

void searchByAuthor(book* library, int n, string search_author)
{
	int c = 0;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (library[i].author == search_author)
		{
			cout << "-------------����� #" << (i + 1) << "-------------" << endl;
			printBook(library[i]);
			c++;
		}
	}
	if (c == 0)
		cout << "�� �������!" << endl;
	cout << endl;
}

void sortByTitle(book* library, int n)
{
	book temp;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (library[j].title > library[j + 1].title)
			{
				temp = library[j];
				library[j] = library[j + 1];
				library[j + 1] = temp;
			}
		}
	}
}

void sortByAuthor(book* library, int n)
{
	book temp;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (library[j].author > library[j + 1].author)
			{
				temp = library[j];
				library[j] = library[j + 1];
				library[j + 1] = temp;
			}
		}
	}
}

void sortByPublish(book* library, int n)
{
	book temp;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (library[j].publish > library[j + 1].publish)
			{
				temp = library[j];
				library[j] = library[j + 1];
				library[j + 1] = temp;
			}
		}
	}
}

void searchByTitle(book* library, int n, string search_title)
{
	int c = 0;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (library[i].title == search_title)
		{
			cout << "-------------����� #" << (i + 1) << "-------------" << endl;
			printBook(library[i]);
			c++;
		}
	}
	if (c == 0)
		cout << "�� �������!" << endl;
	cout << endl;
}



int main()
{
	setlocale(0, "");
	int n = 10;
	book* library = new book[n];

	library[0].title = "Harry Potter";
	library[0].author = "J. K. Rowling";
	library[0].publish = "Bloomsbury Children's";
	library[0].genre = "Fantasy";

	library[1].title = "Lord of the Rings";
	library[1].author = "J.R.R. Tolkien";
	library[1].publish = "HarperCollins";
	library[1].genre = "Fantasy";

	library[2].title = "And Then There Were None";
	library[2].author = "Agatha Christie";
	library[2].publish = "HarperCollins";
	library[2].genre = "Detective";

	library[3].title = "Pride and Prejudice";
	library[3].author = "Jane Austen";
	library[3].publish = "Wordsworth";
	library[3].genre = "Romance novel";

	library[4].title = "The Picture of Dorian Gray";
	library[4].author = "Oscar Wilde";
	library[4].publish = "Wordsworth";
	library[4].genre = "Philosophical novel";

	library[5].title = "Jane Eyre";
	library[5].author = "Charlotte Bronte";
	library[5].publish = "Wordsworth";
	library[5].genre = "Novel";

	library[6].title = "Lolita";
	library[6].author = "Vladimir Nabokov";
	library[6].publish = "Penguin Classics";
	library[6].genre = "Novel";

	library[7].title = "The Catcher in the Rye";
	library[7].author = "J. D. Salinger";
	library[7].publish = "Penguine";
	library[7].genre = "Novel";

	library[8].title = "The Great Gatsby";
	library[8].author = "F. S. Fitzgerald";
	library[8].publish = "Vintage";
	library[8].genre = "Novel";

	library[9].title = "Lord of the Flies";
	library[9].author = "William Golding";
	library[9].publish = "Anthology";
	library[9].genre = "Novel";

	int act;
	do
	{
		cout << "�������: " << endl
			<< "1 - �������� ��� �����" << endl
			<< "2 - ����� ������������� �����" << endl
			<< "3 - ����� ����� �� ������" << endl
			<< "4 - ����� ����� �� ��������" << endl
			<< "5 - ����������  �� �������� ����" << endl
			<< "6 - ����������  �� ������" << endl
			<< "7 - ����������  �� ������������" << endl
			<< "����� ���� �����, ����� ���������" << endl << endl;
		cin >> act;
		system("cls");
		switch (act)
		{
		case 1:
			printLibrary(library, n);
			break;
		case 2:
		{
			int i;
			int cont;
			do
			{
				cout << "������� ����� ����� � ������(1-10) : ";
				cin >> i;
				editBook(i - 1, library, n);
				cout << "����� ��������!" << endl;
				cout << "��� �� ���������� ��������� ������� 1" << endl
					<< "����� ������ �����, ����� �����" << endl;
				cin >> cont;
				system("cls");
			} while (cont == 1);
		}
		break;
		case 3:
		{
			string a;
			cout << "������� ������ ��� ������: ";
			cin.ignore();
			getline(cin, a);
			searchByAuthor(library, n, a);
		}
		break;
		case 4:
		{
			string t;
			cout << "������� �������� ��� ������: ";
			cin.ignore();
			getline(cin, t);
			searchByTitle(library, n, t);
		}
		break;
		case 5:
		{
			cout << "�������������� �����: " << endl << endl;
			sortByTitle(library, n);
			printLibrary(library, n);
		}
		break;
		case 6:
		{
			cout << "�������������� �����: " << endl << endl;
			sortByAuthor(library, n);
			printLibrary(library, n);
		}
		break;
		case 7:
		{
			cout << "�������������� �����: " << endl << endl;
			sortByPublish(library, n);
			printLibrary(library, n);
		}
		break;
		default:
			cout << "������� ������������ ��������!";
		}
	} while (act >= 1 && act <= 7);
	return 0;
}