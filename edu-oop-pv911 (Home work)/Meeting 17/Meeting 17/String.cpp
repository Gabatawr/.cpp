#include "String.h"


#pragma region Constructors

	String::String()
	{
		size = 1;
		line = new char[size];
		
		line[size - 1] = '\0';
		
		created_now++;
		created_all++;
	}

	String::String(const char* str)
	{
		int len = 0;
		while (str[len++] != '\0');
		size = len;

		line = new char[size];
		for (auto i = 0; i < static_cast<int>(size); i++) line[i] = str[i];

		created_now++;
		created_all++;
	}

	String::String(char symbol, unsigned size)
	{
		if (size == 0) size++;
		this->size = ++size;
		
		line = new char[this->size];

		for (auto i = 0; i < static_cast<int>(this->size - 1); i++) line[i] = symbol;
		line[this->size - 1] = '\0';

		created_now++;
		created_all++;
	}

	String::String(char* array, unsigned size)
	{
		if (size == 0) size++;
		this->size = ++size;

		line = new char[this->size];
		
		for (auto i = 0; i < static_cast<int>(size - 1); i++) line[i] = array[i];
		line[this->size - 1] = '\0';

		created_now++;
		created_all++;
		
	}

	String::String(int number)
	{
		bool negative = false;
		int count = 0;
		
		if (number < 0)
		{
			negative = true;
			number = -number;
			count++;
		}
		else if (number == 0) count++;
		
		for (int tmp = number; tmp > 0; count++) tmp /= 10;

		size = count + 1;
		line = new char[size];
		
		for (auto i = count - 1; i > -1; i--)
		{
			line[i] = static_cast<char>(number % 10 + 48);
			number /= 10;
		}
		
		if (negative) line[0] = '-';
		line[size - 1] = '\0';

		created_now++;
		created_all++;
	}

	String::String(double number, unsigned accuracy)
	{
		bool negative = false;
		int count = static_cast<int>(accuracy) + 1;
		
		if (number < 0)
		{
			negative = true;
			number = -number;
			count++;
		}
		else if (number == 0) count++;
		
		for (int tmp = static_cast<int>(number); tmp > 0; count++) tmp /= 10;

		int digits = static_cast<int>(number);
		double tmp_reverse_digits = 0;
		for (auto i = 0; i < static_cast<int>(count - accuracy - 1); i++)
		{
			tmp_reverse_digits = (tmp_reverse_digits + static_cast<double>(digits % 10) / 10) * 10;
			digits /= 10;
		}
		int reverse_digits = static_cast<int>(tmp_reverse_digits);

		int fraction = static_cast<int>(static_cast<double>(number - static_cast<int>(number) + (1 / pow(100, accuracy))) * pow(10, accuracy));
		double tmp_reverse_fraction = 0;
		for (auto i = 0; i < static_cast<int>(accuracy); i++)
		{
			tmp_reverse_fraction = (tmp_reverse_fraction + static_cast<double>(fraction % 10) / 10) * 10;
			fraction /= 10;
		}
		int reverse_fraction = static_cast<int>(tmp_reverse_fraction);

		size = count + 1;
		line = new char[size];
		
		for (auto i = 0, tmp = static_cast<int>(size - 1 - accuracy - 1); i < static_cast<int>(size - 1); i++)
		{
			if (i < tmp)
			{
				line[i] = static_cast<char>(reverse_digits % 10 + 48);
				reverse_digits /= 10;
			}
			if (i == tmp) line[i] = '.';
			if (i > tmp)
			{
				line[i] = static_cast<char>(reverse_fraction % 10 + 48);
				reverse_fraction /= 10;
			}
		}

		if (negative) line[0] = '-';
		line[size - 1] = '\0';

		created_now++;
		created_all++;
	}

	String::String(const String& other)
	{
		size = other.size;
		line = new char[size];
		
		for (auto i = 0; i < static_cast<int>(size); i++) line[i] = other.line[i];
		
		created_now++;
		created_all++;
	}

#pragma endregion

#pragma region Destructor

	String::~String()
	{
		delete[] line;
		created_now--;
	}

#pragma endregion

#pragma region Static

	#pragma region Variables

		int String::created_now = 0;
		int String::created_all = 0;

	#pragma endregion

	#pragma region Functions

		int String::get_created_now()
		{
			return created_now;
		}

		int String::get_created_all()
		{
			return created_all;
		}

	#pragma endregion

#pragma endregion

#pragma region Put

	void String::put(const char& symbol, unsigned index, unsigned length)
		{
			size += length;
			char* old_line = line;
			line = new char[size];

			for (auto i = 0; i < static_cast<int>(size); i++)
			{
				if (i < static_cast<int>(index)) line[i] = old_line[i];
				else if (i > static_cast<int>(index + length - 1)) line[i] = old_line[i - length];
				else line[i] = symbol;
			}

			delete[] old_line;
		}

	void String::put(const char* str, unsigned index)
		{
			int len = 0;
			while (str[len] != '\0') len++;
			
			size += len;
			char* old_line = line;
			line = new char[size];

			for (auto i = 0; i <= static_cast<int>(size); i++)
			{
				if (i < static_cast<int>(index)) line[i] = old_line[i];
				else if (i == index) for (auto j = 0; j < len; j++) line[i++] = str[j];
				else line[i - 1] = old_line[i - len - 1];
			}

			delete[] old_line;
		}

	void String::put(const String& other, unsigned index)
		{
			int len = other.size - 1;

			size += len;
			char* old_line = line;
			line = new char[size];

			for (auto i = 0; i <= static_cast<int>(size); i++)
			{
				if (i < static_cast<int>(index)) line[i] = old_line[i];
				else if (i == static_cast<int>(index)) for (auto j = 0; j < len; j++) line[i++] = other.line[j];
				else line[i - 1] = old_line[i - len - 1];
			}

			delete[] old_line;
		}

#pragma endregion

#pragma region Cut

	void String::cut(unsigned index, unsigned range_size)
	{
		size -= range_size;
		char* old_line = line;
		line = new char[size];

		for (auto i = 0; i < static_cast<int>(size); i++)
		{
			if (i < static_cast<int>(index)) line[i] = old_line[i];
			else line[i] = old_line[i + range_size];
		}

		delete[] old_line;
	}

	void String::cut(const char& symbol)
	{
		size -= this->count_symbol(symbol);
		char* old_line = line;
		line = new char[size];

		for (auto i = 0, j = 0; j < static_cast<int>(size); i++) if (old_line[i] != symbol) line[j++] = old_line[i];
			
		delete[] old_line;
	}

#pragma endregion

#pragma region Count

	int String::len() const
	{
		return static_cast<int>(size - 1);
	}

	int String::count_letters() const
	{
		int count = 0;
		for (auto i = 0; i < static_cast<int>(size); i++)
			if ((line[i] >= 65 && line[i] <= 90) || (line[i] >= 97 && line[i] <= 122)) count++;
		return count;
	}

	int String::count_digits() const
	{
		int count = 0;
		for (auto i = 0; i < static_cast<int>(size); i++) if (line[i] >= 48 && line[i] <= 57) count++;
		return count;
	}

	int String::count_numbers() const
	{
		int count = 0;
		for (auto i = 0; i < static_cast<int>(size); i++)
		{
			bool flag = false;

			int digits = i;
			while (line[i] >= 48 && line[i] <= 57) {
				flag = true;
				i++;
			}
			digits = i - digits;

			if (digits > 0) count++;
			if (flag) i--;
		}
		return count;
	}

	int String::count_symbol(char symbol) const
	{
		int count = 0;
		for (auto i = 0; i < static_cast<int>(size); i++) if (line[i] == symbol) count++;
		return count;
	}

	int String::count_word(const char* str) const
	{
		int len = 0;
		while (str[len++] != '\0');
		len--;

		int count = 0;
		for (auto i = 0, j = 0; i < static_cast<int>(size); i++, j = 0)
		{
			bool trigger = false;
			while (line[i] == str[j] && j < len)
			{
				i++; j++;
				trigger = true;
				if (j == len) count++;
			}
			if (trigger) i--;
		}
		return count;
	}

	int String::count_word(char* array, unsigned size) const
	{
		int count = 0;
		for (auto i = 0, j = 0; i < static_cast<int>(this->size); i++, j = 0)
		{
			bool trigger = false;
			while (line[i] == array[j] && j < static_cast<int>(size))
			{
				i++; j++;
				trigger = true;
				if (j == size) count++;
			}
			if (trigger) i--;
		}
		return count;
	}

	int String::count_word(String& other) const
	{
		int count = 0;
		for (auto i = 0, j = 0; i < static_cast<int>(size); i++, j = 0)
		{
			bool trigger = false;
			while (line[i] == other.line[j] && j < other.len())
			{
				i++; j++;
				trigger = true;
				if (j == other.len()) count++;
			}
			if (trigger) i--;
		}
		return count;
	}

#pragma endregion 

#pragma region Other

	void String::replace(String& old_w, String& new_w)
	{
		for (auto i = 0, j = 0; i < this->size; i++, j = 0)
		{
			while (this->line[i] == old_w.line[j] && j < old_w.len())
			{
				bool flag = false;
				if (j == old_w.len() - 1)
				{
					if (old_w.len() != new_w.len())
					{
						if (old_w.len() > new_w.len()) cut(i, old_w.len() - new_w.len());
						else this->put('#', i + 1, new_w.len() - old_w.len());
					}

					i = i - old_w.len() + 1;
					for (auto k = 0; k < new_w.len(); k++, i++) this->line[i] = new_w.line[k];
					flag = true;
				}
				if (flag) j = 0;
				else { i++; j++; }
			}
		}
	}

	void String::replace(char& old_symbol, char& new_symbol) const
	{
		for (auto i = 0; i < static_cast<int>(size); i++) if (line[i] == old_symbol) line[i] = new_symbol;
	}

	void String::capital_letters() const
	{
		char arr_end_sym[4] = { '.', '!', '?', ';' };
		for (auto i = 0; this->line[i] != '\0'; i++)
		{
			bool is_lower = false, is_new = false;
			if (this->line[i] >= 97 && this->line[i] <= 122) is_lower = true;
			if (i != 0 && is_lower && this->line[i - 1] == ' ')
			{
				for (char j : arr_end_sym)
					if (this->line[i - 2] == j) is_new = true;
			}

			if (is_lower && i == 0 || is_lower && is_new) this->line[i] = static_cast<char>(this->line[i] - 32);
		}
	}

	void String::uppercase() const
	{
		for (auto i = 0; i < static_cast<int>(size); i++)
			if (line[i] >= 97 && line[i] <= 122) line[i] = static_cast<char>(line[i] - 32);
	}

	void String::lowercase() const 
	{
		for (auto i = 0; i < static_cast<int>(size); i++)
			if (line[i] >= 65 && line[i] <= 90) line[i] = static_cast<char>(line[i] + 32);
	}

	void String::reverse() const
	{
		for (auto i = 0; i < static_cast<int>(size - 1) / 2; i++)
		{
			char tmp = line[i];
			line[i] = line[size - 2 - i];
			line[size - 2 - i] = tmp;
		}
	}

	void String::clear()
	{
		delete[] line;

		size = 1;
		line = new char[size];
		line[size - 1] = '\0';
	}

	bool String::empty() const
	{
		if (size == 1 && line[0] == '\0') return true;
		return false;
	}

	bool String::has(const char* str) const
	{
		int len = 0;
		while (str[len++] != '\0');
		len--;

		for (auto i = 0, j = 0; i < static_cast<int>(size); i++, j = 0)
		{
			while (line[i] == str[j] && j < len)
			{
				i++; j++;
				if (j == len) return true;
			}
		}
		return false;
	}

	bool String::has(char* array, unsigned size) const
	{
		for (auto i = 0, j = 0; i < static_cast<int>(this->size); i++, j = 0)
		{
			while (line[i] == array[j] && j < static_cast<int>(size))
			{
				i++; j++;
				if (j == size) return true;
			}
		}
		return false;
	}

	bool String::has(String& other) const
	{
		for (auto i = 0, j = 0; i < static_cast<int>(this->size); i++, j = 0)
		{
			while (line[i] == other.line[j] && j < other.len())
			{
				i++; j++;
				if (j == other.len()) return true;
			}
		}
		return false;
	}

	int String::fpos(const char* str) const
	{
		int len = 0;
		while (str[len++] != '\0');
		len--;
			
		for (auto i = 0, j = 0; i < static_cast<int>(size); i++, j = 0)
		{
			while (line[i] == str[j] && j < len)
			{
				if (j == len - 1) return i - len + 1;
				i++; j++;
			}
		}
		return -1;
	}

	int String::fpos(char* array, unsigned size) const
	{
		for (auto i = 0, j = 0; i < static_cast<int>(this->size); i++, j = 0)
		{
			while (line[i] == array[j] && j < static_cast<int>(size))
			{
				if (j == size - 1) return i - size + 1;
				i++; j++;
			}
		}
		return -1;
	}

	int String::fpos(String& other) const
	{
		for (auto i = 0, j = 0; i < static_cast<int>(this->size); i++, j = 0)
		{
			while (line[i] == other.line[j] && j < other.len())
			{
				if (j == other.len() - 1) return i - other.len() + 1;
				i++; j++;
			}
		}
		return -1;
	}

	int String::lpos(const char* str) const
	{
		int len = 0;
		while (str[len++] != '\0');
		len--;
			
		for (auto i = static_cast<int>(this->len()), j = len; i >= 0; i--, j = len)
		{
			while (line[i] == str[j] && j >= 0)
			{
				if (j == 0) return i;
				i--; j--;
			}
		}
		return -1;
	}

	int String::lpos(char* array, unsigned size) const
	{
		for (auto i = static_cast<int>(this->len()), j = static_cast<int>(size); i >= 0; i--, j = size)
		{
			while (line[i] == array[j] && j >= 0)
			{
				if (j == 0) return i;
				i--; j--;
			}
		}
		return -1;
	}

	int String::lpos(String& other) const
	{
		for (auto i = static_cast<int>(this->len()), j = static_cast<int>(other.len()); i >= 0; i--, j = other.len())
		{
			while (line[i] == other.line[j] && j >= 0)
			{
				if (j == 0) return i;
				i--; j--;
			}
		}
		return -1;
	}

	String String::between(char symbol) const
	{
		int start = -1, end = -1;

		for (auto i = 0; i < static_cast<int>(size); i++)
		{
			if (line[i] == symbol)
			{
				if (start == -1) start = i;
				else { end = i; break; }
			}
		}

		String ret;
		if (start == -1 || end == -1) return ret;

		char* tmp = new char[end - start];
		for (auto i = start + 1; i < end; i++) tmp[i - (start + 1)] = line[i];
		tmp[end - start - 1] = '\0';

		ret += tmp;
		delete[] tmp;

		return ret;
	}

	int String::to_int(unsigned number_in_row) const
	{
		double number = 0;
		for (auto i = 0, count = 0; i < static_cast<int>(size); i++)
		{
			bool flag = false;

			int digits = i;
			while (line[i] >= 48 && line[i] <= 57) {
				flag = true;
				i++;
			}
			digits = i - digits;

			if (digits > 0) count++;

			if (count == number_in_row)
			{
				i -= digits;
				for (auto j = 0; j < digits; j++, i++)
				{
					number += static_cast<double>(line[i] - 48) / 10;
					number *= 10;
				}
				return static_cast<int>(number);
			}
			if (flag) i--;
		}
		return 0;
	}

	double String::to_double(unsigned number_in_row) const
	{
		double number = 0;
		for (auto i = 0, count = 0; i < static_cast<int>(size); i++)
		{
			bool flag = false;

			int digits = i;
			while (line[i] >= 48 && line[i] <= 57) { flag = true; i++; }
			digits = i - digits;

			int fraction = i;
			if (digits > 0 && (line[i] == 46 || line[i] == 44))
			{
				i++; while (line[i] >= 48 && line[i] <= 57) i++;
			}
			fraction = i - fraction - 1;

			if (digits > 0) count++;

			if (count == number_in_row)
			{
				i -= digits + 1 + fraction;
				for (auto j = 0; j < digits + 1 + fraction; j++, i++)
				{
					if (j < digits) number = (number + static_cast<double>(line[i] - 48) / 10) * 10;
					if (j > digits) number += static_cast<double>(line[i] - 48) / pow(10, j - digits);
				}
				return number;
			}
			if (flag) i--;
		}
		return 0;
	}

	String String::shorten(unsigned length)
	{
		String new_str('#', length);
		for (auto i = 0; i < static_cast<int>(length); i++) new_str.line[i] = line[i];
		return new_str;
	}

#pragma endregion

#pragma region Operators

	#pragma region =

		String& String::operator = (const char* str)
		{
			delete[] line;

			int len = 0;
			while (str[len++] != '\0');
			size = len;

			line = new char[size];
			for (auto i = 0; i < static_cast<int>(size); i++) line[i] = str[i];

			return *this;
		}

		String& String::operator = (const char& symbol)
		{
			delete[] line;

			size = 2;
			line = new char[size];

			for (auto i = 0; i < static_cast<int>(size - 1); i++) line[i] = symbol;
			line[size - 1] = '\0';
			
			return *this;
		}

		String& String::operator = (int number)
		{
			delete[] line;

			bool negative = false;
			int len = 0;

			if (number < 0)
			{
				negative = true;
				number = -number;
				len++;
			}
			else if (number == 0) len++;

			for (int tmp = number; tmp > 0; len++) tmp /= 10;

			size = len + 1;
			line = new char[size];

			for (auto i = len - 1; i > -1; i--)
			{
				line[i] = static_cast<char>(number % 10 + 48);
				number /= 10;
			}

			if (negative) line[0] = '-';
			line[size - 1] = '\0';
			
			return *this;
		}

		String& String::operator = (double number)
		{
			delete[] line;
			unsigned accuracy = 2;

			bool negative = false;
			int len = static_cast<int>(accuracy) + 1;

			if (number < 0)
			{
				negative = true;
				number = -number;
				len++;
			}
			else if (number == 0) len++;

			for (int tmp = static_cast<int>(number); tmp > 0; len++) tmp /= 10;

			int digits = static_cast<int>(number);
			double tmp_reverse_digits = 0;
			for (auto i = 0; i < static_cast<int>(len - accuracy - 1); i++)
			{
				tmp_reverse_digits = (tmp_reverse_digits + static_cast<double>(digits % 10) / 10) * 10;
				digits /= 10;
			}
			int reverse_digits = static_cast<int>(tmp_reverse_digits);

			int fraction = static_cast<int>(static_cast<double>(number - static_cast<int>(number) + (1 / pow(100, accuracy))) * pow(10, accuracy));
			double tmp_reverse_fraction = 0;
			for (auto i = 0; i < static_cast<int>(accuracy); i++)
			{
				tmp_reverse_fraction = (tmp_reverse_fraction + static_cast<double>(fraction % 10) / 10) * 10;
				fraction /= 10;
			}
			int reverse_fraction = static_cast<int>(tmp_reverse_fraction);

			size = len + 1;
			line = new char[size];

			for (auto i = 0, tmp = static_cast<int>(size - 1 - accuracy - 1); i < static_cast<int>(size - 1); i++)
			{
				if (i < tmp)
				{
					line[i] = static_cast<char>(reverse_digits % 10 + 48);
					reverse_digits /= 10;
				}
				if (i == tmp) line[i] = '.';
				if (i > tmp)
				{
					line[i] = static_cast<char>(reverse_fraction % 10 + 48);
					reverse_fraction /= 10;
				}
			}

			if (negative) line[0] = '-';
			line[size - 1] = '\0';
			
			return *this;
		}

		String& String::operator = (const String& other)
		{
			delete[] this->line;

			this->size = other.size;
			this->line = new char[this->size];

			for (auto i = 0; i < static_cast<int>(this->size); i++) this->line[i] = other.line[i];
			
			return *this;
		}

	#pragma endregion

	#pragma region +

		String String::operator + (const char* str) const
		{
			String new_obj(*this);
			new_obj += str;
			return new_obj;
		}

		String String::operator + (char& symbol) const
		{
			String new_obj(*this);
			new_obj += symbol;
			return new_obj;
		}

		String String::operator + (int& number) const
		{
			String new_obj(number);
			new_obj.put(*this, 0);
			return new_obj;
		}

		String String::operator + (double& number) const
		{
			String new_obj(number);
			new_obj.put(*this, 0);
			return new_obj;
		}

		String String::operator + (String& other) const
		{
			String new_obj(*this);
			new_obj += other;
			return new_obj;
		}

	#pragma endregion

	#pragma region +=

		String& String::operator += (unsigned length)
		{
			this->put('#', this->len(), length);
			return *this;
		}

		String& String::operator += (const char* str)
		{
			this->put(str, this->len());
			return *this;
		}

		String& String::operator += (const char& symbol)
		{
			this->put(symbol, this->len());
			return *this;
		}

		String& String::operator += (const String& other)
		{
			this->put(other, this->len());
			return *this;
		}

		String& String::operator += (const int& number)
		{
			String num = number;
			this->put(num, this->len());
			return *this;
		}

	#pragma endregion

	#pragma region -=

		String& String::operator -= (unsigned length)
		{
			this->cut(this->len() - length, length);
			return *this;
		}

		String& String::operator -= (const char* str)
		{
			int len = 0;
			while (str[len++] != '\0');
			len--;

			for (auto i = 0, j = 0; i < static_cast<int>(size); i++, j = 0)
			{
				while (line[i] == str[j] && j < len)
				{
					i++; j++;
					if (j == len)
					{
						this->cut(i - len, len);
						i -= len;
					}
				}
			}
			
			return *this;
		}

		String& String::operator -= (const char& symbol)
		{
			this->cut(symbol);
			return *this;
		}

		String& String::operator -= (const String& other)
		{
			for (auto i = 0, j = 0; i < static_cast<int>(this->size); i++, j = 0)
			{
				while (line[i] == other.line[j] && j < other.len())
				{
					i++; j++;
					if (j == other.len())
					{
						this->cut(i - other.len(), other.len());
						i -= other.len();
					}
				}
			}

			return *this;
		}

	#pragma endregion

	#pragma region bool

		bool String::operator <  (String& other) const
		{
			int i = -1;
			while (this->line[++i] != '\0')
			{
				if (other.line[i] == '\0' || this->line[i] > other.line[i]) return false;
				if (this->line[i] < other.line[i]) return true;
			}
			if (other.line[i] == '\0') return false;
			return true;
		}

		bool String::operator <  (const char* str) const
		{
			int i = -1;
			while (this->line[++i] != '\0')
			{
				if (str[i] == '\0' || this->line[i] > str[i]) return false;
				if (this->line[i] < str[i]) return true;
			}
			if (str[i] == '\0') return false;
			return true;
		}

		bool String::operator >  (String& other) const
		{
			int i = -1;
			while (this->line[++i] != '\0')
			{
				if (other.line[i] == '\0' || this->line[i] > other.line[i]) return true;
				if (this->line[i] < other.line[i]) return false;
			}
			return false;
		}

		bool String::operator >  (const char* str) const
		{
			int i = -1;
			while (this->line[++i] != '\0')
			{
				if (str[i] == '\0' || this->line[i] > str[i]) return true;
				if (this->line[i] < str[i]) return false;
			}
			return false;
		}

		bool String::operator == (String& other) const
		{
			int i = -1;
			while (this->line[++i] != '\0')
				if (this->line[i] != other.line[i]) return false;

			return other.line[i] == '\0';
		}

		bool String::operator == (const char* str) const
		{
			int i = -1;
			while (this->line[++i] != '\0')
				if (this->line[i] != str[i]) return false;

			return str[i] == '\0';
		}

		bool String::operator != (String& other) const
		{
			int i = -1;
			while (this->line[++i] != '\0')
				if (this->line[i] != other.line[i]) return true;

			return other.line[i] != '\0';
		}

		bool String::operator != (const char* str) const
		{
			int i = -1;
			while (this->line[++i] != '\0')
				if (this->line[i] != str[i]) return true;

			return str[i] != '\0';
		}

		bool String::operator <= (String& other) const
		{
			int i = -1;
			while (this->line[++i] != '\0')
			{
				if (other.line[i] == '\0' || this->line[i] > other.line[i]) return false;
				if (this->line[i] < other.line[i]) return true;
			}
			return true;
		}

		bool String::operator <= (const char* str) const
		{
			int i = -1;
			while (this->line[++i] != '\0')
			{
				if (str[i] == '\0' || this->line[i] > str[i]) return false;
				if (this->line[i] < str[i]) return true;
			}
			return true;
		}

		bool String::operator >= (String& other) const
		{
			int i = -1;
			while (this->line[++i] != '\0')
			{
				if (other.line[i] == '\0' || this->line[i] > other.line[i]) return true;
				if (this->line[i] < other.line[i]) return false;
			}
			if (other.line[i] == '\0') return true;
			return false;
		}

		bool String::operator >= (const char* str) const
		{
			int i = -1;
			while (this->line[++i] != '\0')
			{
				if (str[i] == '\0' || this->line[i] > str[i]) return true;
				if (this->line[i] < str[i]) return false;
			}
			if (str[i] == '\0') return true;
			return false;
		}

	#pragma endregion

	#pragma region >>

		std::istream& operator >> (std::istream& in, String& obj)
		{
			if (in.peek() == '\n') in.ignore();
			
			obj.clear();
			obj.put('#', 0, 255);
			in.getline(obj.line, obj.size);

			unsigned tmp = obj.tech_size();
			obj.cut(tmp, 255 - tmp);
			
			return in;
		}

	#pragma endregion

	#pragma region <<

		std::ostream& operator << (std::ostream& out, const String& obj)
		{
			return out << static_cast<const char*>(obj.line);
		}

	#pragma endregion

	#pragma region []

		char& String::operator [] (unsigned index) const
		{
			return line[index];
		}

	#pragma endregion

	#pragma region type()

		String::operator int() const
		{
			return this->to_int();
		}

		String::operator double() const
		{
			return this->to_double();
		}

		String::operator const char*() const
		{
			return static_cast<const char*>(line);
		}

		String::operator char* () const
		{
			char* ret = new char[len() + 1];
			for (auto i = 0; i < static_cast<int>(size); i++) ret[i] = line[i];
			return ret;
		}

#pragma endregion

#pragma endregion 

int String::tech_size() const
{
	for (auto i = 0; true; i++) if (this->line[i] == '\0') return i;
}