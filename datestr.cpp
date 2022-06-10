#include "datestr.h"

datestr::datestr(string str)
{
	if (!str.empty()) {
		this->data = str;
	}
	
}

string operator+(const datestr& d1, const datestr& d2)
{
	calc daycalc;
	daycalc.mySpilt({ d1.data });

	return daycalc.after(atoi(d2.data.c_str()));
}

string operator-(const datestr& d1, const datestr& d2)
{
	calc daycalc;
	daycalc.mySpilt({ d1.data });

	return  daycalc.before(atoi(d2.data.c_str()));
}

int operator,(const datestr& d1, const datestr& d2)
{
	calc daycalc;
	daycalc.mySpilt({ d1.data, d2.data });

	return daycalc.interval();
}
