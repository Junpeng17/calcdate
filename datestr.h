#pragma once
#include "calc.h"
class datestr :
	public calc
{
public:
	datestr(string str);

	friend string operator+(const datestr&, const datestr&);
	friend string operator-(const datestr&, const datestr&);
	friend int operator,(const datestr&, const datestr&);

private:
	string data;
};

