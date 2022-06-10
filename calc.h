#pragma once

#include <iostream>
#include <string>

using namespace std;

class calc
{
public:
	calc(void) = default;
	calc(string str);
	int days;
	string data;

	void mySpilt(initializer_list<string> s1);
	int interval();
	string before(int days);
	string after(int days);

private:
	int raw_start, raw_end;
	int start_year, end_year;
	int start_month, end_month;
	int start_day, end_day;
	string ss1, ss2;

	int runnian(int year);
	void checkSwap(string* s);
};

