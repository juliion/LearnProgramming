#include "MailServer.h"
#include "Web.h"
#include "Desktop.h"
#include "Phone.h"

int main()
{
	MailServer* ms = new MailServer();
	Web* w = new Web();
	Desktop* d = new Desktop();
	Phone* ph = new Phone();
	ms->subscribe(w);
	ms->subscribe(d);
	ms->subscribe(ph);
	ms->getLetter(new Letter("Maria", "18.09.2021  07:30", "Hello!"));

	delete ms;
	delete w;
	delete d;
	delete ph;
	return 0;
}