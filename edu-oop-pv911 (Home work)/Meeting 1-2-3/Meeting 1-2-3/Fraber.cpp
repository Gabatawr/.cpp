#include "Fraber.h"


Fraber::Fraber()
{
	n = 0;
	d = 1;
}

Fraber::Fraber(const Fraber& other)
{
	this->n = other.n;
	this->d = other.d;
}



void Fraber::set_n(int numerator)
{
	this->n = numerator;
}

void Fraber::set_d(int denominator)
{
	this->d = denominator;
}



int Fraber::get_n() const
{
	return this->n;
}

int Fraber::get_d() const
{
	return this->d;
}



Fraber Fraber::operator + (Fraber& other)
{
	Fraber res;

	if (this->d == other.d)
	{
		res.d = this->d;
		res.n = this->n + other.n;
	}
	else if ((this->d < other.d ? other.d - this->d : this->d - other.d) < (this->d < other.d ? this->d : other.d))
	{
		res.d = this->d * other.d;
		res.n = this->n * other.d + other.n * this->d;
	}
	else if (this->d > other.d) 
	{
		res.d = this->d;
		res.n = this->n + other.n * (this->d / other.d);
	}
	else
	{
		res.d = other.d;
		res.n = this->n * (other.d / this->d) + other.n;
	}

	return res;
}

Fraber Fraber::operator - (Fraber& other)
{
	Fraber res;

	if (this->d == other.d)
	{
		res.d = this->d;
		res.n = this->n - other.n;
	}
	else if ((this->d < other.d ? other.d - this->d : this->d - other.d) < (this->d < other.d ? this->d : other.d))
	{
		res.d = this->d * other.d;
		res.n = this->n * other.d - other.n * this->d;
	}
	else if (this->d > other.d)
	{
		res.d = this->d;
		res.n = this->n - other.n * (this->d / other.d);
	}
	else
	{
		res.d = other.d;
		res.n = this->n * (other.d / this->d) - other.n;
	}
	
	return res;
}

Fraber Fraber::operator * (Fraber& other)
{
	Fraber res;

	res.d = this->d * other.d;
	res.n = this->n * other.n;
	
	return res;
}

Fraber Fraber::operator / (Fraber& other)
{
	Fraber res;

	res.d = this->d * other.n;
	res.n = this->n * other.d;

	return res;
}



std::ostream& operator << (std::ostream& out, const Fraber& fraber)
{
	return out << fraber.get_n() << "/" << fraber.get_d();
}