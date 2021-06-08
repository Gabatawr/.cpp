#include "my-lib_of_week-12.h"


// Task 1
bool leap_year(int year)
{
	if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0) return false;
	return true;
}
bool check_date_for_errors(int day, int month, int year)
{
	if (day < 1 || 31 < day) {
		cout << " incorrect day..\n";
		return true;
	}
	if (day == 31 && (month != 1 && month != 2 && month != 3 && month != 5 && month != 7 && month != 8 && month != 10 && month != 12)) {
		cout << " incorrect day for " << month << " months (max 30)\n";
		return true;
	}
	if (day > 28 && (month == 2 && !leap_year(year)) || day > 29 && (month == 2 && leap_year(year))) {
		cout << " incorrect day for February " << year;
		if (leap_year(year)) cout << " (max 29)\n";
		else cout << " (max 28)\n";
		return true;
	}
	if (month > 12 || month < 1) {
		cout << " incorrect month..\n";
		return true;
	}
	if (year < 0) {
		cout << " incorrect year..\n";
		return true;
	}
	return false;
}
int days_between_dates(int d1_d, int d1_m, int d1_y, int d2_d, int d2_m, int d2_y)
{
	if (d1_y > d2_y) 
	{
		swap(d1_y, d2_y);
		swap(d1_m, d2_m);
		swap(d1_d, d2_d);
	}
	else if (d1_y == d2_y && d1_m > d2_m) 
	{
		swap(d1_m, d2_m);
		swap(d1_d, d2_d);
	}
	else if (d1_y == d2_y && d1_m == d2_m) 
	{
		if (d1_d > d2_d) swap(d1_d, d2_d);
		return d2_d - d1_d;
	}

	int days_d1 = 0, days_d2 = 0;
	for (int count_day = 0, tmp_m = d1_m, tmp_y = d1_y, i = 0; i < 2; i++, count_day = 0, tmp_m = d2_m, tmp_y = d2_y) {
		for (; tmp_m > 1; tmp_m--) {
			if (tmp_m == 1 || tmp_m == 3 || tmp_m == 5 || tmp_m == 7 || tmp_m == 8 || tmp_m == 10 || tmp_m == 12) count_day += 31;
			else if (tmp_m == 2) {
				if (leap_year(tmp_y)) count_day += 29;
				else count_day += 28;
			} else count_day += 30;
			
			if (i == 0) days_d1 = count_day + d1_d;
			else {
				if (leap_year(d2_y)) days_d2 = 366 - (count_day + d2_d);
				else days_d2 = 365 - (count_day + d2_d);
			}
		}
	}

	for (int days = 0; d1_y <= d2_y; d1_y++) {
		if (leap_year(d1_y)) days += 366;
		else days += 365;
		if (d1_y == d2_y) return days - days_d1 - days_d2;
	}
}


//---------------------------------------------------------------------------------------------------------------------------//


// Task 2
int common_factor_2num(int n1, int n2)
{
	if (n1 < n2) swap(n2, n1);
	if (n1 % n2 == 0) return n2;
	return common_factor_2num(n2, n1 - n2);
}


//---------------------------------------------------------------------------------------------------------------------------//


// Task 6
void game_task6_start(int u_num)
{
	int p_num = rand() % 8999 + 1000;
	int count = 1;
	game_task6_recursion(u_num, p_num, count);
}
void game_task6_recursion(int u_num, int p_num, int count)
{
	cout << "\n\n Game #" << count << endl;
	
	if (count != 1) {
		cout << " ****\b\b\b\b";
		cin >> u_num;
	}
	
	if (u_num == p_num)
	{
		cout << "\n Yes! You WIN!!!\n";
		return;
	}
	
	int bulls = 0, cows = 0;
	for (int i = 0, D = 10, u_tmp = u_num, p_tmp = p_num; i < 4; i++, u_tmp /= D, p_tmp /= D) {
		if (u_tmp % D == p_tmp % D) cows++;
	}
	
	for (int i = 0, D = 10, u_tmp = u_num, tmp = -1, a = -1, b = -1, c = -1; i < 4; i++, u_tmp /= D)
	{
		tmp = u_tmp % D;
		if (tmp == a || tmp == b || tmp == c) continue;
		
		for (int j = 0, D2 = 10, p_tmp = p_num; j < 4; j++, p_tmp /= D) { //1901
			if (p_tmp % D == tmp) {
				bulls++;
				break;
			}
		}
		
		if (bulls == 4) break;
		
		if (i == 0) a = tmp;
		else if (i == 1) b = tmp;
		else if (i == 2) c = tmp;
	}
	
	cout << " Bulls: " << bulls << " | Cows: " << cows << endl;
	
	game_task6_recursion(u_num, p_num, ++count);
}


//---------------------------------------------------------------------------------------------------------------------------//


// question about restarting the task
bool restart_task()
{
	cout << endl << " Restart task? (0 / 1)" << endl << " Enter: _\b";
	char u_enter;
	cin >> u_enter;
	
	if (u_enter == '1') return true;
	if (u_enter == '0') return false;
	
	cout << " Invalid command.." << endl;
	return restart_task();
}
