#pragma once

template <class T> class DList;
template <class T> class DList_Node
{
private:
	friend DList<T>;

protected:
	DList_Node<T>* next;
	DList_Node<T>* prev;

	DList_Node() : prev(nullptr), next(nullptr) {}
	explicit DList_Node(const T& obj)
		try : prev(nullptr), next(nullptr), obj(obj) {}
		catch (...) { std::cout << "\n oops, caught exception while creating node\n"; }
	
public:
	T obj;
};

template <class T> class DList
{
protected:
	int _size;
	DList_Node<T>* _head;
	DList_Node<T>* _tail;

public:
	DList_Node<T>* cur;

	DList() : _head(nullptr), cur(nullptr), _tail(nullptr), _size(0) {}
	explicit DList(T& obj) : DList()
	{
		try { _head = new DList_Node<T>(obj); } catch (...) {}
		
		if (_head)
		{
			_tail = cur = _head;
			_size++;
		}
	}
	DList(const DList<T>& other) : DList()
	{
		DList_Node<T>* old_cur = other.cur;
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
	
	DList_Node<T>* cur_to_head()
	{
		return cur = _head;
	}
	DList_Node<T>* cur_to_pos(int index)
	{
		if (index <= 0) return cur_to_head();
		if (index >= _size - 1) return cur_to_tail();

		if (index <= _size / 2)
		{
			cur_to_head();
			for (auto i = 0; i <= index; i++, cur = cur->next)
				if (i == index) return cur;
		}
		else
		{
			cur_to_tail();
			for (auto i = _size - 1; i >= index; --i, cur = cur->prev)
				if (i == index) return cur;
		}
	}
	DList_Node<T>* cur_to_tail()
	{
		return cur = _tail;
	}
	DList_Node<T>* peek_node(int index)
	{
		if (index < 0) index = 0;
		if (index > _size - 1) index = _size - 1;

		DList_Node<T>* old_cur = cur;
		DList_Node<T>* ret = cur_to_pos(index);
		cur = old_cur;
		return ret;
	}

	void push_head(T& obj)
	{
		DList_Node<T>* old_head = _head;
		try { _head = new DList_Node<T>(obj); } catch (...) {}

		if (_head)
		{
			if (old_head != nullptr) old_head->prev = _head;
			if (_tail == nullptr) _tail = _head;

			_head->next = old_head;
			_head->prev = nullptr;

			cur_to_head();
			_size++;
		}
		else _head = old_head;
	}
	void push_pos(T& obj, int index)
	{
		if (index <= 0) { push_head(obj); return; }
		if (index >= _size - 1) { push_tail(obj); return; }

		cur_to_head();
		for (auto i = 0; i < index; i++) ++(*this);
		
		DList_Node<T>* old_cur_next = cur->next;
		try { cur->next = new DList_Node<T>(obj); } catch (...) {}
		
		if (cur->next)
		{
			cur->next->next = old_cur_next;
			cur->next->prev = cur;
			old_cur_next->prev = cur->next;
			++(*this);

			_size++;
		}
		else cur->next = old_cur_next;
		
	}
	void push_tail(T& obj)
	{
		DList_Node<T>* old_tail = _tail;
		try { _tail = new DList_Node<T>(obj); } catch (...) {}
		
		if (_tail)
		{
			if (old_tail != nullptr) old_tail->next = _tail;
			if (_head == nullptr) _head = _tail;

			_tail->prev = old_tail;
			_tail->next = nullptr;

			cur_to_tail();
			_size++;
		}
		else _tail = old_tail;
	}

	T pop_head()
	{
		DList_Node<T>* old_node = _head;
		_head = _head->next;

		if (_head == nullptr) _tail = _tail->prev = nullptr;
		if (_head != nullptr) _head->prev = nullptr;

		cur_to_head();
		if (old_node != nullptr)
		{
			T pop_obj = old_node->obj;
			delete old_node;

			_size--;
			return pop_obj;
		}
		else return nullptr;
	}
	T pop_pos(int index)
	{
		if (index <= 0) return pop_head();
		if (index >= _size - 1) return pop_tail();

		cur_to_head();
		for (auto i = 0; i < index - 1; i++) ++(*this);

		DList_Node<T>* old_node = cur->next;
		cur->next->next->prev = cur;
		cur->next = old_node->next;

		if (old_node != nullptr)
		{
			T pop_obj = old_node->obj;
			delete old_node;

			_size--;
			return pop_obj;
		}
		else return nullptr;
	}
	T pop_tail()
	{
		DList_Node<T>* old_node = _tail;
		_tail = _tail->prev;

		if (_tail == nullptr) _head = _head->next = nullptr;
		if (_tail != nullptr) _tail->next = nullptr;

		cur_to_tail();
		if (old_node != nullptr)
		{
			T pop_obj = old_node->obj;
			delete old_node;

			_size--;
			return pop_obj;
		}
		else return nullptr;
	}
	T pop_node(DList_Node<T>* node_ptr, char way = '>')
	{
		DList_Node<T>* old_cur = cur;

		if (way == '>')
		{
			cur_to_head();
			for (auto i = 0; i <= _size; i++, cur = cur->next)
				if (cur->next == node_ptr) break;
		}
		else
		{
			cur_to_tail();
			for (auto i = _size - 1; i >= 0; --i, cur = cur->prev)
				if (cur->next == node_ptr) break;
		}

		if (cur->next == node_ptr && cur->next != nullptr)
		{
			T ret = cur->next->obj;
			cur->next = cur->next->next;
			cur->next->prev = cur;

			delete node_ptr;
			cur = old_cur;

			_size--;
			return ret;
		}
		else
		{
			cur = old_cur;
			return nullptr;
		}
	}
	
	T& head()
	{
		return _head->obj;
	}
	T& tail()
	{
		return _tail->obj;
	}
	T& operator [] (int index)
	{
		try { return t_obj_by_index(index); }
		catch (const char* n) { std::cout << n; }
	}

	void step(int count)
	{
		if (count < 0) for (auto i = -count; i > 0; --i) --(*this);
		else for (auto i = count; i > 0; --i) ++(*this);
	}
	DList_Node<T>* operator ++()
	{
		if (cur->next != nullptr) return cur = cur->next;
		return cur = _tail;
	}
	DList_Node<T>* operator ++(int)
	{
		if (cur->next != nullptr) return cur = cur->next;
		return cur = _tail;
	}
	DList_Node<T>* operator --()
	{
		if (cur->prev != nullptr) return cur = cur->prev;
		return cur = _head;
	}
	DList_Node<T>* operator --(int)
	{
		if (cur->prev != nullptr) return cur = cur->prev;
		return cur = _head;
	}

	DList<T>* clone()
	{
		DList<T>* new_list = new_list(*this);
		return new_list;
	}
	DList<T>& operator  = (const DList<T>& other)
	{
		clear();

		DList_Node<T>* old_cur = other.cur;
		other.cur_to_head();

		for (auto i = 0; i < other._size; i++, ++other) push_tail(other.cur->obj);

		other.cur = old_cur;
		return *this;
	}
	DList<T>& operator += (const DList<T>& other)
	{
		DList_Node<T>* old_cur = other.cur;
		other.cur_to_head();

		for (auto i = 0; i < other._size; i++, ++other) push_head(other.cur->obj);

		other.cur = old_cur;
		return *this;
	}
	DList<T>  operator +  (const DList<T>& other)
	{
		DList<T> new_list = *this;

		DList_Node<T>* old_cur = other.cur;
		other.cur_to_head();

		for (auto i = 0; i < other._size; i++, ++other) new_list.push_tail(other.cur->obj);

		other.cur = old_cur;
		return new_list;
	}
	DList<T>  operator  * (const DList<T>& other)
	{
		DList<T> new_list;

		DList_Node<T>* old_cur_this = this->cur; this->cur_to_head();
		DList_Node<T>* old_cur_other = other.cur; other.cur_to_head();

		DList<T>* left, right;
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

private:
	T& t_obj_by_index(int index)
	{
		if (_size == 0)         throw "\n oops, list is empty\n";
		if (index < 0)         throw "\n oops, index cannot be less than zero\n";
		if (index > _size - 1) throw "\n oops, index cannot be greater than or equal to the size\n";

		return cur_to_pos(index)->obj;
	}
};