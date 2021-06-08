#pragma once
#include <iostream>

enum type { rnd, z, a, b, c };

class Base
{
public:
	virtual void print() = 0;
	static Base* get(type = rnd);
};

class Z : public Base
{
public:
	void print() override;
};
class A : public Base
{
public:
	void print() override;
};
class B : public Base
{
public:
	void print() override;
};
class C : public Base
{
public:
	void print() override;
};
