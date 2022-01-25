#include "ChatRoom.h"

void ChatRoom::addMember(User* user)
{
	user->setRoom(this);
	members.push_back(user);
}

void ChatRoom::sendMessageToEveryone(User* sender, string message)
{
	for (User* member : members)
	{
		if(member != sender)
			member->receive(sender, message);
	}
}

void ChatRoom::sendMessageTo(User* sender, User* receiver, string message)
{
	vector<User*>::iterator it;
	it = find(members.begin(), members.end(), receiver);
	if (it != members.end())
		(*it)->receive(sender, message);
}