#pragma once
#include "List.h"

class Stack : public List
{
public:
	Stack() : List() { }
	virtual void push(int value) override;
	virtual void pop() override;
	~Stack();
};

