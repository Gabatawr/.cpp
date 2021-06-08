#pragma once
#include <ostream>

template <class T> class List;
template <class T> class List_Node
{
private:
	friend List<T>;

protected:
	List_Node<T>* next;
	
	List_Node()
	{
		next = nullptr;
	}
	explicit List_Node(T obj) : List_Node()
	{
		this->obj = obj;
	}
	
public:
	T obj;
};

template <class T> class List
{
protected:
	int _size;
	List_Node<T>* _head;
	List_Node<T>* _tail;

public:
	List_Node<T>* cur;

	List()
	{
		_head = cur = _tail = nullptr;
		_size = 0;
	}
	explicit List(T obj) : List()
	{
		_tail = cur = _head = new List_Node<T>(obj);
		_size++;
	}
	List(List<T>& other) : List()
	{
		List_Node<T>* old_cur = other.cur;
		other.cur_to_head();

		for (auto i = 0; i < other._size; i++, ++other) push_tail(other.cur->obj);

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
	
	List_Node<T>* cur_to_head()
	{
		return cur = _head;
	}
	List_Node<T>* cur_to_pos(int index)
	{
		if (index <= 0) return cur_to_head();
		if (index >= this->_size - 1) return cur_to_tail();

		cur_to_head();
		for (auto i = 0; i <= index; i++, cur = cur->next)
			if (i == index) return cur;
	}
	List_Node<T>* cur_to_tail()
	{
		return cur = _tail;
	}
	List_Node<T>* peek_node(int index)
	{
		if (index < 0) index = 0;
		if (index > this->_size - 1) index = this->_size - 1;

		List_Node<T>* old_cur = cur;
		List_Node<T>* ret = cur_to_pos(index);
		cur = old_cur;
		return ret;
	}

	void push_head(T obj)
	{
		List_Node<T>* new_node = new List_Node<T>(obj);
		if (_head == nullptr)
		{
			_head = _tail = cur = new_node;
			_size++;
			return;
		}
		new_node->next = _head;

		_head = cur = new_node;
		if (_tail == nullptr) _tail = _head;

		_size++;
	}
	void push_pos(int index, T obj)
	{
		if (index <= 0) { push_head(obj); return; }
		if (index >= this->_size - 1) { push_tail(obj); return; }

		cur_to_pos(index - 1);
		List_Node<T>* new_node = new List_Node<T>(obj);
		new_node->next = cur->next;
		cur = cur->next = new_node;

		_size++;
	}
	void push_tail(T obj)
	{
		List_Node<T>* new_node = new List_Node<T>(obj);
		if (_head == nullptr)
		{
			_head = _tail = cur = new_node;
			_size++;
			return;
		}
		_tail->next = new_node;

		_tail = cur = new_node;
		if (this->_head == nullptr) this->_head = _tail;
		
		_size++;
	}

	T pop_head()
	{
		T ret = _head->obj;
		List_Node<T>* old_node = _head;

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
		List_Node<T>* old_node = cur->next;

		cur->next = cur->next->next;

		delete old_node;
		_size--;

		return ret;
	}
	T pop_tail()
	{
		T ret = _tail->obj;
		List_Node<T>* old_node = _tail;

		if (_head == _tail) _head = cur = _tail = nullptr;
		else _tail = cur_to_pos(this->_size - 2);

		delete old_node;
		_size--;

		return ret;
	}
	T pop_node(List_Node<T>* node_ptr)
	{
		List_Node<T>* old_cur = cur;

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

		return peek_node(index)->obj;
	}

	void step(int count)
	{
		if (count <= 0) return;
		while (count-- > 0 && cur->next != nullptr) cur = cur->next;
	}
	List_Node<T>* operator ++()
	{
		return cur = cur->next;
	}
	List_Node<T>* operator ++(int)
	{
		return cur = cur->next;
	}

	List<T>* clone()
	{
		List<T>* new_list = new_list(*this);
		return new_list;
	}
	List<T>& operator  = (List<T>& other)
	{
		clear();
		
		List_Node<T>* old_cur = other.cur;
		other.cur_to_head();

		for (auto i = 0; i < other._size; i++, ++other) push_tail(other.cur->obj);

		other.cur = old_cur;
		return *this;
	}
	List<T>& operator += (List<T>& other)
	{
		List_Node<T>* old_cur = other.cur;
		other.cur_to_head();

		for (auto i = 0; i < other._size; i++, ++other) push_head(other.cur->obj);

		other.cur = old_cur;
		return *this;
	}
	List<T>  operator +  (List<T>& other)
	{
		List<T> new_list = *this;

		List_Node<T>* old_cur = other.cur;
		other.cur_to_head();

		for (auto i = 0; i < other._size; i++, ++other) new_list.push_tail(other.cur->obj);

		other.cur = old_cur;
		return new_list;
	}
	List<T>  operator  * (List<T>& other)
	{
		List<T> new_list;

		List_Node<T>* old_cur_this = this->cur; this->cur_to_head();
		List_Node<T>* old_cur_other = other.cur; other.cur_to_head();

		List<T>* left, right;
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
					if (not copy) new_list.push_tail(right->cur->obj);
				}
			}
		}
		
		this->cur = old_cur_this;
		other.cur = old_cur_other;
		
		return new_list;
	}

	friend std::ostream& operator << (std::ostream& out, List<T>& list)
	{
		List_Node<T>* old_cur = list.cur;
		auto i = 0;
		
		for (list.cur_to_head(); list.cur != nullptr; ++list, i++) out << " #" << i << "\t" << *(list.cur->obj) << "\n";

		list.cur = old_cur;
		return out;
	}
};