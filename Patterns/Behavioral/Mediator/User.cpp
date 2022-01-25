#include "User.h"

void User::setRoom(Room* room)
{
	this->room = room;
}

string User::getName()
{
	return name;
}

void User::send(string message)
{
	room->sendMessageToEveryone(this, message);
}

void User::sendTo(User* receiver, string message)
{
	room->sendMessageTo(this, receiver, message);
}

void User::receive(User* sender, string message)
{
	messagesReceived.push_back(sender->getName() + ": " + message + "\n");
}

void  User::printMessagesReceived()
{
	cout << "messages for " << name << ":" << endl << endl;
	for (string m : messagesReceived)
		cout << m;
}

bool operator==(User& u1, User& u2)
{
	return u1.name == u2.name;
}
