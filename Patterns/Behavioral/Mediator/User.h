#pragma once
#include "Room.h"
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class User
{
	string name;
	Room* room;
	vector<string> messagesReceived;
public:
	User(string n, Room* r = nullptr) : name{ n }, room{ r } { }
	~User() = default;
	void setRoom(Room* room);
	string getName();
	void send(string message);
	void sendTo(User* receiver, string message);
	void receive(User* sender, string message);
	void printMessagesReceived();
	friend bool operator==(User& u1, User& u2);
};

