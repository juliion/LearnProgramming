#pragma once
#include <list>
#include "Offense.h"

class Node
{
public:
	Node(string carNum) : carNumber{ carNum }, right{ nullptr }, left{ nullptr } { }
	string carNumber;
	list <Offense> offenses;
	Node* right;
	Node* left;
	void print();
};

class Tree
{
	Node* root;
	void addNode(Node** node, string carNumber, Offense offense);
	Node* search(string carNumber);
	void print(Node* node);
	void printRange(Node* node, string start, string end);
public:
	Tree() : root{ nullptr } { }
	void addOffense(string carNumber, Offense offense);
	void printAll();
	void printOne(string carNumber);
	void printRangeNumber(string start, string end);
	 
};

