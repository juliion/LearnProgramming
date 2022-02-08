#include <iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;

void printStackAndQueue(Stack* stack, Queue* queue)
{
	cout << "Stack: " << endl;
	stack->print();
	cout << endl;
	cout << "Queue: " << endl;
	queue->print();
}

int main()
{
	Stack* st = new Stack;
	Queue* q = new Queue;
	for (int i = 1; i < 11; i++)
	{
		st->push(i);
		q->push(i);
	}
	printStackAndQueue(st, q);
	st->pop();
	q->pop();
	cout << endl;
	cout << "After pop():" << endl;
	printStackAndQueue(st, q);
	return 0;
}