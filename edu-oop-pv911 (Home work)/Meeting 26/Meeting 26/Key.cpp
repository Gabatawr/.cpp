#include "header.h"

Key* Key::ptr = nullptr;

Key::Key() : all(false), c(false), b(false), o(false), p(false), a(false) {}

Key* Key::Create()
{
	if (not ptr) ptr = new Key();
	return ptr;
}

void Key::Delete()
{
	if (ptr)
	{
		delete ptr;
		ptr = nullptr;
	}
}

void Key::set(string& commands)
{
    c = commands.find(static_cast<string>("-c")) != string::npos;
    b = commands.find(static_cast<string>("-b")) != string::npos;
    o = commands.find(static_cast<string>("-o")) != string::npos;
    p = commands.find(static_cast<string>("-p")) != string::npos;
    a = commands.find(static_cast<string>("-a")) != string::npos;

    all = not c && not b && not o && not p && not a;
}