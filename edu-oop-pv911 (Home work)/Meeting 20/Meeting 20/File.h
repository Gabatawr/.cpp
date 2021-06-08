#pragma once
#include <fstream>
#include <iostream>

constexpr auto BUFFER_SIZE = 1048576; // 1 Mbyte



class File_BASE
{
protected:
	FILE* f;
	const char* path;
	char* buffer;
	unsigned buffer_size;
	unsigned byte_read;

	virtual void init(const char*&, unsigned&) final;
	virtual bool open() final;
	virtual void read() final;
	virtual void check_error() final;
	virtual void close() final;
	virtual void clear() final;

	virtual void print_t();
	
public:
	File_BASE() : f(nullptr), path(""), buffer(nullptr), buffer_size(0), byte_read(0) {}
	virtual void print(const char*, unsigned = BUFFER_SIZE) final;
	virtual ~File_BASE() = default;
};


class File_ASCII : public File_BASE
{
protected:
	void print_t() override;
};

class File_BINARY : public File_BASE
{
protected:
	void print_t() override;
};