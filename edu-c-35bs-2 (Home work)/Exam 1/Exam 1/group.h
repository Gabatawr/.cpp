#pragma once

struct group
{
	int size;
	people* member;

	group()
	{
		size = 1;
		member = new people[size];
	}
	group(int size)
	{
		this->size = size;
		this->member = new people[size];
	}
	group(char* file_name) //load
	{
		char tmp_byte;
		FILE* file_ptr = fopen(file_name, "r");
		if (file_ptr == NULL) { perror("Error: File not found!"); exit(0); }
		
		int tmp_count = 1;
		fseek(file_ptr, 12, SEEK_SET);
		while ((tmp_byte = (char)getc(file_ptr)) != '\n') tmp_count++;
		
		char* tmp_int = new char[tmp_count];
		
		fseek(file_ptr, 12, SEEK_SET);
		for (auto i = 0; (tmp_byte = (char)getc(file_ptr)) != '\n'; i++) tmp_int[i] = tmp_byte;
		tmp_int[tmp_count - 1] = '\0';
		
		this->size = str_to_int(tmp_int); delete[] tmp_int;
		this->member = new people[this->size];

		int current_pos = 12 + tmp_count + 1 + 61 + 1 + 1; // 12 = len."Group size: " + tmp_count = len."10'\n'" + 1? + 53 = count."-" + 1 len.'\n' + 1?
		
		fseek(file_ptr, current_pos, SEEK_SET);
		for (auto i = 0; i < this->size; i++)
		{
			// First name
			for (tmp_count = 1; (tmp_byte = (char)getc(file_ptr)) != ' '; tmp_count++);
			delete[] this->member[i].first_name;
			this->member[i].first_name = new char[tmp_count];
			
			fseek(file_ptr, -tmp_count, SEEK_CUR);
			for (auto j = 0; j < tmp_count; j++)
				this->member[i].first_name[j] = (char)getc(file_ptr);
			this->member[i].first_name[tmp_count - 1] = '\0';

			current_pos += tmp_count;
			fseek(file_ptr, current_pos, SEEK_SET);
			//--------------------------------------------------------------------------
			//
			// Last name
			for (tmp_count = 1; (tmp_byte = (char)getc(file_ptr)) != '\t'; tmp_count++);
			delete[] this->member[i].last_name;
			this->member[i].last_name = new char[tmp_count];

			fseek(file_ptr, -tmp_count, SEEK_CUR);
			for (auto j = 0; j < tmp_count; j++)
				this->member[i].last_name[j] = (char)getc(file_ptr);
			this->member[i].last_name[tmp_count - 1] = '\0';

			current_pos += tmp_count;
			fseek(file_ptr, current_pos, SEEK_SET);

			while ((char)getc(file_ptr) == '\t') current_pos++;
			fseek(file_ptr, -1, SEEK_CUR);
			//--------------------------------------------------------------------------
			//
			// Date of birth
			for (tmp_count = 1; (tmp_byte = (char)getc(file_ptr)) != '\t'; tmp_count++);
			char* tmp_date = new char[tmp_count];
			
			fseek(file_ptr, -tmp_count, SEEK_CUR);
			for (auto j = 0; j < tmp_count; j++)
				tmp_date[j] = (char)getc(file_ptr);
			tmp_date[tmp_count - 1] = '\0';
			
			this->member[i].birthday.day   = (char)str_to_int(tmp_date, 1);
			this->member[i].birthday.month = (char)str_to_int(tmp_date, 2);
			this->member[i].birthday.year  =       str_to_int(tmp_date, 3);
			
			if (not this->member[i].birthday.check_date())
			{
				std::cout << " Error Date of Birth: #" << i + 1 << "\n";
				this->member[i].age = 0;
			}
			else this->member[i].age = this->member[i].birthday.full_years();

			delete[] tmp_date;
			current_pos += tmp_count;
			fseek(file_ptr, current_pos, SEEK_SET);
			//--------------------------------------------------------------------------
			//
			// Phone
			for (tmp_count = 1; (tmp_byte = (char)getc(file_ptr)) != '\n'; tmp_count++);
			delete[] this->member[i].phone;
			this->member[i].phone = new char[tmp_count - 1];

			fseek(file_ptr, -tmp_count, SEEK_CUR);
			for (auto j = 0; j < tmp_count - 1; j++)
				this->member[i].phone[j] = (char)getc(file_ptr);
			this->member[i].phone[tmp_count - 2] = '\0';

			if (i != this->size - 1)
			{
				current_pos += tmp_count + 1;
				fseek(file_ptr, current_pos, SEEK_SET);
			}
		}
		fclose(file_ptr);
	}

	~group()
	{
		delete[] member;
	}
	void save (char* file_name)
	{
		FILE* file_ptr = fopen(file_name, "w");
		if (file_ptr == NULL) { perror("Error: File not found!"); exit(0); }

		char* tmp_str = new char[13]{"Group size: "};
		for (auto i = 0; tmp_str[i] != '\0'; i++)
			putc(tmp_str[i], file_ptr);
		delete[] tmp_str;

		tmp_str = str_from_int(this->size);
		for (auto i = 0; tmp_str[i] != '\0'; i++)
			putc(tmp_str[i], file_ptr);
		delete[] tmp_str;
		putc('\n', file_ptr);

		for (auto i = 0; i < 61; i++)
			putc('-', file_ptr);
		putc('\n', file_ptr);

		for (auto i = 0; i < this->size; i++)
		{
			// First name
			for (auto j = 0; this->member[i].first_name[j] != '\0'; j++)
				putc(this->member[i].first_name[j], file_ptr);
			putc(' ', file_ptr);
			//--------------------------------------------------------------------------
			// Last name
			for (auto j = 0; this->member[i].last_name[j] != '\0'; j++)
				putc(this->member[i].last_name[j], file_ptr);
			//--------------------------------------------------------------------------
			
			if (str_len(this->member[i].first_name) + str_len(this->member[i].last_name) > 14)
			{ putc('\t', file_ptr); }
			
			else if (str_len(this->member[i].first_name) + str_len(this->member[i].last_name) < 7)
			{ putc('\t', file_ptr); putc('\t', file_ptr); putc('\t', file_ptr); }
			
			else { putc('\t', file_ptr); putc('\t', file_ptr); }
			
			// Date of birth
			tmp_str = str_from_int(this->member[i].birthday.day);
			if (this->member[i].birthday.day < 10) putc('0', file_ptr);
			for (auto j = 0; tmp_str[j] != '\0'; j++) 
				putc(tmp_str[j], file_ptr);
			delete[] tmp_str;
			putc('.', file_ptr);
			
			tmp_str = str_from_int(this->member[i].birthday.month);
			if (this->member[i].birthday.month < 10) putc('0', file_ptr);
			for (auto j = 0; tmp_str[j] != '\0'; j++)
				putc(tmp_str[j], file_ptr);
			delete[] tmp_str;
			putc('.', file_ptr);

			tmp_str = str_from_int(this->member[i].birthday.year);
			for (auto j = 0; tmp_str[j] != '\0'; j++)
				putc(tmp_str[j], file_ptr);
			delete[] tmp_str;
			putc(' ', file_ptr); putc(':', file_ptr); putc(' ', file_ptr);

			tmp_str = str_from_int(this->member[i].age);
			for (auto j = 0; tmp_str[j] != '\0'; j++)
				putc(tmp_str[j], file_ptr);
			delete[] tmp_str;
			putc('\t', file_ptr); putc('\t', file_ptr);
			//--------------------------------------------------------------------------
			// Phone
			for (auto j = 0; this->member[i].phone[j] != '\0'; j++)
				putc(this->member[i].phone[j], file_ptr);
			putc('\n', file_ptr);
		}
		fclose(file_ptr);
	}
	
	void print_by_number(int number) const
	{
		std::cout << "\n #" << number + 1 << "\t" << this->member[number];
	}
	void print_all() const
	{
		for (auto i = 0; i < this->size; i++) this->print_by_number(i);
	}
	void print_by_birthmonth(int month) const
	{
		for (auto i = 0; i < this->size; i++)
			if (this->member[i].birthday.month == month) this->print_by_number(i);
	}
	void print_by_age(int age) const
	{
		for (auto i = 0; i < this->size; i++)
			if (this->member[i].age == age) this->print_by_number(i);
	}

	void add(int number = 0)
	{
		if (number < 0)	         number = 0;
		if (number > this->size) number = this->size;

		people* old_list = this->member;
		member = new people[this->size + 1];

		for (auto i = 0; i < this->size + 1; i++)
		{
			if (i < number)  this->member[i] = old_list[i];
			if (i == number) this->member[i].randomizer();
			if (i > number)  this->member[i] = old_list[i - 1];
		}
		delete[] old_list;
		print_by_number(number);
		this->size++;
	}
	void remove(int number = 0)
	{
		if (number < 0)	         number = 0;
		if (number > this->size) number = this->size - 1;

		people* old_list = this->member;
		member = new people[this->size - 1];

		for (auto i = 0; i < this->size; i++)
		{
			if (i < number)  this->member[i] = old_list[i];
			if (i > number)  this->member[i - 1] = old_list[i];
		}
		delete[] old_list;

		this->size--;
	}

	void search_by_name(char* key) const
	{
		for (auto i = 0; i < this->size; i++)
			if (str_count_word(this->member[i].first_name, key) > 0 || str_count_word(this->member[i].last_name, key) > 0) this->print_by_number(i);
	}
	void search_by_phone(char* key) const
	{
		for (auto i = 0; i < this->size; i++)
			if (str_count_word(this->member[i].phone, key) > 0) this->print_by_number(i);
	}
};