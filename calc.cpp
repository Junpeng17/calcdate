// calc.cpp
//

#include "calc.h"
#include <math.h>

calc::calc(string str)
{

    string s1;
    string s2;
    for (char c : str)
    {
        if (c == ',') {
            s1 = str.substr(0, 10);
            s2 = str.substr(11, 21);
            break;
        }
    }
    mySpilt({ s1,s2 });
    cout << s1 << "和" << s2 << "之间" << "相差" << interval() << "天" << endl;
}

void calc::mySpilt(initializer_list<string> s1)
{
    string s1_1, s2_1, s3_1;
    string s1_2, s2_2, s3_2;
    string* str = new string[2];
    
    int length = s1.size();
    if (length == 1) {
        for (auto p = s1.begin(); p != s1.end(); ++p) {
            s1_1 = (*p).substr(0, 4);
            s2_1 = (*p).substr(5, 2);
            s3_1 = (*p).substr(8, 2);
            start_year = atoi(s1_1.c_str());
            start_month = atoi(s2_1.c_str());
            start_day = atoi(s3_1.c_str());
        }
    }
    else if (length == 2) {
        int i = 0;
        for (auto p = s1.begin(); p != s1.end(); ++p, i++) {
            str[i] = *p;
        }
        checkSwap(str);
        s1_1 = ss1.substr(0, 4);
        s2_1 = ss1.substr(5, 2);
        s3_1 = ss1.substr(8, 2);
        start_year = atoi(s1_1.c_str());
        start_month = atoi(s2_1.c_str());
        start_day = atoi(s3_1.c_str());

        s1_2 = ss2.substr(0, 4);
        s2_2 = ss2.substr(5, 2);
        s3_2 = ss2.substr(8, 2);
        end_year = atoi(s1_2.c_str());
        end_month = atoi(s2_2.c_str());
        end_day = atoi(s3_2.c_str());
    }
}

void calc::checkSwap(string* s)
{
    raw_start = atoi(s[0].c_str());
    raw_end = atoi(s[1].c_str());

    if (raw_start > raw_end) {
        ss1 = s[1];
        ss2 = s[0];
    }
    else {
        ss1 = s[0];
        ss2 = s[1];
    }
}

int calc::interval()
{
    days = 0;
    int go = 1;

    while (go) {
        if (start_month != 2 && (start_month == 1 || start_month == 3 || start_month == 5 || start_month == 7 || start_month == 8 ||
            start_month == 10 || start_month == 12)) {
            if (start_day == 31) {
                if (start_month != 12) {
                    start_month++;
                }
                else {
                    start_year++;
                    start_month = 1;
                }
                //days++;
                start_day = 0;
                continue;
            }
            start_day++;
            days++;

        }
        else if (start_month != 2 && (start_month == 4 || start_month == 6 || start_month == 9 || start_month == 11)) {
            if (start_day == 30) {
                start_month++;
                //days++;
                start_day = 0;
                continue;
            }
            start_day++;
            days++;

        }
        else if (start_month == 2) {
            if (runnian(start_year)) {
                if (start_day == 29) {
                    start_month++;
                    start_day = 0;
                    //days++;
                    continue;
                }
                start_day++;
                days++;
            }
            else {
                if (start_day == 28) {
                    start_month++;
                    //days++;
                    start_day = 0;
                    continue;
                }
                start_day++;
                days++;
            }
        }
        if (start_year == end_year) {
            if (start_month == end_month) {
                if (start_day == end_day) {
                    go = 0;
                }
            }
        }
    }
    return days;
}

string calc::after(int days)
{
    string output;

    while (days >= 1) {
        if (start_month != 2 && (start_month == 1 || start_month == 3 || start_month == 5 || start_month == 7 || start_month == 8 ||
            start_month == 10 || start_month == 12)) {
            if (start_day == 31) {
                if (start_month != 12) {
                    start_month++;
                }
                else {
                    start_year++;
                    start_month = 1;
                }
                days--;
                start_day = 1;
                continue;
            }
            start_day++;
            days--;
        }
        else if (start_month != 2 && (start_month == 4 || start_month == 6 || start_month == 9 || start_month == 11)) {
            if (start_day == 30) {
                start_month++;
                days--;
                start_day = 1;
                continue;
            }
            start_day++;
            days--;
        }
        else if (start_month == 2) {
            if (runnian(start_year)) {
                if (start_day == 29) {
                    start_month++;
                    start_day = 1;
                    days--;
                    continue;
                }
                start_day++;
                days--;
            }
            else {
                if (start_day == 28) {
                    start_month++;
                    days--;
                    start_day = 1;
                    continue;
                }
                start_day++;
                days--;
            }
        }
    }
    string str_start_month;
    string str_start_day;
    if (start_month < 10) {
        str_start_month = "0" + to_string(start_month);
    }
    else {
        str_start_month = to_string(start_month);
    }
    if (start_day < 10) {
        str_start_day = "0" + to_string(start_day);
    }
    else {
        str_start_day = to_string(start_day);
    }
		output = to_string(start_year) + "年" + str_start_month + "月" + str_start_day + "日";
		return output;
}

string calc::before(int days)
{
    string output;

    days = fabs(days);

    while (days > 0) {
        if (start_month != 2 && (start_month == 1 || start_month == 3 || start_month == 5 || start_month == 7 || start_month == 8 ||
            start_month == 10 || start_month == 12)) {
            if (start_day == 1) {
                if (start_month == 1) {
                    start_year--;
                    start_month = 12;
                    start_day = 31;
                    days--;
                    continue;
                }
                else if (start_month == 3) {
                    start_month--;
                    if (runnian(start_year)) {
                        start_day = 29;
                        days--;
                        continue;
                    }
                    else {
                        start_day = 28;
                        days--;
                        continue;
                    }
                }
                if (start_month == 8) {
                    start_day = 31;
                }
                else {
                    start_day = 30;
                }
                start_month--;
                days--;
                continue;
            }
        }
        else if (start_month != 2 && (start_month == 4 || start_month == 6 || start_month == 9 || start_month == 11)) {
            if (start_day == 1) {
                start_month--;
                start_day = 31;
                days--;
                continue;
            }
        }
        else if (start_month == 2) {
            if (start_day == 1) {
                start_month--;
                start_day = 31;
                days--;
                continue;
            }
        }
        start_day--;
        days--;
    }
    string str_start_month;
    string str_start_day;
    if (start_month < 10) {
        str_start_month = "0" + to_string(start_month);
    }
    else {
        str_start_month = to_string(start_month);
    }
    if (start_day < 10) {
        str_start_day = "0" + to_string(start_day);
    }
    else {
        str_start_day = to_string(start_day);
    }
    output = to_string(start_year) + "年" + str_start_month + "月" + str_start_day + "日";

    return output;
}


int calc::runnian(int year)
{
    return (year % 4) == 0 ? 1 : 0;
}
