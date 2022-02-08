#pragma once
#include "List.h"

class Queue : public List
{
public:
	Queue() : List() { }
	virtual void push(int value) override;
	virtual void pop() override;
	~Queue();
};

