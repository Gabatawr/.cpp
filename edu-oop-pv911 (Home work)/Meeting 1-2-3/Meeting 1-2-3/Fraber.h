#pragma once
#include <iostream>


class Fraber // Fractional Number
{
private:
	int n; // numerator
	int d; // denominator;

public:
	Fraber();
	Fraber(const Fraber&); // copying
	
	void set_n(int);
	void set_d(int);
	
	int get_n() const;
	int get_d() const;

	Fraber operator + (Fraber&);
	Fraber operator - (Fraber&);
	Fraber operator * (Fraber&);
	Fraber operator / (Fraber&);

	friend std::ostream& operator << (std::ostream&, const Fraber&);
};


