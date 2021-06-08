#pragma once

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