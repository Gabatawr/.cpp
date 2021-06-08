#pragma once


 // enter array parameters [size, min value, limit of values and use unique numbers]
template <typename ArrType>
void enter_arr_param(int &arr_size, bool &is_unique, ArrType &arr_min, ArrType &arr_max, int accuracy)
{
	bool error_enter;
	do {
		cout << "\n Enter array size: ";
		cin >> arr_size;

		cout << " Enter min value: ";
		cin >> arr_min;

		cout << " Enter limit of values: ";
		cin >> arr_max;

		cout << " Use unique numbers? (0 / 1): _\b";
		cin >> is_unique;
		if (is_unique && ((arr_max - arr_min < arr_size && typeid(ArrType) == typeid(int)) || ((arr_max - arr_min) * pow(10, accuracy) < arr_size && typeid(ArrType) == typeid(double)))) {
			cout << "\n Error, range is not enough to use unique values\n";
			error_enter = true;
		} else if (arr_size < 1) {
			cout << "\n Error, array size minimum [1]\n";
			error_enter = true;
		} else return;
	} while (error_enter);
}

template <typename ArrType>
void create_random_arr(ArrType* &arr, int arr_size, bool is_unique, ArrType arr_min, ArrType arr_max, int accuracy)
{
	// create arr
	arr = new ArrType[arr_size];

	// randomizer
	for (int i = 0; i < arr_size; i++)
	{
		arr[i] = ArrType(rand() % int(arr_max - arr_min) + arr_min);

		// if double
		if (typeid(arr) == typeid(double*)) arr[i] += double(rand() % int(pow(10, accuracy))) / int(pow(10, accuracy));

		// if unique
		if (is_unique)
			for (int j = 0; j < i; j++)
				if (arr[i] == arr[j]) {
					i--; break;
				}
	}
}

template <typename ArrType>
void print_arr(ArrType* arr, int arr_size)
{
	for (int i = 0; i < arr_size; i++) {
		if (i == 0) cout << "\n Array [";
		cout << arr[i];
		if (i == arr_size - 1) cout << "]" << endl;
		else cout << ", ";
	}
}

// calculation average value of the array
template <typename ArrType>
double calc_arr_avg(ArrType* arr, int arr_size)
{
	ArrType sum = 0;
	for (int i = 0; i < arr_size; i++) sum += arr[i];
	return sum / double(arr_size);
}

// count_[Negative Zero Positive]_elements_array
template <typename ArrType>
void count_NZP_el_arr(ArrType* arr, int arr_size, int &count_negative, int &count_zero, int &count_positive)
{
	for (int i = 0; i < arr_size; i++)
	{
		if (arr[i] < 0) count_negative++;
		else if (arr[i] == 0) count_zero++;
		else count_positive++;
	}
}

// Task 3 (enter_arr_param + create_random_arr + print_arr + count_NZP_el_arr)
template <typename ArrType>
void fun_task_3(ArrType T, int accuracy = 1)
{
	int arr_size;
	bool is_unique;
	ArrType arr_min, arr_max;
	enter_arr_param(arr_size, is_unique, arr_min, arr_max, accuracy);

	ArrType* arr = nullptr;
	create_random_arr(arr, arr_size, is_unique, arr_min, arr_max, accuracy);

	print_arr(arr, arr_size);

	int count_negative_val = 0, count_positive_val = 0, count_zero_val = 0;
	count_NZP_el_arr(arr, arr_size, count_negative_val, count_zero_val, count_positive_val);
	cout << "\n In the array: [Negative values = " << count_negative_val << " | Positive values = " << count_positive_val << " | Zero values = " << count_zero_val << "]\n";
}

// Task 2 (enter_arr_param + create_random_arr + print_arr + calc_arr_avg)
template <typename ArrType>
void fun_task_2(ArrType T, int accuracy = 1)
{
	int arr_size;
	bool is_unique;
	ArrType arr_min, arr_max;
	enter_arr_param(arr_size, is_unique, arr_min, arr_max, accuracy);
	
	ArrType* arr = nullptr;
	create_random_arr(arr, arr_size, is_unique, arr_min, arr_max, accuracy);
	
	print_arr(arr, arr_size);

	cout << "\n Array average = " << calc_arr_avg(arr, arr_size) << endl;
}


//---------------------------------------------------------------------------------------------------------------------------//


// enter matrix parameters [size, min value, limit of value and use unique numbers]
template <typename ArrType>
void enter_mx_param(ArrType mx_type, int& mx_size, bool& is_unique, int& mx_min, int& mx_max, int& accuracy)
{
	if (typeid(ArrType) == typeid(double)) {
		do {
			cout << "\n Enter fractional accuracy: ";
			cin >> accuracy;
			if (accuracy > 4) cout << " Randomizer cannot generate 5+ decimal places\n";
		} while (accuracy < 1 || accuracy > 4);
	}

	do {
		cout << " Enter matrix size: ";
		cin >> mx_size;
	} while (mx_size < 1);
	
	do {
		while (true) {
			cout << " Enter min value: ";
			if (typeid(ArrType) == typeid(char)) cout << "\b\b (min 32): ";
			cin >> mx_min;
			if ((mx_min < 32 || mx_min > 126) && typeid(ArrType) == typeid(char)) {
				cout << " Error, for char range 32 - 127\n\n";
				continue;
			}
			break;
		}

		while (true) {
			cout << " Enter limit of values: ";
			if (typeid(ArrType) == typeid(char)) cout << "\b\b (max 127): ";
			cin >> mx_max;
			if (mx_max < mx_min) {
				cout << " Error, max < min\n\n";
				continue;
			}
			if ((mx_max < 33 || mx_max > 127) && typeid(ArrType) == typeid(char)) {
				cout << " Error, for char range 32 - 127\n\n";
				continue;
			}
			break;
		}

		cout << " Use unique numbers? (0 / 1): _\b";
		cin >> is_unique;
		if (is_unique && ((mx_max - mx_min < mx_size * mx_size && (typeid(ArrType) != typeid(double))) || ((mx_max - mx_min) * pow(10, accuracy) < mx_size * mx_size && typeid(ArrType) == typeid(double)))) {
			cout << "\n Error, range is not enough to use unique values\n";
			continue;
		}
		break;
	} while (true);
}

// matrix randomizer
template <typename ArrType>
void mx_rand(ArrType** &arr_mx, int mx_size, bool const is_unique, int mx_min, int mx_max, int accuracy)
{
	for (int i = 0; i < mx_size; i++)
	{
		for (int j = 0; j < mx_size; j++)
		{
			bool is_flag = false;
			arr_mx[i][j] = ArrType((rand() % (mx_max - mx_min)) + mx_min);

			// if double
			if (typeid(ArrType) == typeid(double)) arr_mx[i][j] += double(rand() % int(pow(10, accuracy))) / int(pow(10, accuracy));

			// if unique
			if (is_unique)
			{
				for (int k = 0; k <= i; k++)
				{
					if (is_flag) break;
					for (int p = 0; p < mx_size; p++)
					{
						if(k == i && p == j) 
						{
							is_flag = true;
							break;
						}
						if (arr_mx[i][j] == arr_mx[k][p])
						{
							j--;
							is_flag = true;
							break;
						}
					}
				}
			}
		}
	}
}

template <typename ArrType>
void print_matrix(ArrType** arr_mx, int mx_size, int tmp, int accuracy)
{
	// cell width calculation
	int digit_size = 1;
	
	if (typeid(ArrType) == typeid(double)) digit_size += accuracy + 1;
	
	do {
		tmp /= 10;
		digit_size++;
	} while (tmp > 10);

	if (typeid(ArrType) == typeid(char)) digit_size = 1;
	cout << "\n " << setfill('-') << setw((3 + digit_size) * mx_size + 1) << "" << endl; // header row line ---
	for (int i = 0; i < mx_size; i++) 
	{
		for (int j = 0; j < mx_size; j++) 
		{
			cout << " | " << setfill(' ') << setw(digit_size) << arr_mx[i][j]; // output number
			if (j == mx_size - 1) cout << " |";
		}
		cout << "\n " << setfill('-') << setw((3 + digit_size) * mx_size + 1) << "" << endl; // line ---
	}
}

template <typename ArrType>
void mx_min_max_val(ArrType** arr_mx, int mx_size, ArrType& mx_min_val, ArrType& mx_max_val)
{
	for (int i = 0; i < mx_size; i++)
	{
		if (i == 0) {
			if (typeid(arr_mx) == typeid(char**)) {
				mx_min_val = 126;
				mx_max_val = 32;
			} else {
				mx_min_val = arr_mx[i][i];
				mx_max_val = arr_mx[i][i];
			}
			
		} else {
			if (typeid(arr_mx) == typeid(char**)) {
				if (int(arr_mx[i][i]) < int(mx_min_val)) mx_min_val = arr_mx[i][i];
				if (int(arr_mx[i][i]) > int(mx_max_val)) mx_max_val = arr_mx[i][i];
			} else {
				if (arr_mx[i][i] < mx_min_val) mx_min_val = arr_mx[i][i];
				if (arr_mx[i][i] > mx_max_val) mx_max_val = arr_mx[i][i];
			}
		}
		
	}
}

template <typename ArrType>
void mx_rows_quick_sort(ArrType* mx_rows, int first, int last)
{
	int f = first;
	int l = last;
	ArrType mid = mx_rows[(f + l) / 2];

	while (f < l) {
		if (typeid(ArrType) == typeid(char)) while (int(mx_rows[f]) < int(mid)) f++;
		else while (mx_rows[f] < mid) f++;
		if (typeid(ArrType) == typeid(char)) while (int(mx_rows[l]) > int(mid)) l--;
		else while (mx_rows[l] > mid) l--;
		if (f <= l) swap(mx_rows[f++], mx_rows[l--]);
	}
	
	if (first < l) mx_rows_quick_sort(mx_rows, first, l);
	if (f < last) mx_rows_quick_sort(mx_rows, f, last);
}

// Task 4 (enter_mx_param + mx_rand + print_mx + mx_min_max_val + mx_rows_quick_sort + print_mx)
template <typename ArrType>
void fun_task_4(ArrType mx_type, bool use_def_set)
{
	int mx_size = 8, mx_min = 32, mx_max = 127, accuracy = 2;
	bool is_unique = true;

	if (!use_def_set) enter_mx_param(mx_type, mx_size, is_unique, mx_min, mx_max, accuracy);

	ArrType** arr_mx = new ArrType* [mx_size];
	for (int i = 0; i < mx_size; i++)
		arr_mx[i] = new ArrType[mx_size];

	mx_rand(arr_mx, mx_size, is_unique, mx_min, mx_max, accuracy);
	print_matrix(arr_mx, mx_size, mx_max, accuracy);

	ArrType mx_min_val, mx_max_val;
	mx_min_max_val(arr_mx, mx_size, mx_min_val, mx_max_val);
	cout << "\n On the main diagonal of the matrix: min value = ";
	if (typeid(mx_type) == typeid(char)) cout << int(mx_min_val) << ", max value = " << int(mx_max_val) << "\n **value is character code" << endl;
	else cout << mx_min_val << ", max value = " << mx_max_val << endl;

	cout << "\n Sort values in rows: ";
	system("pause");
	for (int i = 0; i < mx_size; i++) mx_rows_quick_sort(arr_mx[i], 0, mx_size - 1);
	print_matrix(arr_mx, mx_size, mx_max, accuracy);
	if (typeid(mx_type) == typeid(char)) cout << " **values are sorted by character code" << endl;
	
	for (int i = 0; i < mx_size; i++)
		delete[] arr_mx[i];
	delete[] arr_mx;
}