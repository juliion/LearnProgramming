#include "Tree.h"

void Node::print()
{
	cout << "Number of the car: " << carNumber << endl;
	list<Offense>::iterator it;
	it = offenses.begin();
	while (it != offenses.end())
	{
		cout << "-------------------------------------" << endl;
		it->print();
		++it;
	}
}

void Tree::addNode(Node** node, string carNumber, Offense offense)
{
	if (!(*node))
	{
		Node* newNode = new Node(carNumber);
		newNode->offenses.push_back(offense);
		*node = newNode;
	}
	else
	{
		if (carNumber < (*node)->carNumber)
		{
			addNode(&((*node)->left), carNumber, offense);
		}
		else if (carNumber > (*node)->carNumber)
		{
			addNode(&((*node)->right), carNumber, offense);
		}
	}
}

Node* Tree::search(string carNumber)
{
	Node* tmp = root;
	while (tmp)
	{
		if (tmp->carNumber > carNumber)
		{
			tmp = tmp->left;
			continue;
		}
		else if (tmp->carNumber < carNumber)
		{
			tmp = tmp->right;
			continue;
		}
		else
			return tmp;
	}
	return nullptr;
}

void Tree::addOffense(string carNumber, Offense offense)
{
	Node* node = search(carNumber);
	if (node == nullptr)
		addNode(&root, carNumber, offense);
	else
		node->offenses.push_back(offense);
}


void Tree::print(Node* node)
{
	if (node != 0)
	{
		print(node->left);
		node->print();
		cout << "=====================================" << endl;
		print(node->right);
	}
}

void Tree::printAll()
{
	if (root == nullptr)
		cout << "The database is empty!" << endl;
	else
		print(root);
}

void Tree::printOne(string carNumber)
{
	Node* node = search(carNumber);
	if (node == nullptr)
		cout << "Not found!" << endl;
	else
		node->print();
}

void Tree::printRange(Node* node, string start, string end)
{
	if (node != 0)
	{
		if (node->carNumber > start)
			printRange(node->left, start, end);
		if (node->carNumber >= start && node->carNumber <= end)
		{
			node->print();
			cout << "=====================================" << endl;
		}
		if (node->carNumber < end)
			printRange(node->right, start, end);
	}
}

void Tree::printRangeNumber(string start, string end)
{
	if (root == nullptr)
		cout << "The database is empty!" << endl;
	else
		printRange(root, start, end);
}