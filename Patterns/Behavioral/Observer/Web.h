#pragma once
#include "Application.h"

class Web : public Application
{
public:
	virtual void printNotification(Letter* letter) override;
};

