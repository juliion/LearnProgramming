#include "ChatRoom.h"

int main()
{
	User* lily = new User("Lily");
	User* maria = new User("Maria");
	User* sophia = new User("Sophia");
	ChatRoom* chat = new ChatRoom();
	chat->addMember(lily);
	chat->addMember(maria);
	chat->addMember(sophia);
	lily->send("Hi, everyone!");
	sophia->send("Hello)");
	maria->sendTo(sophia, "How are you?");
	lily->printMessagesReceived();
	cout << "---------------------------------" << endl;
	sophia->printMessagesReceived();
	cout << "---------------------------------" << endl;
	maria->printMessagesReceived();

	delete lily;
	delete maria;
	delete sophia;
	delete chat;
	return 0;
}