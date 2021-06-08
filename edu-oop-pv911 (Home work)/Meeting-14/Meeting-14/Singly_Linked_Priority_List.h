#pragma once

template <class T>
class Singly_Linked_Priority_List
{
	template <class T>
	class SLPL_Node
	{
	friend Singly_Linked_Priority_List;
		
		SLPL_Node<T>* next;
		int priority;

	public:
		T obj;

		SLPL_Node()
		{
			next = nullptr;
			priority = 0;
		}
		explicit SLPL_Node(T obj, int priority = 0) : SLPL_Node()
		{
			this->obj = obj;
			this->priority = priority;
		}

		int get_priority()
		{
			return priority;
		}
	};
	
	int slpl_size;
	SLPL_Node<T>* slpl_head;
	SLPL_Node<T>* slpl_tail;

public:
	SLPL_Node<T>* cur;

	Singly_Linked_Priority_List()
	{
		slpl_head = cur = slpl_tail = nullptr;
		slpl_size = 0;
	}
	explicit Singly_Linked_Priority_List(T obj, int priority = 0) : Singly_Linked_Priority_List()
	{
		slpl_head = new SLPL_Node<T>(obj, priority);
		slpl_tail = cur = slpl_head;
		slpl_size++;
	}

	bool empty() const
	{
		return slpl_head == nullptr;
	}

	int size() const
	{
		return slpl_size;
	}

	SLPL_Node<T>* cur_to_head()
	{
		return cur = slpl_head;
	}
	SLPL_Node<T>* cur_to_pos(int index)
	{
		if (index <= 0) return cur_to_head();
		if (index >= slpl_size - 1) return cur_to_tail();

		cur = slpl_head;

		for (auto i = 0; i <= index; i++, cur = cur->next)
			if (i == index) return cur;
	}
	SLPL_Node<T>* cur_to_tail()
	{
		return cur = slpl_tail;
	}

	SLPL_Node<T>* node_head()
	{
		return slpl_head;
	}
	SLPL_Node<T>* node_pos(int index)
	{
		if (index < 0) index = 0;
		if (index > slpl_size - 1) index = slpl_size - 1;
		
		SLPL_Node<T>* old_cur = cur;
		SLPL_Node<T>* ret = cur_to_pos(index);
		cur = old_cur;
		return ret;
	}
	SLPL_Node<T>* node_tail()
	{
		return slpl_tail;
	}
	
	void push_head(T obj, int priority = 0)
	{
		SLPL_Node<T>* new_node = new SLPL_Node<T>(obj, priority);
		
		cur_to_head();
		if (cur != nullptr)
		{
			if (cur->priority <= priority)
			{
				new_node->next = cur;
				slpl_head = cur = new_node;
			}
			else
			{
				while (cur->next != nullptr && cur->next->priority > priority) ++(*this);
				
				if (cur->next == nullptr) cur = cur->next = slpl_tail = new_node;
				else
				{
					new_node->next = cur->next;
					cur = cur->next = new_node;
				}
			}
		}
		else slpl_head = cur = slpl_tail = new_node;
		
		slpl_size++;
	}
	void push_tail(T obj, int priority = 0)
	{
		SLPL_Node<T>* new_node = new SLPL_Node<T>(obj, priority);

		cur_to_tail();
		if (cur != nullptr)
		{
			if (cur->priority >= priority)
			{
				cur->next = new_node;
				cur = slpl_tail = new_node;
			}
			else
			{
				cur_to_head();
				while (cur->next != nullptr && cur->next->priority >= priority) ++(*this);
				
				if (cur->next == nullptr) cur = cur->next = slpl_tail = new_node;
				else
				{
					new_node->next = cur->next;
					cur = cur->next = new_node;
				}
			}
		}
		else slpl_head = cur = slpl_tail = new_node;

		slpl_size++;
	}

	T pop_head()
	{
		T ret = slpl_head->obj;
		SLPL_Node<T>* old_node = slpl_head;

		slpl_head = slpl_head->next;
		if (slpl_head == nullptr) cur = slpl_tail = nullptr;

		delete old_node;
		slpl_size--;

		return ret;
	}
	T pop_pos(int index)
	{
		if (index <= 0) return pop_head();
		if (index >= slpl_size - 1) return pop_tail();

		cur_to_pos(index - 1);

		T ret = cur->next->obj;
		SLPL_Node<T>* old_node = cur->next;

		cur->next = cur->next->next;

		delete old_node;
		slpl_size--;

		return ret;
	}
	T pop_tail()
	{
		T ret = slpl_tail->obj;
		SLPL_Node<T>* old_node = slpl_tail;

		if (slpl_head == slpl_tail) slpl_head = cur = slpl_tail = nullptr;
		else
		{
			slpl_tail = cur_to_pos(slpl_size - 2);
			slpl_tail->next = nullptr;
		}

		delete old_node;
		slpl_size--;

		return ret;
	}

	T head() const
	{
		return slpl_head->obj;
	}
	T peek(int index)
	{
		if (index <= 0) return head();
		if (index >= slpl_size - 1) return tail();

		cur_to_head();
		for (auto i = 0; i <= index; i++, cur = cur->next)
			if (i == index) return cur->obj;
	}
	T tail() const
	{
		return slpl_tail->obj;
	}

	T operator [] (int index)
	{
		return peek(index);
	}

	void step(int count)
	{
		if (count <= 0) return;
		while (count-- > 0) if (cur->next != nullptr) cur = cur->next;
	}

	SLPL_Node<T>* operator ++()
	{
		if (cur->next != nullptr) return cur = cur->next;
		return cur = slpl_tail;
	}
	SLPL_Node<T>* operator ++(int)
	{
		if (cur->next != nullptr) return cur = cur->next;
		return cur = slpl_tail;
	}
	
	Singly_Linked_Priority_List<T> operator + (Singly_Linked_Priority_List<T>& other) const
	{
		Singly_Linked_Priority_List<T> new_list = *this;

		SLPL_Node<T>* old_cur = other.cur;
		other.cur_to_head();

		for (auto i = 0; i < other.slpl_size; i++, ++other) new_list.push_head(other.cur->obj, other.cur->priority);

		other.cur = old_cur;
		return new_list;
	}
	
	int get_priority(int index)
	{
		return node_pos(index)->priority;
	}
	void set_priority(int index, int new_priority = 0)
	{
		if (index < 0) index = 0;
		else if (index > slpl_size - 1) index = slpl_size - 1;

		if (node_pos(index)->priority > new_priority) push_head(pop_pos(index), new_priority);
		else push_tail(pop_pos(index), new_priority);
	}
};