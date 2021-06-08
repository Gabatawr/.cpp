#pragma once
#include "header.h"

struct Key
{
public:  bool all, c, b, o, p, a;
	
		 static Key* Create();
		 static void Delete();
		 void set(string&);
	
		 ~Key() = default;
	
private: Key();
	
		 static Key* ptr;
	
		 Key(const Key*) = delete;
		 Key& operator = (const Key*) = delete;
};

static Key* key = Key::Create();