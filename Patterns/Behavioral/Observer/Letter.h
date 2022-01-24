#pragma once
#include <iostream>
using std::string;

class Letter
{
	string from;
	string date;
	string title;
public:
	Letter(string fr, string d, string t) : from{ fr }, date{ d }, title{ t } { }
	string getFrom();
	string getDate();
	string getTitle();
};

