#pragma once

#pragma region Create

template <typename ArrType>
void arr_create_sequence(ArrType* &arr, const int arr_size, bool is_random_step = false, int random_step = 0, ArrType start = 0)
{
	if (arr != nullptr) delete[] arr;
	arr = new ArrType[arr_size];

	for (auto i = 0; i < arr_size; i++)
	{
		arr[i] = i + start;
		if (is_random_step) start += rand() % random_step;
	}
}

template <typename ArrType>
void arr_create_random(ArrType* &arr, const int arr_size, bool is_unique = false, ArrType min = 0, ArrType max = 100, int accuracy = 2)
{
	// if arr no empty
	if (arr != nullptr) delete[] arr;
	
	// create arr
	arr = new ArrType[arr_size];

	// randomizer
	for (auto i = 0; i < arr_size; i++)
	{
		int whole = rand() % int(max - min);
		arr[i] = ArrType(whole + min);	

		// if double
		bool is_double = false;
		if (typeid(arr) != typeid(int*)) is_double = true;
		if (is_double) arr[i] += double(rand() % int(pow(10, accuracy))) / int(pow(10, accuracy));

		// if unique
		if (is_unique)
		{
			for (auto j = 0; j < i; j++)
			{
				if (arr[i] == arr[j])
				{
					i--; break;
				}
			}
		}
	}
}

#pragma endregion

#pragma region Count

template <typename ArrType>
int arr_copy_count(ArrType* arr, const int arr_size, ArrType to_search)
{
	int count = 0;
	for (auto i = 0; i < arr_size; i++)
	{
		if (arr[i] == to_search) count++;
	}
	return count;
}

#pragma endregion

#pragma region Sort

template <typename ArrType>
void arr_quick_sort(ArrType* arr_rand, int first, int last)
{
	int f = first;
	int l = last;
	int mid = arr_rand[(f + l) / 2];

	while (f < l) {
		while (arr_rand[f] < mid) f++;
		while (arr_rand[l] > mid) l--;
		if (f <= l) std::swap(arr_rand[f++], arr_rand[l--]);
	}

	if (first < l) arr_quick_sort(arr_rand, first, l);
	if (f < last) arr_quick_sort(arr_rand, f, last);
}

#pragma endregion

#pragma region Search

// For binary search, the array must be sorted in ascending order.
template <typename ArrType>
int binary_search(ArrType* arr, ArrType key, int begin, int end)
{
	while (begin <= end) {
		int mid = (begin + end) / 2;

		if (arr[mid] == key) return mid;
		if (arr[mid] > key) end = mid - 1;
		else begin = mid + 1;
	}
	return -1;
}


template <typename ArrType>
int arr_find_begin(ArrType* arr, const int arr_size, ArrType key, int begin = 0)
{
	if (begin < 0 || begin > arr_size - 1) return -1;

	for (auto i = begin; i < arr_size; i++)
	{
		if (arr[i] == key) return i;
	}
	return -1;
}

template <typename ArrType>
int arr_find_end(ArrType* arr, const int arr_size, ArrType key, int end = -1)
{
	if (end == -1) end = arr_size - 1;
	else if (end >= arr_size || end < 0) return -1;

	for (auto i = end; i >= 0; i--)
	{
		if (arr[i] == key) return i;
	}
	return -1;
}

template <typename ArrType>
int arr_find_range(ArrType* arr, const int arr_size, ArrType key, int begin = 0, int end = -1)
{
	if (end == -1) end = arr_size - 1;
	else if (end < 0 || end > arr_size - 1) return -1;
	if (begin < 0 || begin > arr_size - 1) return -1;

	for (auto i = begin; i <= end; i++)
	{
		if (arr[i] == key) return i;
	}
	return -1;
}

#pragma endregion

#pragma region Put/Get

// Add element by index, without index last.
template <typename ArrType>
void arr_el_put(ArrType*& arr, int& arr_size, ArrType el, int index = -1)
{
	if (index == -1) index = arr_size;
	ArrType* arr_new = new ArrType[++arr_size];

	for (auto i = 0; i < arr_size; i++) {
		if (i < index) arr_new[i] = arr[i];
		if (i == index) arr_new[i] = el;
		if (i > index) arr_new[i] = arr[i - 1];
	}

	std::swap(arr, arr_new);
	delete[] arr_new;
}

// Delete element by index.
template <typename ArrType>
void arr_el_get(ArrType*& arr, int& arr_size, int index)
{
	ArrType* arr_new = new ArrType[--arr_size];

	for (auto i = 0; i < arr_size; i++) {
		if (i < index) arr_new[i] = arr[i];
		else arr_new[i] = arr[i + 1];
	}

	std::swap(arr, arr_new);
	delete[] arr_new;
}
#pragma endregion

#pragma region Selection

// Put in "C" elements "A" that are not included in "B", without duplication.
template <typename ArrType>
void arrs_unique_to_A(ArrType* arr_a, const int arr_a_size, ArrType* arr_b, const int arr_b_size, ArrType*& arr_c, int& arr_c_size)
{
	if (arr_c == nullptr)
	{
		for (auto count = 0, step = 0; step < 2; step++)
		{
			for (int a = 0; a < arr_a_size; a++) {
				if (a != 0) {
					bool is_duplicate = false;
					for (auto d = 0; d < a; d++) {
						if (arr_a[a] == arr_a[d]) {
							is_duplicate = true;
							break;
						}
					}
					if (is_duplicate) continue;
				}

				for (auto b = 0; b < arr_b_size; b++) {
					if (arr_a[a] == arr_b[b]) break;
					if (b == arr_b_size - 1) {
						if (step == 0) count++;
						else arr_c[--count] = arr_a[a];
					}
				}
			}

			if (step == 0) {
				arr_c_size = count;
				arr_c = new int[arr_c_size] {};
			}
		}
	} else return;
}

// Put in "C" elements "A" and "B".
template <typename ArrType>
void arrs_combine_AB(ArrType* arr_a, const int arr_a_size, ArrType* arr_b, const int arr_b_size, ArrType*& arr_c, int& arr_c_size)
{
	arr_c_size = arr_a_size + arr_b_size;
	if (arr_c == nullptr) arr_c = new int[arr_c_size] {};
	else return;

	for (auto i = 0; i < arr_a_size; i++) arr_c[i]				= arr_a[i];
	for (auto i = 0; i < arr_b_size; i++) arr_c[arr_a_size + i] = arr_b[i];
}

#pragma endregion

#pragma region Aggregate

template <typename ArrType>
ArrType arr_min(ArrType* arr, const int arr_size)
{
	ArrType min = arr[0];
	for (auto i = 1; i < arr_size; i++)
	{
		if (arr[i] < min) min = arr[i];
	}
	return min;
}

template <typename ArrType>
ArrType arr_max(ArrType* arr, const int arr_size)
{
	ArrType max = arr[0];
	for (auto i = 1; i < arr_size; i++)
	{
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

template <typename ArrType>
ArrType arr_sum(ArrType* arr, const int arr_size)
{
	ArrType sum = 0;
	for (auto i = 0; i < arr_size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

template <typename ArrType>
double arr_avg(ArrType* arr, const int arr_size)
{
	return double(double(arr_sum(arr, arr_size)) / arr_size);
}

#pragma endregion

#pragma region Display

template <typename ArrType>
void arr_echo_el(ArrType* arr, const int arr_size)
{
	std::cout << " {";
	for (auto i = 0; i < arr_size; i++)
	{
		std::cout << arr[i];
		if (i != (arr_size - 1)) std::cout << ", ";
	}
	std::cout << "} ";
}

template <typename ArrType>
void arr_echo_tech(ArrType* arr, const int arr_size)
{
	std::cout << "\n Array type: " << typeid(arr).name() << " | size: " << arr_size << " | RAM: " << arr << "\n";
}

template <typename ArrType>
void arr_echo_aggregate(ArrType* arr, const int arr_size)
{
	std::cout << "\n MIN : " << arr_min(arr, arr_size) << "\n";
	std::cout << " MAX : " << arr_max(arr, arr_size) << "\n";
	std::cout << " SUM : " << arr_sum(arr, arr_size) << "\n";
	std::cout << " AVG : " << arr_avg(arr, arr_size) << "\n";
}


template <typename ArrType>
void arr_echo_all(ArrType* arr, const int arr_size)
{
	echo_arr_tech(arr, arr_size);
	echo_arr_el(arr, arr_size);
	echo_arr_aggregate(arr, arr_size);
}

#pragma endregion

#pragma region Delete

// Clear memory up to 5 arrays.
template <typename ArrType_1, typename ArrType_2 = int, typename ArrType_3 = int, typename ArrType_4 = int, typename ArrType_5 = int>
void arr_delete(ArrType_1* arr_1, ArrType_2* arr_2 = nullptr, ArrType_3* arr_3 = nullptr, ArrType_4* arr_4 = nullptr, ArrType_5* arr_5 = nullptr)
{
	if (arr_1 != nullptr) delete[] *arr_1;
	if (arr_2 != nullptr) delete[] *arr_2;
	if (arr_3 != nullptr) delete[] *arr_3;
	if (arr_4 != nullptr) delete[] *arr_4;
	if (arr_5 != nullptr) delete[] *arr_5;
}

#pragma endregion
