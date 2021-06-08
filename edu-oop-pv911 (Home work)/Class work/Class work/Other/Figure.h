#pragma once
#include <cmath>

class Figure
{
public:
	virtual double get_area() = 0;
	virtual ~Figure() = 0;
};


class Circle : public Figure
{
	double pi;
public:
	double r;

	Circle(double r) : pi(3.14), r(r) {}
	double get_area() override { return r * r * pi; }
};
 
class Rectangle_ : public Figure
{
public:
	double w;
	double h;

	Rectangle_(double w, double h) : w(w), h(h) {}
	double get_area() override { return w * h; }
};

class Right_triangle : public Figure
{
public:
	double a;

	Right_triangle(double a) : a(a) {}
	double get_area() override { return sqrt(3) / 4 * (a * a); }
};

