#pragma once
#include "Exception.h"

class MathematicalException : public Exception
{
public:
	MathematicalException(string errorMessage) : Exception("Mathematical error", errorMessage) { }
};

class DivisionByZero : public MathematicalException
{
public:
	DivisionByZero() : MathematicalException("division by zero") { }
};

class RootOfNegNum : public MathematicalException
{
public:
	RootOfNegNum() : MathematicalException("root of a negative number") { }
};

class WrongLogArg : public MathematicalException
{
public:
	WrongLogArg() : MathematicalException("wrong logarithm argument") { }
};