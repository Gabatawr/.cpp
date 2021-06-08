#pragma once

template <class T> class uptr
{
T* ptr;
	
public:
	uptr() : ptr(nullptr) {}
	explicit uptr(T* pointer) : ptr(pointer) {}
	
   ~uptr() { delete ptr; }

    uptr(const uptr&) = delete;
	uptr& operator = (const uptr&) = delete;

	uptr(const uptr&& other) noexcept
	{
		this->ptr = other.ptr;
		other.ptr = nullptr;
	}

	T& operator * () { return *ptr; }
	
	T* operator ->() { return  ptr; }
	T*         get() { return  ptr; }
	
	operator bool() const { return ptr; }

	void swap(uptr& other) noexcept
	{
		T* tmp = this->ptr;
		this->ptr = other.ptr;
		other.ptr = tmp;
	}

	T* release()
	{
		T* res = ptr;
		ptr = nullptr;
		return res;
	}
	
	void reset() { ptr = nullptr; }

	T& operator [] (size_t index) { return *(ptr + index); }
};

