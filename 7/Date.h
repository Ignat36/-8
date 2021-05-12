#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class Date
{
public:
	int year;
	int month;
	int day;

	Date(int _year, int _month, int _day);

	Date();

	friend bool operator!= (const Date &a, const Date &b);
	friend bool operator== (const Date& a, const Date& b);
	friend bool operator> (const Date& a, const Date& b);
	friend bool operator< (const Date& a, const Date& b);
	friend bool operator>= (const Date& a, const Date& b);
	friend bool operator<= (const Date& a, const Date& b);
	friend int operator- (const Date& a, const Date& b);

	std::string show();
};

