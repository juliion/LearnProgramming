#pragma once
#include "Application.h"

class Phone : public Application
{
public:
	virtual void printNotification(Letter* letter) override;
};

