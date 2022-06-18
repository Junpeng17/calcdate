#include "datestr.h"
#include "calc.h"

int main(int argc, char *argv[])
{
	datestr date1("2022-05-09");
	datestr date2("2022-09-20");
	int day = (date1, date2);

	cout << "2022年5月9日距2022年9月20日" << day << "天" << endl;

	calc("2022-05-01,2022-08-13");

	return 0;
}
