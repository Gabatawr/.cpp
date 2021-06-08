#pragma once

bool leap_year(int year);
bool check_date_for_errors(int day, int month, int year);
int days_between_dates(int d1_d, int d1_m, int d1_y, int d2_d, int d2_m, int d2_y);

int common_factor_2num(int n1, int n2);

void game_task6_start(int u_num);
void game_task6_recursion(int u_num, int p_num, int count);

// question about restarting the task
bool restart_task();