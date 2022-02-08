#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	int value;
	Node* next;
	Node(int val) : value{ val }, next{ nullptr } { }
};
class List
{
protected:
	int size;
	Node* head;
	Node* tail;
	List();
public:
	virtual void push(int value) = 0;
	virtual void pop() = 0;
	void print();
};

