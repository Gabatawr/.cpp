#include "File.h"


void File_BASE::init(const char*& path, unsigned& buffer_size)
{
	this->path = path;
	this->buffer_size = buffer_size;
	buffer = new char[buffer_size];
}

bool File_BASE::open()
{
	if (fopen_s(&f, path, "r") != 0)
	{
		std::cout << "\n The file '" << path << "' was not opened\n";
		return false;
	}
	return true;
}

void File_BASE::read()
{
	byte_read = fread(buffer, 1, buffer_size - 2, f);
}

void File_BASE::check_error()
{
	if (ferror(f) != 0) std::cout << "\n The file '" << path << "' was not readed\n";
}

void File_BASE::close()
{
	if (fclose(f) != 0) std::cout << "\n The file '" << path << "' was not closed\n";
}

void File_BASE::clear()
{
	path = ""; f = nullptr;
	buffer_size = byte_read = 0;
	delete[] buffer; buffer = nullptr;
}

void File_BASE::print(const char* path, unsigned buffer_size)
{
	init(path, buffer_size);
	if (not open()) { clear(); return; }
	read();
	print_t();
	check_error();
	close();
	clear();
}



void File_BASE::print_t()
{
	for (unsigned i = 0; i != byte_read; i++) std::cout << buffer[i];
}

void File_ASCII::print_t()
{
	for (unsigned i = 0; i != byte_read; i++) std::cout << static_cast<int>(buffer[i]) << " ";
}

void File_BINARY::print_t()
{
	for (unsigned i = 0; i != byte_read; i++)
	{
		unsigned n = 0, t = static_cast<int>(buffer[i]);
		for (auto j = 0; t; t /= 2) n += static_cast<unsigned>((t % 2) * pow(10, j++));
		std::cout << n << " ";
	}
}