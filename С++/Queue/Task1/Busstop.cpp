#include "Busstop.h"

enum DurationTime
{
	morning = 240,
	day = 420,
	evening = 300,
	night = 250
};

enum TypeBusstop
{
	start,
	other
};

Busstop::Busstop(int intervalArriveBus, int intervalArriveHuman, int type, int durationTime)
{
	this->intervalArriveBus = intervalArriveBus;
	this->intervalArriveHuman = intervalArriveHuman;
	this->type = type;
	this->durationTime = durationTime;
	timeHumans = new Queue;
}

void Busstop::pushBus()
{
	Bus currentBus;
	if (type == other)
		currentBus.setRandomFreePlaces();
	busses.push_back(currentBus);
}

void Busstop::averHumanTime()
{
	double allAverTime = 0;
	int durTime = durationTime;
	while (durTime > 0)
	{
		int timeBeforeBus = intervalArriveBus;
		pushBus();
		Bus currentBus = busses[busses.size() - 1];
		while (timeBeforeBus > 0)
		{
			timeHumans->push(0);
			timeHumans->increaseElements(intervalArriveHuman);
			timeBeforeBus -= intervalArriveHuman;
		}
		int humansAtBusstop = timeHumans->getSize();
		int freePlaces = currentBus.getFreePlaces();
		int humansInBus = humansAtBusstop < freePlaces ? humansAtBusstop : freePlaces;
		allAverTime += timeHumans->countAverage(humansInBus);
		for (int i = 0; i < humansInBus; i++)
			timeHumans->pop();
		durTime -= intervalArriveBus;
	}
	allAverTime /= busses.size();
	cout << "���������� ���������: " << busses.size() << endl;
	cout << "������� ����� ���������� �������� �� ���������: " << allAverTime << " �����" << endl;
	timeHumans->clear();
}

void Busstop::optimalIntArriveBus()
{
	int freePlaces = 0;
	if (type == start)
		freePlaces = Bus::maxFreePlaces;
	else
	{
		int sum = 0;
		for (int i = 0; i < busses.size(); i++)
			sum += busses[i].getFreePlaces();
		freePlaces = sum / busses.size();
	}
	int optimalInterval = freePlaces * intervalArriveHuman;
	cout << "����������� ����� ����� ��������� ���������: " << optimalInterval << " �����" << endl;
	intervalArriveBus = optimalInterval;
	cout << "� ����������� ��������: " << endl;
	vector<Bus>().swap(busses);
	averHumanTime();
}

void Busstop::printDate()
{
	cout << "����� �����: ";
	switch (durationTime)
	{
		case morning: cout << "����" << endl; break;
		case day: cout << "����" << endl; break;
		case evening: cout << "�����" << endl; break;
		case night: cout << "����" << endl; break;
	}
	cout << "��� ���������: ";
	switch (type)
	{
		case start: cout << "���������" << endl; break;
		case other: cout << "�� ���������" << endl; break;
	}
	cout << "������� ����� ����� ����������� ���������� �� ���������: " << intervalArriveHuman << " �����" << endl;
	cout << "C������ ����� ����� ����������� ���������: " << intervalArriveBus << " �����" << endl;
	averHumanTime();
	optimalIntArriveBus();
}