#pragma once

template <class T> class DPList;
template <class T> class DPList_Node
{
private:
	friend DPList<T>;
	
protected:
	DPList_Node<T>* next;
	DPList_Node<T>* prev;
	int _priority;

	DPList_Node()
	{
		prev = next = nullptr;
		_priority = 0;
	}
	explicit DPList_Node(T obj, int priority = 0) : DPList_Node()
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

template <class T> class DPList
{
protected:
	int _size;
	DPList_Node<T>* _head;
	DPList_Node<T>* _tail;

public:
	DPList_Node<T>* cur;

	DPList()
	{
		_head = cur = _tail = nullptr;
		_size = 0;
	}
	explicit DPList(T obj, int priority = 0) : DPList()
	{
		_tail = cur = _head = new DPList_Node<T>(obj, priority);
		_size++;
	}
	DPList(const DPList<T>& other) : DPList()
	{
		DPList_Node<T>* old_cur = other.cur;
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

	DPList_Node<T>* cur_to_head()
	{
		return cur = _head;
	}
	DPList_Node<T>* cur_to_pos(int index)
	{
		if (index <= 0) return this->cur_to_head();
		if (index >= this->_size - 1) return this->cur_to_tail();

		if (index <= this->_size / 2)
		{
			this->cur_to_head();
			for (auto i = 0; i <= index; i++, cur = cur->next)
				if (i == index) return cur;
		}
		else
		{
			this->cur_to_tail();
			for (auto i = this->_size - 1; i >= index; --i, cur = cur->prev)
				if (i == index) return cur;
		}
	}
	DPList_Node<T>* cur_to_tail()
	{
		return cur = _tail;
	}
	DPList_Node<T>* peek_node(int index)
	{
		if (index < 0) index = 0;
		if (index > this->_size - 1) index = this->_size - 1;

		DPList_Node<T>* old_cur = cur;
		DPList_Node<T>* ret = cur_to_pos(index);
		cur = old_cur;
		return ret;
	}
	
	void push_head(T obj, int priority = 0)
	{
		DPList_Node<T>* new_node = new DPList_Node<T>(obj, priority);

		this->cur_to_head();
		if (cur != nullptr)
		{
			if (cur->_priority <= priority)
			{
				new_node->next = cur;
				_head = cur = cur->next->prev = new_node;
			}
			else
			{
				while (cur->next != nullptr && cur->next->_priority > priority) ++(*this);

				if (cur->next == nullptr)
				{
					new_node->prev = cur;
					cur = cur->next = _tail = new_node;
				}
				else
				{
					new_node->next = cur->next;
					new_node->prev = cur;
					cur = cur->next = cur->next->prev = new_node;
				}
			}
		}
		else _head = cur = _tail = new_node;

		_size++;
	}
	void push_tail(T obj, int priority = 0)
	{
		DPList_Node<T>* new_node = new DPList_Node<T>(obj, priority);

		this->cur_to_tail();
		if (cur != nullptr)
		{
			if (cur->_priority >= priority)
			{
				new_node->prev = cur;
				cur = cur->next = _tail = new_node;
			}
			else
			{
				while (cur->prev != nullptr && cur->prev->_priority < priority) --(*this);

				if (cur->prev == nullptr)
				{
					new_node->prev = cur;
					cur = cur->prev = _head = new_node;
				}
				else
				{
					new_node->prev = cur->prev;
					new_node->next = cur;
					cur = cur->prev = cur->prev->next = new_node;
				}
			}
		}
		else _head = cur = _tail = new_node;

		_size++;
	}

	T pop_head()
	{
		DPList_Node<T>* old_node = _head;
		_head = _head->next;

		if (_head == nullptr) _tail = _tail->prev = nullptr;
		if (_head != nullptr) _head->prev = nullptr;

		this->cur_to_head();
		T pop_obj = old_node->obj;
		delete old_node;

		_size--;
		return pop_obj;
	}
	T pop_pos(int index)
	{
		if (index <= 0) return pop_head();
		if (index >= this->_size - 1) return pop_tail();

		this->cur_to_head();
		for (auto i = 0; i < index - 1; i++) ++(*this);

		DPList_Node<T>* old_node = cur->next;
		cur->next->next->prev = cur;
		cur->next = old_node->next;

		T pop_obj = old_node->obj;
		delete old_node;

		_size--;
		return pop_obj;
	}
	T pop_tail()
	{
		DPList_Node<T>* old_node = _tail;
		_tail = _tail->prev;

		if (_tail == nullptr) _head = _head->next = nullptr;
		if (_tail != nullptr) _tail->next = nullptr;

		this->cur_to_tail();
		T pop_obj = old_node->obj;
		delete old_node;

		_size--;
		return pop_obj;
	}
	T pop_node(DPList_Node<T>* node_ptr, char way = '>')
	{
		DPList_Node<T>* old_cur = cur;

		if (way == '>')
		{
			this->cur_to_head();
			for (auto i = 0; i <= this->_size; i++, cur = cur->next)
				if (cur->next == node_ptr) break;
		}
		else
		{
			this->cur_to_tail();
			for (auto i = this->_size - 1; i >= 0; --i, cur = cur->prev)
				if (cur->next == node_ptr) break;
		}

		T ret = cur->next->obj;
		cur->next = cur->next->next;
		cur->next->prev = cur;

		delete node_ptr;
		cur = old_cur;
		--(this->_size);

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

		return cur_to_pos(index)->obj;
	}

	void step(int count)
	{
		if (count < 0) for (auto i = -count; i > 0; --i) --(*this);
		else for (auto i = count; i > 0; --i) ++(*this);
	}
	DPList_Node<T>* operator ++()
	{
		if (cur->next != nullptr) return cur = cur->next;
		return cur = _tail;
	}
	DPList_Node<T>* operator ++(int)
	{
		if (cur->next != nullptr) return cur = cur->next;
		return cur = _tail;
	}
	DPList_Node<T>* operator --()
	{
		if (cur->prev != nullptr) return cur = cur->prev;
		return cur = _head;
	}
	DPList_Node<T>* operator --(int)
	{
		if (cur->prev != nullptr) return cur = cur->prev;
		return cur = _head;
	}

	DPList<T>* clone()
	{
		DPList<T>* new_list = new_list(*this);
		return new_list;
	}
	DPList<T>& operator  = (const DPList<T>& other)
	{
		clear();

		DPList_Node<T>* old_cur = other.cur;
		other.cur_to_head();

		for (auto i = 0; i < other._size; i++, ++other) push_tail(other.cur->obj, other.cur->_priority);

		other.cur = old_cur;
		return *this;
	}
	DPList<T>& operator += (const DPList<T>& other)
	{
		DPList_Node<T>* old_cur = other.cur;
		other.cur_to_head();

		for (auto i = 0; i < other._size; i++, ++other) push_head(other.cur->obj, other.cur->_priority);

		other.cur = old_cur;
		return *this;
	}
	DPList<T>  operator +  (const DPList<T>& other)
	{
		DPList<T> new_list = *this;

		DPList_Node<T>* old_cur = other.cur;
		other.cur_to_head();

		for (auto i = 0; i < other._size; i++, ++other) new_list.push_head(other.cur->obj, other.cur->_priority);

		other.cur = old_cur;
		return new_list;
	}
	DPList<T>  operator  * (const DPList<T>& other)
	{
		DPList<T> new_list;

		DPList_Node<T>* old_cur_this = this->cur; this->cur_to_head();
		DPList_Node<T>* old_cur_other = other.cur; other.cur_to_head();

		DPList<T>* left, right;
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
	void set_priority(DPList_Node<T>* node_ptr, int new_priority = 0)
	{
		if (node_ptr == nullptr) return;

		if (node_ptr->_priority > new_priority) push_head(this->pop_node(node_ptr), new_priority);
		else push_tail(this->pop_node(node_ptr), new_priority);
	}
};