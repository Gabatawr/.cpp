#include "Date.h"


Date::Date()
{
	day = 20;
	month = 2;
	year = 2020;
}

Date::Date(unsigned char day, unsigned char month, unsigned short year) : Date()
{
	unsigned char day_t = day;
	unsigned char month_t = month;
	unsigned short year_t = year;
	
	do {
		std::swap(this->day, day_t);
		std::swap(this->month, month_t);
		std::swap(this->year, year_t);
	} while (not check());
}

bool Date::replace(const char* date)
{
	unsigned char day_t = 0, month_t = 0;
	unsigned short year_t = 0;
	
	double number = 0;
	for (auto i = 0, count = 0; count < 3 && date[i] != '\0'; i++)
	{
		bool flag = false;

		int digits = i;
		while (date[i] >= 48 && date[i] <= 57) {
			flag = true;
			i++;
		}
		digits = i - digits;
		
		if (digits > 0)
		{
			count++;
			i -= digits;
			for (auto j = 0; j < digits; j++, i++)
			{
				number += static_cast<double>(date[i] - 48) / 10;
				number *= 10;
			}
			if (count == 1) day_t = static_cast<unsigned char>(number);
			else if (count == 2) month_t = static_cast<unsigned char>(number);
			else year_t = static_cast<unsigned short>(number);
		}
		if (flag) i--;
	}

	if (day_t == 0 || month_t == 0 || year_t == 0) return false;

	auto check = 0;
	do {
		std::swap(this->day, day_t);
		std::swap(this->month, month_t);
		std::swap(this->year, year_t);
		check++;
	} while (not this->check());

	if (check == 1) return true;
	return false;
}

void Date::replace(Date& other)
{
	day = other.day;
	month = other.month;
	year = other.year;
}

void Date::random(unsigned short min_year, unsigned short max_year)
{
	do {
		this->day = rand() % 31 + 1;
		this->month = rand() % 12 + 1;
		this->year = rand() % (max_year - min_year) + min_year;
	} while (not this->check());
}

bool Date::leap_year() const
{
	return year % 4 != 0 || year % 100 == 0 && year % 400 != 0;
}

bool Date::check() const
{
	if (month > 12 || month < 1) return false;
	if (day < 1 || 31 < day) return false;
	if (day == 31 && (month != 1 && month != 2 && month != 3 && month != 5 && month != 7 && month != 8 && month != 10 && month != 12)) return false;
	if (day > 28 && (month == 2 && not leap_year()) || day > 29 && (month == 2 && leap_year())) return false;
	return true;
}

int Date::full_years() const
{
	time_t date_now_tmp;
	time(&date_now_tmp);
	struct tm* date_now = nullptr;
	localtime_s(date_now, &date_now_tmp);

	int full_years = date_now->tm_year + 1900 - this->year;

	if (date_now->tm_mon + 1 < this->month) full_years--;
	else if (date_now->tm_mon + 1 == this->month)
	if (date_now->tm_mday < this->day) full_years--;

	return full_years;
}

/*
bool birthday_today() const
{
	time_t date_now_tmp; time(&date_now_tmp);
	struct tm* date_now = localtime(&date_now_tmp);

	return date_now->tm_mon + 1 == this->month && date_now->tm_mday == this->day;
}
*/

int Date::days_between_dates(Date other)
{
	if (this->year > other.year)
	{
		std::swap(this->year, other.year);
		std::swap(this->month, other.month);
		std::swap(this->day, other.day);
	}
	else if (this->year == other.year && this->month > other.month)
	{
		std::swap(this->month, other.month);
		std::swap(this->day, other.day);
	}
	else if (this->year == other.year && this->month == other.month)
	{
		if (this->day > other.day) std::swap(this->day, other.day);
		return other.day - this->day;
	}
	int days_d1 = 0, days_d2 = 0;
	for (int count_day = 0, tmp_m = this->month, i = 0; i < 2; i++, count_day = 0, tmp_m = other.month) 
	{
		for (; tmp_m > 1; tmp_m--) 
		{
			if (tmp_m == 1 || tmp_m == 3 || tmp_m == 5 || tmp_m == 7 || tmp_m == 8 || tmp_m == 10 || tmp_m == 12) count_day += 31;
			else if (tmp_m == 2) 
			{
				if (i == 0)
				{
					if (this->leap_year()) count_day += 29;
					else count_day += 28;
				}
				else
				{
					if (other.leap_year()) count_day += 29;
					else count_day += 28;
				}
			}
			else count_day += 30;
			if (i == 0) days_d1 = count_day + this->day;
			else {
				if (other.leap_year()) days_d2 = 366 - (count_day + other.day);
				else days_d2 = 365 - (count_day + other.day);
			}
		}
	}
	for (int days = 0; this->year <= other.year; this->year++) 
	{
		if (this->leap_year()) days += 366;
		else days += 365;
		if (this->year == other.year) return days - days_d1 - days_d2;
	}
}

Date& Date::operator ++ ()
{
	day++;
	if (not check())
	{
		day = 1;
		month++;
		if (not check())
		{
			month = 1;
			year++;
		}
	}
	
	return *this;
}

Date Date::operator  ++ (int)
{
	Date res = *this;

	res.day++;
	if (not res.check())
	{
		res.day = 1;
		res.month++;
		if (not res.check())
		{
			res.month = 1;
			res.year++;
		}
	}
	
	return res;
}

Date& Date::operator -- ()
{
	if (day == 1)
	{
		if (month == 1)
		{
			year--; month = 12; day = 31;
		}
		else
		{
			day = 31; month--;
			while (not check()) day--;
		}
	}
	else day--;
	
	return *this;
}

Date Date::operator  -- (int)
{
	Date res = *this;

	if (res.day == 1)
	{
		if (res.month == 1)
		{
			res.year--; res.month = 12; res.day = 31;
		}
		else
		{
			res.day = 31; res.month--;
			while (not res.check()) res.day--;
		}
	}
	else res.day--;
	
	return res;
}

bool Date::operator != (const Date& other)
{
	return this->day != other.day || this->month != other.month || this->year != other.year;
}

bool Date::operator == (const Date& other)
{
	return this->day == other.day && this->month == other.month && this->year == other.year;
}

bool Date::operator > (const Date& other)
{
	if (this->year == other.year)
	{
		if (this->month == other.month) 
		{
			return this->day > other.day;
		}
		return this->month > other.month;
	}
	return this->year > other.year;
}

bool Date::operator < (const Date& other)
{
	if (this->year == other.year)
	{
		if (this->month == other.month)
		{
			return this->day < other.day;
		}
		return this->month < other.month;
	}
	return this->year < other.year;
}

std::istream& operator >> (std::istream& in, Date& date)
{
	unsigned char s;
	unsigned short d, m, y;
	
	std::cout << "dd.mm.yyyy\b\b\b\b\b\b\b\b\b\b";
	in >> d >> s >> m >> s >> y;

	date.day = d;
	date.month = m;
	date.year = y;
	
	return in;
}

std::ostream& operator << (std::ostream& out, const Date& date)
{
	if (date.day < 10) out << "0"; out << static_cast<int>(date.day) << ".";
	if (date.month < 10) out << "0"; out << static_cast<int>(date.month) << ".";
	out << date.year;
	return out;
}