#pragma once

class Square
{
protected: int a;
public:
	Square(int a) { this->a = a; }
	int get_a() const {return a; }
};

class Circle
{
protected: double r;
public:
	Circle(double r){ this->r = r; }
	double get_r() const{ return r; }
};

class Circle_in_Square : public Square, public Circle
{
public:
	Circle_in_Square(int a) : Square(a), Circle(double(a) / 2) {}
	Circle_in_Square(double r) : Square(int(r * 2)), Circle(r) {}
};