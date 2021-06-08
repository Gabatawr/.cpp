#pragma once
#include <iostream>

template <class T>
class dlNode;

template <class T>
class dlList
{
private:
	dlNode<T>* head;
	dlNode<T>* tail;
public:
	dlNode<T>* iterator;

	dlList()
	{
		head = iterator = tail = nullptr;
	}

	explicit dlList(const T& obj)
	{
		head = new dlNode<T>(obj);
		tail = iterator = head;
	}

	void to_head()
	{
		iterator = head;
	}

	void to_tail()
	{
		iterator = tail;
	}

	bool is_empty()
	{
		if (head == nullptr) return true;
		return false;
	}

	void print_head(const char* splitter = ", ")
	{
		to_head();
		while (iterator != nullptr)
		{
			std::cout << iterator->obj;
			iterator = iterator->next;
			if (iterator != nullptr) std::cout << splitter;
		}
		to_head();
	}

	void print_tail(const char* splitter = ", ")
	{
		to_tail();
		while (iterator != nullptr)
		{
			std::cout << iterator->obj;
			iterator = iterator->prev;
			if (iterator != nullptr) std::cout << splitter;
		}
		to_tail();
	}

	int count()
	{
		to_head();
		auto i = 0; while (iterator != nullptr)
		{
			i++;
			iterator = iterator->next;
		}

		return i;
	}

	void push_head(const T& obj)
	{
		dlNode<T>* new_obj = new dlNode<T>(obj);
		
		dlNode<T>* old_head = head;
		if (old_head != nullptr) old_head->prev = new_obj;
		
		head = new_obj;
		if (tail == nullptr) tail = new_obj;
		
		head->next = old_head;
		head->prev = nullptr;
		
		to_head();
	}

	void push_tail(const T& obj)
	{
		dlNode<T>* new_obj = new dlNode<T>(obj);
		
		dlNode<T>* old_tail = tail;
		if (old_tail != nullptr) old_tail->next = new_obj;
		
		tail = new_obj;
		if (head == nullptr) head = new_obj;
		
		tail->prev = old_tail;
		tail->next = nullptr;
		
		to_tail();
	}

	T pop_head()
	{
		dlNode<T>* old_obj = head;
		head = head->next;
		
		if (head == nullptr) tail = tail->prev = nullptr;
		if (head != nullptr) head->prev = nullptr;
		
		T ret = *old_obj->obj;
		delete old_obj;

		to_head();
		return ret;
	}

	T pop_tail()
	{
		dlNode<T>* old_obj = tail;
		tail = tail->prev;
		
		if (tail == nullptr) head = head->next = nullptr;
		if (tail != nullptr) tail->next = nullptr;

		T ret = *old_obj->obj;
		delete old_obj;

		to_tail();
		return ret;
	}

	void clear()
	{
		while (head->next != nullptr)
		{
			dlNode<T>* old_obj = head;
			head = head->next;
			delete old_obj;
		}

		delete head;
		tail = iterator = head = nullptr;
	}
};



template <class T>
class dlNode
{
	friend class dlList<T>;

public:
	T* obj;
private:
	dlNode<T>* next;
	dlNode<T>* prev;

public:
	dlNode()
	{
		obj = prev = next = nullptr;
	}

	explicit dlNode(const T& obj)
	{
		this->obj = new T(obj);
		prev = next = nullptr;
	}
};