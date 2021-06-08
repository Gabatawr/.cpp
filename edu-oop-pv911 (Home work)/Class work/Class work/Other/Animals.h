#pragma once

class animals
{
public:
	virtual void eat() = 0;
	virtual ~animals() = default;
};


class i_carnivorous
{
public:
	virtual void hunt() = 0;
	virtual ~i_carnivorous() = default;
};

class i_herbivorous
{
public:
	virtual void grass() = 0;
	virtual ~i_herbivorous() = default;
};


class Wolf : public animals, public i_carnivorous
{
	void eat() override
	{
		
	}
	void hunt() override
	{
		
	}
};

class Horse : public animals, public i_herbivorous
{
	void eat() override
	{

	}
	void grass() override
	{

	}
};
