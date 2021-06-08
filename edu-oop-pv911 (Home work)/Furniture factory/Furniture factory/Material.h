#pragma once

class Material
{
protected:
	int _size;
	
public:	
	Material();
	Material(int size);
	
	virtual int size() final;
	virtual void add(int size) final;
	virtual bool take(int size) final;

	virtual ~Material() = default;
};

class Textile : public Material
{
public:
	Textile() = default;
	Textile(int size) : Material(size) {}
};

class Wood : public Material
{
public:
	Wood() = default;
	Wood(int size) : Material(size) {}
};

class Metal : public Material
{
public:
	Metal() = default;
	Metal(int size) : Material(size) {}
};