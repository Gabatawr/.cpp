#include "Material.h"


Material::Material()
{
	_size = 0;
}
Material::Material(int size)
{
	_size = size;
}

int Material::size()
{
	return _size;
}

void Material::add(int size)
{
	this->_size += size;
}

bool Material::take(int size)
{
	if (_size < size) return false;
	this->_size -= size;
	return true;
}