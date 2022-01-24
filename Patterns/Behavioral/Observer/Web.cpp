#include "Web.h"

void Web::printNotification(Letter* letter)
{
	cout << "Web: " << endl;
	cout << "------------------------------" << endl;
	cout << "Letter from: " << letter->getFrom() << endl;
	cout << "date: " << letter->getDate() << endl;
	cout << "\"" << letter->getTitle() << "\"" << endl;
	cout << "------------------------------" << endl;
}