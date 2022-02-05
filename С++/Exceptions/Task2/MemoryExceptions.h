#pragma once
#include "Exception.h"

class MemoryException : public Exception
{
public:
	MemoryException(string errorMessage) : Exception("Memory error", errorMessage) { }
};

class ArrayOverflow : public MemoryException
{
public:
	ArrayOverflow() : MemoryException("array overflow") { }
};

class OutOfBounds : public MemoryException
{
public:
	OutOfBounds() : MemoryException("read out of bounds of array") { }
};
