#pragma once
#include <iostream>
class Set
{
	int* elements;
	int size;
	void resize(int newSize);
public:
	Set(int* elements, int size);
	Set() : Set(nullptr, 0) { }
	~Set();
	bool has(int num);
	bool has(int num) const;
	Set& operator+=(const Set& s);
	Set& operator+=(int element);
	Set& operator-=(const Set& s);
	Set& operator-=(int element);
	Set& operator*=(const Set& s);
	Set& operator=(const Set& s);
	friend const Set operator+(const Set& s1, const Set& s2);
	friend const Set operator+(const Set& s, int element);
	friend const Set operator-(const Set& s1, const Set& s2);
	friend const Set operator-(const Set& s, int element);
	friend const Set operator*(const Set& s1, const Set& s2);
	friend bool operator==(const Set& s1, const Set& s2);
	friend std::ostream& operator<<(std::ostream& output, const Set& s);
};

