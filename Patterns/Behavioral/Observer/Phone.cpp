#include "Phone.h"

void Phone::printNotification(Letter* letter)
{
	cout << "Phone: " << endl;
	cout << "------------------------------" << endl;
	cout << "Letter from: " << letter->getFrom() << endl;
	cout << "date: " << letter->getDate() << endl;
	cout << "\"" << letter->getTitle() << "\"" << endl;
	cout << "------------------------------" << endl;
}