#pragma once
#include "Application.h"

class Desktop : public Application
{
public:
	virtual void printNotification(Letter* letter) override;
};

