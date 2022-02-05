#include "List.h"

List::List()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

List::~List()
{
	while (size != 0)
		pop();
}

void List::push_front(int value)
{
	Node* temp = new Node(value);
	temp->prev = nullptr;
	temp->next = head;
	if (head != nullptr)
		head->prev = temp;
	if (size == 0)
		head = tail = temp;
	else
		head = temp;
	size++;
}

void List::push_back(int value)
{
	Node* temp = new Node(value); 
	temp->next = nullptr; 
	temp->prev = tail;
	if (tail != nullptr)                     
		tail->next = temp;             
	if (size == 0)
		head = tail = temp;
	else
		tail = temp;
	size++;
}

void List::pop()
{
	if (size == 0)
		throw "Trying to remove from empty list \n";
	Node* temp = head;
	head = head->next;
	delete temp;
	size--;
}

void List::insert(int pos, int value)
{
	if (pos < 1 || pos > size + 1)
		throw "Incorrect position for insert\n";
	if (pos == size + 1)
		push_back(value);
	else if (pos == 1)
		push_front(value);
	else
	{
		int i = 1;
		Node* ins = head;
		while (i < pos)
		{
			ins = ins->next;
			i++;
		}
		Node* prevIns = ins->prev;
		Node* temp = new Node(value);
		if (prevIns != 0 && size != 1)
			prevIns->next = temp;
		temp->next = ins;
		temp->prev = prevIns;
		ins->prev = temp;
		size++;
	}
}

void List::print(int pos)
{
	if (pos < 1 || pos > size)
		throw "Incorrect position for printing\n";
	Node* temp = nullptr;
	if (pos <= size / 2)
	{
		temp = head;
		int i = 1;
		while (i < pos)
		{
			temp = temp->next;
			i++;
		}
	}
	else
	{
		temp = tail;
		int i = 1;
		while (i <= size - pos)
		{
			temp = temp->prev;
			i++;
		}
	}

	cout << pos << " element: ";
	cout << temp->value << endl;
}

void List::print()
{
	if (size != 0)
	{
		Node* temp = head;
		cout << "{ ";
		while (temp->next != 0)
		{
			cout << temp->value << ", ";
			temp = temp->next;
		}

		cout << temp->value << " }" << endl;
	}
}
