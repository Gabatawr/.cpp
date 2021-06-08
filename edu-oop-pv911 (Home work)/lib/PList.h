#pragma once

template <class T> class PList;
template <class T> class PList_Node
{
private:
	friend PList<T>;

protected:
	PList_Node<T>* next;
	int _priority;

	PList_Node()
	{
		next = nullptr;
		_priority = 0;
	}
	explicit PList_Node(T obj, int priority = 0) : PList_Node()
	{
		this->obj = obj;
		_priority = priority;
	}

public:
	T obj;
	
	int get_priority() const
	{
		return _priority;
	}
};

template <class T> class PList
{
protected:
	int _size;
	PList_Node<T>* _head;
	PList_Node<T>* _tail;

public:
	PList_Node<T>* cur;

	PList()
	{
		_head = cur = _tail = nullptr;
		_size = 0;
	}
	PList(T obj, int priority = 0) : PList()
	{
		_tail = _head = cur = new PList_Node<T>(obj, priority);
		_size++;
	}
	PList(PList<T>& other) : PList()
	{
		PList_Node<T>* old_cur = other.cur;
		other.cur_to_head();

		for (auto i = 0; i < other._size; i++, ++other) push_tail(other.cur->obj, other.cur->_priority);

		other.cur = old_cur;
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
		while (_size) pop_head();
	}
	void remove()
	{
		while (_size) delete pop_head();
	}

	PList_Node<T>* cur_to_head()
	{
		return cur = _head;
	}
	PList_Node<T>* cur_to_pos(int index)
	{
		if (index <= 0) return cur_to_head();
		if (index >= this->_size - 1) return cur_to_tail();

		cur_to_head();
		for (auto i = 0; i <= index; i++, cur = cur->next)
			if (i == index) return cur;
	}
	PList_Node<T>* cur_to_tail()
	{
		return cur = _tail;
	}
	PList_Node<T>* peek_node(int index)
	{
		if (index < 0) index = 0;
		if (index > this->_size - 1) index = this->_size - 1;

		PList_Node<T>* old_cur = cur;
		PList_Node<T>* ret = cur_to_pos(index);
		cur = old_cur;
		return ret;
	}

	void push_head(T obj, int priority = 0)
	{
		PList_Node<T>* new_node = new PList_Node<T>(obj, priority);

		this->cur_to_head();
		if (cur != nullptr)
		{
			if (cur->_priority <= priority)
			{
				new_node->next = cur;
				_head = cur = new_node;
			}
			else
			{
				while (cur->next != nullptr && cur->next->_priority > priority) ++(*this);

				if (cur->next == nullptr) cur = cur->next = _tail = new_node;
				else
				{
					new_node->next = cur->next;
					cur = cur->next = new_node;
				}
			}
		}
		else _head = cur = _tail = new_node;

		_size++;
	}
	void push_tail(T obj, int priority = 0)
	{
		PList_Node<T>* new_node = new PList_Node<T>(obj, priority);

		cur_to_tail();
		if (cur != nullptr)
		{
			if (cur->_priority >= priority)
			{
				cur->next = new_node;
				cur = _tail = new_node;
			}
			else
			{
				this->cur_to_head();
				while (cur->next != nullptr && cur->next->_priority >= priority) ++(*this);

				if (cur->next == nullptr) cur = cur->next = _tail = new_node;
				else
				{
					new_node->next = cur->next;
					cur = cur->next = new_node;
				}
			}
		}
		else _head = cur = _tail = new_node;

		_size++;
	}

	T pop_head()
	{
		T ret = _head->obj;
		PList_Node<T>* old_node = _head;

		_head = _head->next;
		if (_head == nullptr) cur = _tail = nullptr;

		delete old_node;
		_size--;

		return ret;
	}
	T pop_pos(int index)
	{
		if (index <= 0) return pop_head();
		if (index >= this->_size - 1) return pop_tail();

		cur_to_pos(index - 1);

		T ret = cur->next->obj;
		PList_Node<T>* old_node = cur->next;

		cur->next = cur->next->next;

		delete old_node;
		_size--;

		return ret;
	}
	T pop_tail()
	{
		T ret = _tail->obj;
		PList_Node<T>* old_node = _tail;

		if (_head == _tail) _head = cur = _tail = nullptr;
		else _tail = cur_to_pos(this->_size - 2);

		delete old_node;
		_size--;

		return ret;
	}
	T pop_node(PList_Node<T>* node_ptr)
	{
		PList_Node<T>* old_cur = cur;

		cur_to_head();
		for (auto i = 0; i <= this->_size; i++, cur = cur->next)
			if (cur->next == node_ptr) break;

		T ret = cur->next->obj;
		cur->next = cur->next->next;

		delete node_ptr;
		cur = old_cur;
		_size--;

		return ret;
	}

	T head()
	{
		return _head->obj;
	}
	T tail()
	{
		return _tail->obj;
	}
	T operator [] (int index)
	{
		if (_size == 0) return nullptr;
		
		if (index <= 0) return this->head();
		if (index >= this->_size - 1) return this->tail();

		return cur_to_head(index)->obj;
	}
	
	void step(int count)
	{
		if (count <= 0) return;
		while (count-- > 0 && cur->next != nullptr) cur = cur->next;
	}
	PList_Node<T>* operator ++()
	{
		return cur = cur->next;
	}
	PList_Node<T>* operator ++(int)
	{
		return cur = cur->next;
	}

	PList<T>* clone()
	{
		PList<T>* new_list = new_list(*this);
		return new_list;
	}
	PList<T>& operator  = (PList<T>& other)
	{
		clear();

		PList_Node<T>* old_cur = other.cur;
		other.cur_to_head();

		for (auto i = 0; i < other._size; i++, ++other) push_tail(other.cur->obj, other.cur->_priority);

		other.cur = old_cur;
		return *this;
	}
	PList<T>& operator += (PList<T>& other)
	{
		PList_Node<T>* old_cur = other.cur;
		other.cur_to_head();

		for (auto i = 0; i < other._size; i++, ++other) push_head(other.cur->obj, other.cur->_priority);

		other.cur = old_cur;
		return *this;
	}
	PList<T>  operator +  (PList<T>& other)
	{
		PList<T> new_list = *this;

		PList_Node<T>* old_cur = other.cur;
		other.cur_to_head();

		for (auto i = 0; i < other._size; i++, ++other) new_list.push_head(other.cur->obj, other.cur->_priority);

		other.cur = old_cur;
		return new_list;
	}
	PList<T>  operator  * (PList<T>& other)
	{
		PList<T> new_list;

		PList_Node<T>* old_cur_this = this->cur; this->cur_to_head();
		PList_Node<T>* old_cur_other = other.cur; other.cur_to_head();

		PList<T>* left, right;
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

		for (auto i = 0; i < left->_size; i++, ++(*left))
		{
			for (auto j = 0; j < right->_size; j++, ++(*right))
			{
				if (left->cur == right->cur)
				{
					bool copy = false;
					new_list.cur_to_head();

					for (auto k = 0; k < new_list._size; k++, ++new_list)
					{
						if (right->cur == new_list.cur)
						{
							copy = true;
							break;
						}
					}
					if (not copy) new_list.push_head(right->cur->obj, other.cur->_priority);
				}
			}
		}

		this->cur = old_cur_this;
		other.cur = old_cur_other;

		return new_list;
	}
	
	void set_priority(int index, int new_priority = 0)
	{
		if (index < 0) index = 0;
		else if (index > this->_size - 1) index = this->_size - 1;

		if (this->peek_node(index)->_priority > new_priority) push_head(this->pop_pos(index), new_priority);
		else push_tail(this->pop_pos(index), new_priority);
	}
	void set_priority(PList_Node<T>* node_ptr, int new_priority = 0)
	{
		if (node_ptr == nullptr) return;

		if (node_ptr->_priority > new_priority) push_head(this->pop_node(node_ptr), new_priority);
		else push_tail(this->pop_node(node_ptr), new_priority);
	}
};