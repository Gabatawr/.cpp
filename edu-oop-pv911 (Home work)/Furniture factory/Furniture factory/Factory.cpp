#include "Factory.h"

Factory::Factory()
{
	completed_orders = work_tyme = current_tyme = 0;
	fabrication = new Fabrication;
	stock = Stock::Create();
}

Factory::~Factory()
{
	delete fabrication;
	Stock::Delete();
}

void Factory::supply()
{
	stock->add(new int[3] { rand() % 100, rand() % 260, rand() % 130 });
}

Furniture* Factory::new_order(Type T)
{
	Furniture* ret = nullptr;
	
	if (T == Type::def)
	{
		switch (rand() % 2 + 1)
		{
			case 1: ret = new Chair; break;
			case 2: ret = new Table; break;
		}
	}
	else if (T == Type::chair) ret = new Chair;
	else if (T == Type::table) ret = new Table;

	if (ret) fabrication->queue.push_tail(ret);
	
	return ret;
}

void Factory::work(int tyme)
{
	work_tyme = tyme;

	while (current_tyme++ != work_tyme)
	{
		if (current_tyme % 24 == 0 || current_tyme == 0)
		{
			std::cout << "\n";
			supply();
		}
		
		if (current_tyme % 6 == 0 || current_tyme == 0) for (auto i = rand() % 7; i > 0; --i) new_order(Type(rand() % 3));
			
		for (auto i = 0; not fabrication->queue.empty() && i < fabrication->queue.size(); i++)
		{			
			if (stock->take(fabrication->queue[i]->raw))
			{
				if (fabrication->queue[i]->type == Type::chair) fabrication->created_chair++;
				else fabrication->created_table++;
				
				delete fabrication->queue.pop_pos(i);
				completed_orders++;
				break;
			}
		}

		std::cout
			<< "\n " << current_tyme << "/" << work_tyme << "\t\t"
			<< stock->raw[0]->size() << ":" << stock->raw[1]->size() << ":" << stock->raw[2]->size() << "\t\t"
			<< completed_orders << "/" << fabrication->queue.size() << "\t\t"
			<< fabrication->created_chair << "/" << fabrication->created_table;

		//Sleep(50);
	}
}
