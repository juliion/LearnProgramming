#include "Stack.h"

void Stack::push(int value) 
{
	Node* node = new Node(value);
	if (size == 0)
	{
		head = node;
		tail = node;
	}
	else
	{
		node->next = head;
		head = node;
	}
	size++;
}

void Stack::pop() 
{
	if (size == 0)
		return;
	Node* temp = head;
	head = head->next;
	delete temp;
	size--;
}

Stack::~Stack()
{
	while (size != 0)
		pop();
}