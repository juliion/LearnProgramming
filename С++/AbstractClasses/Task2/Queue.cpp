#include "Queue.h"

void Queue::push(int value)
{
	Node* node = new Node(value);
	if (size == 0)
	{
		head = node;
		tail = node;
	}
	else
	{
		tail->next = node;
		tail = node;
	}
	size++;
}

void Queue::pop()
{
	if (size == 0)
		return;
	Node* temp = head;
	head = head->next;
	delete temp;
	size--;
}

Queue::~Queue()
{
	while (size != 0)
		pop();
}