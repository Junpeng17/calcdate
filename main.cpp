#include "datestr.h"
#include "calc.h"

int main(int argc, char *argv[])
{
	datestr date1("2022-05-09");
	datestr date2("2022-09-20");
	int day = (date1, date2);

	cout << "2022��05��09�վ�2022��09��20�����" << day << "��" << endl;

	calc("2022-05-01,2022-08-13");

	return 0;
}