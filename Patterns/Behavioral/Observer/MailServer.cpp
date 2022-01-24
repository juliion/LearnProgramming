#include "MailServer.h"

void MailServer::subscribe(Application* listener)
{
	listeners.push_back(listener);
}

void MailServer::unsubscribe(Application* listener)
{
	listeners.remove(listener);
}

void MailServer::notify(Letter* letter)
{
    list<Application*>::iterator it = listeners.begin();
    while (it != listeners.end())
    {
        (*it)->printNotification(letter);
        ++it;
    }
}

void MailServer::getLetter(Letter* letter)
{
    notify(letter);
}