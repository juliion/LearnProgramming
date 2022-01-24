#include "Desktop.h"

void Desktop::printNotification(Letter* letter)
{
	cout << "Desktop: " << endl;
	cout << "------------------------------" << endl;
	cout << "Letter from: " << letter->getFrom() << endl;
	cout << "date: " << letter->getDate() << endl;
	cout << "\"" << letter->getTitle() << "\"" << endl;
	cout << "------------------------------" << endl;
}