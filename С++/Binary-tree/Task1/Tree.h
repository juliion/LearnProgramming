#pragma once
#include "Person.h"

enum sortingWay
{
	alphabet,
	phNumber
};

class Node
{
public:
	Node(Person* p) : person{ p }, right{ nullptr }, left{ nullptr } { }
	Person* person;
	Node* right;
	Node* left;
};

class Tree
{
	Node* root;
	int sortingWay;
	void makeNode(Node** node, Person* person);
	void deleteNode(Node** node, Person* person);
	void print(Node* node);
	void printRange(Node* node, string start, string end);
	void writeToFile(Node* node, const char* name);

public: 
	Tree(int way) : root{ nullptr }, sortingWay{ way } { }
	void addNode(Person* person);
	void removeNode(Person* person);
	Person* search(string str);
	void printAll();
	void printRange(string start, string end);
	void writeToFile(const char* name);
};

