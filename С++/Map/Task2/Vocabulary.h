#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
using std::string;
using std::map;
using std::cout;
using std::endl;

class Vocabulary
{
	map<string, string> vocabulary;
public:
	Vocabulary() = default;
	void addWord(string word, string meaning);
	void editWord(string word);
	void printWord(string word);
	void printAll();
	void removeWord(string word);
	void readFromFile(const char* fname);
	void writeToFile(const char* fname);
};

