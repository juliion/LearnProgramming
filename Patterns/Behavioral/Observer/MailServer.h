#pragma once
#include "Application.h"
#include "Letter.h"
#include <list>
using std::list;

class MailServer
{
	list<Application*> listeners;
public:
	MailServer() = default;
	void subscribe(Application* listener);
	void unsubscribe(Application* listener);
	void notify(Letter* letter);
	void getLetter(Letter* letter);
};

