#include "header.h"

/**
 * Задание 2.
 *   Разработать приложение, имитирующее очередь печати принтера.
 *   
 *   Должны быть клиенты, посылающие запросы на принтер, у каждого из которых есть свой приоритет.
 *   Каждый новый клиент попадает в очередь в зависимости от своего приоритета.
 *   Необходимо сохранять статистику печати (пользователь, время) в отдельной очереди.
 *   Предусмотреть вывод статистики на экран.
 */

class Doc
{
public:
	int in_time;	
	int page_count;
	int page_complete;
	
	Doc(int page_count, int in_time)
	{
		this->in_time = in_time;
		this->page_count = page_count;
		page_complete = 0;
	}
};

class Printer
{
public:
	Singly_Linked_Priority_List<Doc*> queue;
	int work_time;
	int counter;
	int all_print;
	int avg_time;
	int page_for_min;
	int sleep;
	
	Printer()
	{
		work_time = counter = all_print = avg_time = page_for_min = sleep = 0;
	}
	
	void work(int time_min, int page_for_min, int sleep)
	{
		this->page_for_min = page_for_min;
		this->sleep = sleep;
		std::cout << "\n";
		
		
		while (work_time < time_min)
		{
			in();
			out();
		}
		res();
	}

	void in()
	{
		int tmp_priority = rand() % 11 - 5;
		if (tmp_priority > 0) queue.push_head(new Doc(rand() % 99 + 1, work_time), tmp_priority);
	}
	
	void out()
	{
		if (not queue.empty())
		{
			if (queue.get_priority(queue.size() - 1) != 0) queue.set_priority(queue.size() - 1, 0);
			
			for (auto i = 0; i < page_for_min; i++)
			{
				counter++;
				std::cout << "\r Time: " << work_time << "\tDoc#" << all_print << "\tPage(" << counter << "/" << queue.tail()->page_count << ")" << "\tin queue: ";
		
				Sleep(sleep);
				
				if (counter == queue.tail()->page_count)
				{
					avg_time += work_time - queue.tail()->in_time;
					queue.pop_tail();
					
					for (queue.cur_to_head(); queue.cur != queue.node_tail(); ++queue) std::cout << "[" << queue.cur->get_priority() <<"]" << queue.cur->obj->page_count << "; " << (queue.cur->obj->page_count < 10 ? " " : "");
					std::cout << "\n";
					
					counter = 0;
					all_print++;
					break;
				}
			}
		}
		work_time++;
	}

	void res()
	{
		for (queue.cur_to_head(); queue.cur != queue.node_tail(); ++queue) std::cout << "[" << queue.cur->get_priority() << "]" << queue.cur->obj->page_count << "; " << (queue.cur->obj->page_count < 10 ? " " : "");
		std::cout << "\n";
		
		std::cout << "\n\n All print: " << all_print;
		std::cout << "\n Avg time in queue: " << avg_time / all_print;
		std::cout << "\n Awaiting print: " << queue.size() << " Doc(s)";
	}
};

void task_2()
{
    do {

		int t_w = 720, p_m = 30, s = 1;
    	
		//std::cout << "\n Enter:\n";
		//std::cout << " Time work (min): "; std::cin >> t_w;
		//std::cout << " Speed (page/min): "; std::cin >> p_m;
		//std::cout << " Sleep: "; std::cin >> s;
    	
		Printer XeR;
		XeR.work(t_w, p_m, s);

    } while (restart());
}