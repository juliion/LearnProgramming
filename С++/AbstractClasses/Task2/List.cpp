#include "List.h"

List::List()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
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
