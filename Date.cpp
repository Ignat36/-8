#include "Date.h"

Date::Date(int _year, int _month, int _day)
{
	year = _year;
	month = _month;
	day = _day;
}

Date::Date() {}

bool operator!= (const Date& a, const Date& b) { return a.year != b.year || a.month != b.month || a.day != b.day ? true : false; }

bool operator== (const Date& a, const Date& b) { return !(a != b); }

bool operator> (const Date& a, const Date& b)
{
	if (a.year > b.year)
		return true;
	else
	{
		if (a.year == b.year)
		{
			if (a.month > b.month)
				return true;
			else
			{
				if (a.month == b.month)
				{
					if (a.day > b.day)
						return true;
				}
			}
		}
	}

	return false;
}

bool operator< (const Date& a, const Date& b) { return !(a > b) && a != b; }

bool operator>= (const Date& a, const Date& b) { return !(a < b); }
bool operator<= (const Date& a, const Date& b) { return !(a > b); }

std::string Date::show()
{
	std::string res = "";

	if (day < 10)
		res += "0";
	res += std::to_string(day) + ".";

	if (month < 10)
		res += "0";
	res += std::to_string(month) + "." + std::to_string(year);

	return res;
}
int operator- (const Date& a, const Date& b)
{
	int y, m, d;
	
	y = a.year - b.year;
	m = a.month - b.month;
	d = a.day - b.day;

	if (d < 0) m--;
	if (m < 0) y--;

	return y * 365 + m * 30 + d;
}