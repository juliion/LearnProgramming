#pragma once
#include "User.h"

class ChatRoom : public Room
{
	vector<User*> members;
public:
	ChatRoom() = default;
	void addMember(User* user);
	virtual void sendMessageToEveryone(User* sender, string message) override;
	virtual void sendMessageTo(User* sender, User* receiver, string message) override;
};

