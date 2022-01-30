#include "Vocabulary.h"

void Vocabulary::addWord(string word, string meaning)
{
	vocabulary[word] = meaning;
}

void Vocabulary::editWord(string word)
{
	map<string, string>::iterator findW = vocabulary.find(word);
	if(findW == vocabulary.end())
		cout << "Такого слова нету в словаре!" << endl;
	else
	{
		string newWord, newMeaning;
		vocabulary.erase(findW);
		cout << "Введите новое слово: ";
		getline(std::cin, newWord);
		cout << "Введите новый перевод слова: ";
		getline(std::cin, newMeaning);
		addWord(newWord, newMeaning);
		system("cls");
		cout << "Слово изменено!" << endl;
	}
}

void Vocabulary::printWord(string word)
{
	map<string, string>::iterator findW = vocabulary.find(word);
	if (findW == vocabulary.end())
		cout << "Такого слова нету в словаре!" << endl;
	else
		cout << findW->first << " - " << findW->second << endl;
}

void Vocabulary::printAll()
{
	map<string, string>::iterator it = vocabulary.begin();
	cout << "--------------------------------------------------" << endl;
	for (int i = 0; it != vocabulary.end(); it++, i++)
		cout << it->first << " - " << it->second << endl;
	if (it == vocabulary.end())
		cout << "Словарь пуст!" << endl;
	cout << "--------------------------------------------------" << endl;
}

void Vocabulary::removeWord(string word)
{
	map<string, string>::iterator findW = vocabulary.find(word);
	if (findW == vocabulary.end())
		cout << "Такого слова нету в словаре!" << endl;
	else
	{
		vocabulary.erase(findW);
		system("cls");
		cout << "Слово удалено!";
	}
}

void Vocabulary::readFromFile(const char* fname)
{
	std::ifstream file(fname);
	string str;
	if (!file.is_open())
		throw "could not open file";
	while (!file.eof())
	{
		std::getline(file, str);
		int ind = str.find("-");
		if (ind != string::npos)
			addWord(str.substr(0, ind - 1), str.substr(ind + 1));
	}
	file.close();
}

void Vocabulary::writeToFile(const char* fname)
{
	std::ofstream file(fname);
	if (!file.is_open())
		throw "could not open file";
	map<string, string>::iterator it = vocabulary.begin();
	file << "---------------------------------------------" << endl;
	for (int i = 0; it != vocabulary.end(); it++, i++)
		file << it->first << " - " << it->second << endl;
	if (it == vocabulary.end())
		file << "Словарь пуст!" << endl;
	file << "---------------------------------------------" << endl;
	file.close();
}