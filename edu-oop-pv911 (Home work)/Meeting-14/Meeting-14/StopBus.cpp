#include "StopBus.h"

int Passenger::all_id = 0;

Passenger::Passenger(int t)
{
	id = ++all_id;
	in = t;
}

StopBus::StopBus(const bool t, int m_m, int m_an, int m_n, int p_m, int p_an, int p_n, int num)
{
	minibus_morning = m_m; minibus_afternoon = m_an; minibus_night = m_n;
	passenger_morning = p_m; passenger_afternoon = p_an; passenger_night = p_n;
	
	f = 0.5;
	type = t;
	total_wait_time = 0;
	total_ride = total_wait = 0;

	if (type)
	{
		cur_time = start_work = 7 * 60; // 7:00
		for (int i = 0, tmp = 0; i < num; i++)
		{
			tmp = (tmp + int(rand() % int((m_n + m_n * f) - (m_n - m_n * f)) + (m_n - m_n * f))) / 2;
			if (i + 1 == num) end_work = 22 * 60 + tmp;
		}
	}
	else
	{
		for (int i = 0, tmp = 0; i < num; i++)
		{
			tmp = (tmp + int(rand() % int((m_n + m_n * f) - (m_n - m_n * f)) + (m_n - m_n * f))) / 2;
			if (i + 1 == num) cur_time = start_work = 7 * 60 + tmp;
		}
		end_work = 22 * 60; // 22:00
	}
}

void StopBus::loop()
{
	if (type) init();
	while (cur_time < end_work)
	{
		in();
		out();
	}
	result();
}

void StopBus::init() // first trip
{
	int c = rand() % 15 + 1; // 15 = average number of seats

	queue.to_tail();
	for (auto i = 0; i < c; i++)
	{
		queue.push_tail(Passenger(cur_time));
		std::cout << "\n #[" << queue.iterator->obj->id << "] - in";
	}

	total_wait += c;
}

void StopBus::in()
{
	int m = 0, p = 0, t = 0, c = 0;

	if (cur_time < 12 * 60) { m = minibus_morning; p = passenger_morning; } // 7:00 - 12:00
	else if (cur_time < 17 * 60) { m = minibus_afternoon; p = passenger_afternoon; } // 12:00 - 17:00
	else { m = minibus_night; p = passenger_night; } // 17:00 - 22:00

	t = int(rand() % int((m + m * f) - (m - m * f)) + (m - m * f));
	c = int(t / (rand() % int((p + p * f) - (p - p * f)) + (p - p * f)));
	if (c < 0) c = 0;

	queue.to_tail();
	for (auto i = 0; i < c; i++) 
	{
		queue.push_tail(Passenger(cur_time));
		std::cout << "\n #[" << queue.iterator->obj->id << "] - in";
	}

	cur_time += t;
	total_wait += c;
}

void StopBus::out()
{
	int c = rand() % 15 + 1;
	int cc = c;
	
	queue.to_head();
	for (auto i = 0; i < c; i++, cc--)
	{
		if (queue.iterator == nullptr) break;
		
		total_wait_time += cur_time - queue.iterator->obj->in;
		std::cout << "\n #[" << queue.iterator->obj->id << "] - out";
		queue.pop_head();
	}
	
	total_ride += c - cc;
}

void StopBus::result()
{
	std::cout << "\n\n Total wait: " << total_wait;
	
	std::cout << "\n Total ride: " << total_ride;

	std::cout << "\n Still in line: " << queue.count();
	
	std::cout << "\n Average time in line: " << total_wait_time / total_ride;
}