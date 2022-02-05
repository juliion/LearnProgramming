#pragma once
#include "Exception.h"

class FileException : public Exception
{
public:
	FileException(string errorMessage) : Exception("File error", errorMessage) { }
};

class OpenFile : public FileException
{
public:
	OpenFile() : FileException("could not open file") { }
};