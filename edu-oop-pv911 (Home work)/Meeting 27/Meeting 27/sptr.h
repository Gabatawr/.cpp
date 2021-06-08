#pragma once
template <class T> class sptr;
template <class T> class sptr_counter { friend sptr<T>; int counter = 0; };

template <class T> class sptr
{
T* ptr;
sptr_counter<T>* c_ptr;
	
public:
	sptr()                    : ptr(nullptr), c_ptr(new sptr_counter<T>) {}
	explicit sptr(T* pointer) : ptr(pointer), c_ptr(new sptr_counter<T>) { ++c_ptr->counter; }

	~sptr()
	{
		if (c_ptr != nullptr && --c_ptr->counter == 0)
		{
			delete ptr;
			delete c_ptr;
		}
	}

	sptr(const sptr& other)
	{
		this->c_ptr = other.c_ptr;
		this->ptr = other.ptr;
		
		++this->c_ptr->counter;
	}
	
	sptr& operator = (const sptr& other)
	{
		if (this->ptr == other.ptr) return *this;
		
		if (this->c_ptr != nullptr && --this->c_ptr->counter == 0)
		{
			delete ptr;
			delete c_ptr;
		}
		
		this->c_ptr = other.c_ptr;
		this->ptr = other.ptr;
		
		++this->c_ptr->counter;
		
		return *this;
	}

	sptr(const sptr&& other) noexcept
	{
		this->c_ptr = other.c_ptr;
		other.c_ptr = nullptr;
		
		this->ptr = other.ptr;
		other.ptr = nullptr;
	}

	T& operator * () { return *ptr; }

	T* operator ->() { return  ptr; }
	T* get() { return  ptr; }

	operator bool() const { return ptr; }

	void swap(sptr& other) noexcept
	{
		T* tmp = this->ptr;
		this->ptr = other.ptr;
		other.ptr = tmp;
		
		sptr_counter<T>* c_tmp = this->c_ptr;
		this->c_ptr = other.c_ptr;
		other.c_ptr = c_tmp;	
	}

	T* release()
	{
		if (this->c_ptr != nullptr && --this->c_ptr->counter == 0) delete c_ptr;

		T* res = ptr;
		
		ptr = nullptr;
		c_ptr = nullptr;
		
		return res;
	}

	void reset()
	{
		if (this->c_ptr != nullptr && --this->c_ptr->counter == 0)
		{
			delete ptr;
			delete c_ptr;
		}
		
		ptr = nullptr;
		c_ptr = nullptr;
	}

	T& operator [] (size_t index) { return *(ptr + index); }
};

