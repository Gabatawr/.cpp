#pragma once
#include "dlList.h"

class StopBus;

class Passenger
{
	friend StopBus;
	static int all_id;

	int id;
	int in;
	
public:
	Passenger(int);
};

class StopBus
{
	int minibus_morning, minibus_afternoon, minibus_night;
	int passenger_morning, passenger_afternoon, passenger_night;

	bool type;
	
	int start_work, end_work;

	int total_wait_time;
	int cur_time;

	int total_wait;
	int total_ride;

	dlList<Passenger> queue;
	
	double f; // factor
	
	void init();

	void in();
	void out();

	void result();
	
public:
	StopBus(bool, int, int, int, int, int, int, int = 1);

	void loop();
};

