#include "Tree.h"

void Tree::makeNode(Node** node, Person* person)
{
	if (!(*node))
	{
		Node* newNode = new Node(person);
		*node = newNode;
	}
	else
	{
		if (sortingWay == alphabet)
		{
			if (*person < *((*node)->person))
			{
				makeNode(&((*node)->left), person);
			}
			else if (*person > *((*node)->person))
			{
				makeNode(&((*node)->right), person);
			}
		}
		else
		{
			if (person->getPhoneNumber() < (*node)->person->getPhoneNumber())
			{
				makeNode(&((*node)->left), person);
			}
			else if (person->getPhoneNumber() > (*node)->person->getPhoneNumber())
			{
				makeNode(&((*node)->right), person);
			}
		}
	}
}

void Tree::addNode(Person* person)
{
	makeNode(&root, person);
}

void Tree::deleteNode(Node** node, Person* person)
{
	if (*node) 
	{
		if (*((*node)->person) == *person) 
		{
			Node* n = *node;
			if (!n->left && !n->right)
				*node = nullptr;
			else if (!n->left)
				*node = n->right;
			else if (!n->right)
				*node = n->left;
			else 
			{
				*node = n->right;
				Node** ptr = node;
				while (*ptr) ptr = &((*ptr)->left);
				(*ptr) = n->left;
			}
			delete(n);
			deleteNode(node, person);
		}
		else 
		{
			deleteNode(&((*node)->left), person);
			deleteNode(&((*node)->right), person);
		}
	}
}

void Tree::removeNode(Person* person)
{
	deleteNode(&root, person);
}

Person* Tree::search(string str)
{
	Node* tmp = root;
	while (tmp)
	{
		Person* tmpPerson = tmp->person;
		string str2;
		if (sortingWay == alphabet)
			str2 = tmpPerson->getSurname();
		else
			str2 = tmpPerson->getPhoneNumber();
		if (str2 > str)
		{
			tmp = tmp->left;
			continue;
		}
		else if (str2 < str)
		{
			tmp = tmp->right;
			continue;
		}
		else
			return tmpPerson;
	}
	return nullptr;
}

void Tree::print(Node* node)
{
	if (node != 0)
	{
		print(node->left);
		node->person->print();
		cout << "-------------------------------" << endl;
		print(node->right);
	}
}

void Tree::printAll()
{
	print(root);
}

void Tree::printRange(Node* node, string start, string end)
{
	string str;
	if (sortingWay == alphabet)
		str = node->person->getSurname();
	else
		str = node->person->getPhoneNumber();
	if (node != 0)
	{
		if (str > start)
			printRange(node->left, start, end);
		if (str >= start && str <= end)
		{
			node->person->print();
			cout << "-------------------------------" << endl;
		}
		if (str < end)
			printRange(node->right, start, end);
	}
}

void Tree::printRange(string start, string end)
{
	if (root == nullptr)
		cout << "The database is empty!" << endl;
	else
		printRange(root, start, end);
}

void  Tree::writeToFile(Node* node, const char* name)
{
	ofstream fout(name, ios::app);
	if (node != 0)
	{
		writeToFile(node->left, name);
		node->person->writeToFile(name);
		fout << "-------------------------------" << endl;
		writeToFile(node->right, name);
	}
	fout.close();
}

void Tree::writeToFile(const char* name)
{
	writeToFile(root, name);
}