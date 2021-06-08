#pragma once
#include <iostream>

template <class T>
class slNode;

template <class T>
class slList
{	
private:
	slNode<T>* root;
public:
	slNode<T>* iterator;

	slList()
	{
		root = nullptr;
		iterator = nullptr;
	}
	
	explicit slList(const T& obj)
	{
		root = new slNode<T>(obj);
		iterator = root;
	}

	void go_root()
	{
		iterator = root;
	}

	bool is_empty()
	{
		if (root == nullptr) return true;
		return false;
	}

	void print(const char* splitter = ", ")
	{
		go_root();
		while (iterator != nullptr) 
		{
			std::cout << iterator->obj;
			iterator = iterator->next;
			if (iterator != nullptr) std::cout << splitter;
		}
		go_root();
	}

	int count()
	{
		go_root();
		auto i = 0; while (iterator != nullptr)
		{
			i++;
			iterator = iterator->next;
		}
		go_root();

		return i;
	}
	
	void push(const T& obj)
	{
		slNode<T>* new_obj = new slNode<T>(obj);
		new_obj->next = root;
		root = new_obj;
	}

	T pop()
	{
		slNode<T>* old_obj = root;
		root = root->next;

		T ret = old_obj->obj;
		delete old_obj;
		return ret;
	}

	void clear()
	{
		while (root->next != nullptr)
		{
			slNode<T>* old_obj = root;
			root = root->next;
			delete old_obj;
		}
		
		delete root;
		iterator = root = nullptr;
	}
};



template <class T>
class slNode
{
friend class slList<T>;
	
public:
	T obj;
private:
	slNode<T>* next;

public:
	slNode()
	{
		next = nullptr;
	}

	explicit slNode(const T& obj)
	{
		this->obj = obj;
		next = nullptr;
	}
};