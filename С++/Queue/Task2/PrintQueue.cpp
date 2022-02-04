#include "PrintQueue.h"
#include "Person.h"

PrintQueue::PrintQueue()
{
	size =  0;
	requests = nullptr;
}

PrintQueue::~PrintQueue()
{
	delete[] requests;
}

void PrintQueue::resize(int size, int newSize)
{
	Person* newRequests = new Person[newSize];
	for (int i = 0; i < size; i++)
		newRequests[i] = requests[i];
	if (requests != nullptr)
		delete[] requests;
	requests = newRequests;
}

void PrintQueue::insert(int pos, Person request)
{
	Person* newRequests = new Person[size];
	int ind = 0;
	newRequests[pos] = request;
	for (int i = 0; i < size; i++)
	{
		if (i != pos)
		{
			newRequests[i] = requests[ind];
			ind++;
		}
	}
	if (requests != nullptr)
		delete[] requests;
	requests = newRequests;
}

bool operator< (const Date& d1, const Date& d2)
{
	bool result = false;
	if (d1.year == d1.year)
	{
		if (d1.mounth == d2.mounth)
		{
			if (d1.day == d2.day)
			{
				if (d1.hours == d2.hours)
				{
					if (d1.minutes == d1.minutes)
						return false;
					else
						return d1.minutes < d1.minutes;
				}
				else
					return d1.hours < d2.hours;
			}
			else
				return d1.day < d2.day;
		}
		else
			return d1.mounth < d2.mounth;
	}
	else
		return d1.year < d2.year;
}

void PrintQueue::push(Person request)
{
	int pos = 0;
	int priority = request.getPriority();
	Date printDate = request.getPrintDate();
	if (size != 0)
	{
		while (pos != size)
		{
			int priorityCurrReq = requests[pos].getPriority();
			Date printDateCurrReq = requests[pos].getPrintDate();
			if (priorityCurrReq < priority)
				break;
			pos++;
		}
		while (pos != 0)
		{
			int priorityPrevReq = requests[pos - 1].getPriority();
			Date printDatePrevReq = requests[pos - 1].getPrintDate();
			if (priorityPrevReq != priority)
				break;
			if (printDatePrevReq < printDate)
				break;
			pos--;
		}
	}
	resize(size++, size);
	insert(pos, request);
}

void PrintQueue::pop()
{
	if (size == 0)
		exit(0);
	size--;
	Person* newRequests = new Person[size];
	for (int i = 0; i < size; i++)
		newRequests[i] = requests[i + 1];
	if (requests != nullptr)
		delete[] requests;
	requests = newRequests;
}

void PrintQueue::printStatistics()
{
	if (size == 0)
		cout << "Queue is empty!" << endl;
	else
	{
		cout << " Print queue:";
		for (int i = 0; i < size; i++)
		{
			cout << endl <<  "-----------------------------------" << endl;
			requests[i].print();
		}
		cout << endl << "-----------------------------------" << endl << endl;
	}
}