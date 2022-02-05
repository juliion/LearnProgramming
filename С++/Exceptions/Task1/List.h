#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	int value;
	Node* next;
	Node* prev;
	Node(int val) : value{ val }, next{ nullptr }, prev{ nullptr } { }
};

class List
{
	int size;
	Node* head;
	Node* tail;
public:
	List();
	void push_back(int value);
	void push_front(int value);
	void pop();
	void insert(int pos, int value);
	void print(int pos);
	void print();
	~List();
};

