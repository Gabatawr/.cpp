#pragma once
#include <cstdlib>
#include <iostream>
#include <ctime>

class Date
{
	unsigned char day;
	unsigned char month;
	unsigned short year;
	
public:
	Date();
	Date(unsigned char, unsigned char, unsigned short);
	
	void replace(Date&);
	bool replace(const char*);
	
	void random(unsigned short = 1920, unsigned short = 2020);
	
	bool leap_year() const;
	
	bool check() const;

	int full_years() const;

	int days_between_dates(Date);

	Date& operator ++();
	Date operator  ++(int);

	Date& operator --();
	Date operator  --(int);
	
	bool operator != (const Date&);
	bool operator == (const Date&);

	bool operator > (const Date&);
	bool operator < (const Date&);

	friend std::istream& operator >> (std::istream&, Date&);
	friend std::ostream& operator << (std::ostream&, const Date&);
};
