#pragma once
#include <iostream>
using std::string;

class User;

class Room
{
public:
	virtual void sendMessageToEveryone(User* sender, string message) = 0;
	virtual void sendMessageTo(User* sender, User* receiver, string message) = 0;
};


