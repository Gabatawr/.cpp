#pragma once

template <class T>
class Array
{
private:
	
	T** data;
	unsigned size;
	
#pragma region Constructors
public:
	
	explicit Array(unsigned size)
	{
		if (size == 0) size++;
		this->size = size;
		
		data = new T* [size];
		
		for (auto i = 0; i < size; i++) data[i] = new T;
	}

	explicit Array(unsigned size, T first, ...)
	{
		if (size == 0) size++;
		this->size = size;

		data = new T* [size];

		T* ptr = &first;
		for (unsigned i = 0; i < size; i++) data[i] = new T(*ptr++);
	}

	Array(const Array& other)
	{
		size = other.size;
		data = new T* [size];

		for (auto i = 0; i < size; i++) data[i] = new T(other[i]);
	}

#pragma endregion

#pragma region Destructor
public:
	
	~Array()
	{
		for (unsigned i = 0; i < size; i++) delete data[i];
		delete[] data;
	}
	
#pragma endregion
	
#pragma region Random
	
	public: void rand_int(bool unique = true, int min = 0, int max = 100)
	{
		for (unsigned i = 0; i < size; i++)
		{
			*data[i] = rand() % (max + 1 - min) + min;
			if (unique)   for (unsigned j = 0; j < i; j++) if (*data[i] == *data[j]) i--;
		}
	}
	
#pragma endregion
	
#pragma region Count

	#pragma region size

		public: int get_size() const
		{
			return size;
		}

	#pragma endregion

	#pragma region count copy
	
		public: int count_copy(T& key)
	{
		int count = 0;
		for (auto i = 0; i < size; i++) if (*data[i] == key) count++;
		return count;
	}
	
	#pragma endregion

#pragma endregion
	
#pragma region Sort
	
	public: void qSort(int first = -1, int last = -1)
	{
		if (first == -1) first = 0;
		if (last == -1) last = size - 1;
		
		if (first == last || size == 1) return;
		
		qSort_t(first < 0 || first == static_cast<int>(size - 1) ? 0 : first, last > static_cast<int>(size - 1) || last < 1 ? size - 1 : last);
	}
	private: void qSort_t(int first, int last)
	{
		int f = first;
		int l = last;
		T m = *data[(f + l) / 2];

		while (f < l)
		{
			while (*data[f] < m) f++;
			while (*data[l] > m) l--;

			if (f <= l)
			{
				T* tmp_ptr = data[f];
				data[f++] = data[l];
				data[l--] = tmp_ptr;
			}
		}

		if (first < l) qSort_t(first, l);
		if (f < last) qSort_t(f, last);
	}
	
#pragma endregion

#pragma region Search

	#pragma region bynary
	
		public: int bSearch(T& key, bool sorted, int first = -1, int last = -1)
		{
			if (first == -1) first = 0;
			if (last  == -1) last = size - 1;
			if (first == last) { if (*data[last] == key) return last; return -1; }
			
			if (not sorted) qSort();
		
			return bSearch_t(key, first < 0 || first == static_cast<int>(size - 1) ? 0 : first, last > static_cast<int>(size - 1) || last < 1 ? size - 1 : last);
		}
		private: int bSearch_t(T& key, int first, int last)
		{
			while (first <= last) {
				int mid = (first + last) / 2;

				if (*data[mid] == key) return mid;
				*data[mid] > key ? last = mid - 1 : first = mid + 1;
			}
			return -1;
		}
	
	#pragma endregion

	#pragma region linear

		/**
		 * @param way first '>' last
		 * @param way first '<' last
		 */
		public: int lSearch(T& key, char way = '>', int first = -1, int last = -1)
		{
			if (first == -1) first = 0;
			if (last  == -1) last = size - 1;
			if (first == last) { if (*data[last] == key) return last; return -1; }

			if (way != '>' && way != '<') way = '>';
			
			if (way == '>')
			{
				for (auto i = first < 0 || first == static_cast<int>(size - 1) ? 0 : first; i <= last > static_cast<int>(size - 1) || last < 1 ? size - 1 : last; i++)
				{
					if (*data[i] == key) return i;
					return -1;
				}
			}	
			else if (way == '>')
			{
				for (auto i = last > static_cast<int>(size - 1) || last < 1 ? size - 1 : last; i >= first < 0 || first == static_cast<int>(size - 1) ? 0 : first; i--)
				{
					if (*data[i] == key) return i;
					return -1;
				}
			}
		}

	#pragma endregion
	
#pragma endregion

#pragma region Put_Cut

	#pragma region put

		public: void put(T& key, int index = -1, unsigned length = 1)
		{
			if (index == -1 || index < 0 || index > size) index = size;
			if (length == 0) length++;
				
			T** old_data = data;
			size += length;
			data = new T*[size];

			auto i = 0;
			while (i++ < index) data[i] = old_data[i];
			while (length-- != 0) *data[i++] = key;
			while (i < size) data[i] = old_data[i - length];

			delete[] old_data;
		}

	#pragma endregion

	#pragma region cut

		public: void cut(int index = -1, unsigned length = 1)
		{
			if (index == -1 || index < 0 || index > size - 1) index = size - 1;
			if (length == 0) length++;

			T** old_data = data;
			size -= length;
			data = new T* [size];

			auto i = 0;
			while (i++ < index) data[i] = old_data[i];
			while (length-- != 0) delete old_data[i++];
			while (i - length < size) data[i - length] = old_data[i];

			delete[] old_data;
		}

	#pragma endregion

#pragma endregion

#pragma region Other

	#pragma region combine
	
		private: void combine_t(const Array& other)
		{
			size += other.size;
			T** old_data = data;
			data = new T* [size];

			for (auto i = 0; i < size - other.size; i++) data[i] = old_data[i];
			for (auto i = 0; i < size; i++) data[size - other.size + i] = new T(*other.data[i]);

			delete[] old_data;
		}

	#pragma endregion

	#pragma region max

		public: int elMax()
		{
			int max = 0;
			for (auto i = 1; i < size; i++) if (*data[i] > *data[max]) max = i;
			return max;
		}

	#pragma endregion

	#pragma region min

		public: int elMin()
		{
			int min = 0;
			for (auto i = 1; i < size; i++) if (*data[i] < *data[min]) min = i;
			return min;
		}

	#pragma endregion

#pragma endregion
	
#pragma region Operators
public:
	
	#pragma region =

		Array& operator = (const Array& other)
		{
			for (auto i = 0; i < size; i++) delete data[i];
			delete[] data;

			size = other.size;
			data = new T* [size];

			for (auto i = 0; i < size; i++) data[i] = new T(other[i]);

			return *this;
		}

		Array& operator = (const T& obj)
		{
			for (auto i = 0; i < size; i++) delete data[i];
			delete[] data;

			size = 1;
			data = new T* [size];

			data[0] = new T(obj);

			return *this;
		}

	#pragma endregion

	#pragma region +

		Array operator + (const T& obj)
		{
			Array res = *this;
			res.put(obj, size - 1);
			return res;
		}

		Array operator + (const Array& other)
		{
			Array res = *this;
			return res.combine_t(other);
		}

	#pragma endregion
	
	#pragma region +=

		Array& operator += (const T& obj)
		{
			put(obj, size - 1);
			return *this;
		}

		Array& operator += (const Array& other)
		{
			combine_t(other);
			return *this;
		}

	#pragma endregion

	#pragma region ++

		Array& operator ++ ()
		{
			T obj;
			put(obj, size - 1);
			return *this;
		}

		Array operator ++ (int)
		{
			T obj;
			put(obj, size - 1);
			return *this;
		}

	#pragma endregion

	#pragma region --

		Array& operator -- ()
		{
			cut(size - 1);
			return *this;
		}

		Array operator -- (int)
		{
			cut(size - 1);
			return *this;
		}

	#pragma endregion

	#pragma region []
	
		T& operator [] (unsigned index)
		{
			return *data[index];
		}
	
	#pragma endregion
	
#pragma endregion
	
};