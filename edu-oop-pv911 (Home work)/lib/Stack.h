#pragma once

template <class T> class Stack;
template <class T> class Node
{
private:
	friend Stack<T>;

protected:
	Node<T>* next;

	Node()
	{
		next = nullptr;
	}
	explicit Node(T obj) : Node()
	{
		this->obj = obj;
	}

public:
	T obj;
};

template <class T> class Stack
{
protected:
	int _size;
	Node<T>* _head;

public:
	Stack()
	{
		_head = nullptr;
		_size = 0;
	}
	explicit Stack(T obj) : Stack()
	{
		_head = new Node<T>(obj);
		_size++;
	}
	Stack(const Stack<T>& other) : Stack()
	{
		Node<T>* cur = other._head;
		for (auto i = 0; i < other._size; i++, cur = cur->next) push(cur->obj);
	}
	
	int size() const
	{
		return _size;
	}
	bool empty() const
	{
		return _head == nullptr;
	}
	void clear()
	{
		while (_size) pop();
	}
	void remove()
	{
		while (_size) delete pop();
	}
	
	void push(T obj)
	{
		Node<T>* new_node = new Node<T>(obj);
		new_node->next = _head;
		_head = new_node;

		_size++;
	}
	T pop()
	{
		T ret = _head->obj;
		Node<T>* old_node = _head;
		_head = _head->next;
		delete old_node;

		_size--;
		return ret;
	}
	T head() const
	{
		return _head->obj;
	}

	T operator [] (int index)
	{
		if (_size == 0) return nullptr;
		
		if (index > _size - 1) index = _size - 1;
		else if (index < 0) index = 0;

		Node<T>* cur = _head;
		for (auto i = 0; i <= index; i++, cur = cur->next)  if (i == index) return cur->obj;
	}

	Stack<T>* clone()
	{
		Stack<T>* new_list = new_list(*this);
		return new_list;
	}
	Stack<T>& operator  = (const Stack<T>& other)
	{
		clear();
		for (auto i = other._size; i >= 0; --i) push(other[i]);
		return *this;
	}
	Stack<T>& operator += (const Stack<T>& other)
	{
		for (auto i = other._size; i >= 0; --i) push(other[i]);
		return *this;
	}
	Stack<T>  operator +  (const Stack<T>& other)
	{
		Stack<T> new_list = *this;

		for (auto i = other._size; i >= 0; --i) new_list.push(other[i]);

		return new_list;
	}
	Stack<T>  operator  * (const Stack<T>& other)
	{
		Stack<T> new_list;
		
		Stack<T>* left, right;
		if (this->_size <= other._size)
		{
			left = this;
			right = &other;
		}
		else
		{
			left = &other;
			right = this;
		}

		for (auto i = left->_size; i >= 0; --i)
		{
			for (auto j = right->_size; j >= 0; --j)
			{
				if (&(left[i]) == &(right[j]))
				{
					bool copy = false;
					
					for (auto k = new_list._size; k >= 0; --k)
					{
						if (&(right[i]) == &(new_list[k]))
						{
							copy = true;
							break;
						}
					}
					if (not copy) new_list.push(right[j]);
				}
			}
		}
		
		return new_list;
	}

};