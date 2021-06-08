#pragma once
#include <iostream>

struct date
{
	unsigned char day;
	unsigned char month;
	unsigned short int year;

	date()
	{
		day = 11;
		month = 7;
		year = 1994;
	}

	void replace (char* data)
	{
		unsigned char      tmp_day   = str_to_int(data, 1);
		unsigned char      tmp_month = str_to_int(data, 2);
		unsigned short int tmp_year  = str_to_int(data, 3);
		
		if (tmp_day == 0 || tmp_month == 0|| tmp_year == 0) return;
		
		do {
			std::swap(this->day, tmp_day);
			std::swap(this->month, tmp_month);
			std::swap(this->year, tmp_year);
		} while (not this->check_date());
	}

	void randomizer (unsigned short int min_year = 1900, unsigned short int max_year = 2000)
	{
		do {
			this->day = rand() % 31 + 1;
			this->month = rand() % 12 + 1;
			this->year = rand() % (max_year - min_year) + min_year;
		} while (not this->check_date());
	}

	bool leap_year() const
	{
		return this->year % 4 != 0 || this->year % 100 == 0 && this->year % 400 != 0;
	}

	bool check_date() const
	{
		//if (this->year < 0) return false;
		if (this->month > 12 || this->month < 1) return false;
		if (this->day < 1 || 31 < this->day) return false;
		if (this->day == 31 && (this->month != 1 && this->month != 2 && this->month != 3 && this->month != 5 && this->month != 7 && this->month != 8 && this->month != 10 && this->month != 12)) return false;
		if (this->day > 28 && (this->month == 2 && not this->leap_year()) || this->day > 29 && (this->month == 2 && this->leap_year())) return false;
		return true;
	}

	int full_years() const
	{
		time_t date_now_tmp; time(&date_now_tmp);
		struct tm* date_now = localtime(&date_now_tmp);

		int full_years = date_now->tm_year + 1900 - this->year;

		if (date_now->tm_mon + 1 < this->month) full_years--;
		else if (date_now->tm_mon + 1 == this->month)
			if (date_now->tm_mday < this->day) full_years--;

		return full_years;
	}

	bool birthday_today() const
	{
		time_t date_now_tmp; time(&date_now_tmp);
		struct tm* date_now = localtime(&date_now_tmp);

		return date_now->tm_mon + 1 == this->month && date_now->tm_mday == this->day;
	}
	
};

std::ostream& operator << (std::ostream& out, const date& date)
{
	if (date.day   < 10) out << "0"; out << int(date.day)   << ".";
	if (date.month < 10) out << "0"; out << int(date.month) << ".";
	out << date.year;
	return out;
}

int days_between_dates(date one, date two)
{
	if (one.year > two.year)
	{
		std::swap(one.year, two.year);
		std::swap(one.month, two.month);
		std::swap(one.day, two.day);
	}
	else if (one.year == two.year && one.month > two.month)
	{
		std::swap(one.month, two.month);
		std::swap(one.day, two.day);
	}
	else if (one.year == two.year && one.month == two.month)
	{
		if (one.day > two.day) std::swap(one.day, two.day);
		return two.day - one.day;
	}

	int days_d1 = 0, days_d2 = 0;
	for (int count_day = 0, tmp_m = one.month, i = 0; i < 2; i++, count_day = 0, tmp_m = two.month) {
		for (; tmp_m > 1; tmp_m--) {
			if (tmp_m == 1 || tmp_m == 3 || tmp_m == 5 || tmp_m == 7 || tmp_m == 8 || tmp_m == 10 || tmp_m == 12) count_day += 31;
			else if (tmp_m == 2) {
				if (i == 0)
				{
					if (one.leap_year()) count_day += 29;
					else count_day += 28;
				} else
				{
					if (two.leap_year()) count_day += 29;
					else count_day += 28;
				}
				
			}
			else count_day += 30;

			if (i == 0) days_d1 = count_day + one.day;
			else {
				if (two.leap_year()) days_d2 = 366 - (count_day + two.day);
				else days_d2 = 365 - (count_day + two.day);
			}
		}
	}

	for (int days = 0; one.year <= two.year; one.year++) {
		if (one.leap_year()) days += 366;
		else days += 365;
		if (one.year == two.year) return days - days_d1 - days_d2;
	}
}