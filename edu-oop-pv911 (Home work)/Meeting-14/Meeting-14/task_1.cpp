#include "header.h"
#include "StopBus.h"

/**
 * Задание 1.
 *   Создать имитационную модель "остановка маршрутных такси".
 *   
 *   Необходимо вводить следующую информацию:
 *     - Среднее время между появлениями пассажиров на остановке в разное время суток,
 *     - Среднее время между появлениями маршруток на остановке в разное время суток,
 *     - Тип остановки (конечная или нет).
 *     
 *   Необходимо определить:
 *     - Cреднее время пребывание человека на остановке,
 *     - Достаточный интервал времени между приходами маршруток, чтобы на остановке находилось не более N людей одновременно.
 *     
 *   Количество свободных мест в маршрутке является случайной величиной.
 */

void task_1()
{
    do {
		system("cls");
    	
		#pragma region Enter
    	
			bool autocomplete = true; bool type = true; char change;
			int passenger_morning = 1, passenger_afternoon = 2, passenger_night = 3;
	        int minibus_morning = 5, minibus_afternoon = 10, minibus_night = 15;

			std::cout << "\n\n Autocomplete? [y/n] _\b"; std::cin >> change; if (change != 'y') autocomplete = false;
    		
    		if (not autocomplete)
    		{
				std::cout << "\n";
				std::cout << "            Enter average wait time for \n"
						  << "           -----------------------------\n"
						  << "            Morning                     \n"
						  << "                      Afternoon         \n"
						  << "                                  Night \n";

				std::cout << " Passenger: "; std::cin >> passenger_morning;
				std::cout << "                      "; std::cin >> passenger_afternoon;
				std::cout << "                                  "; std::cin >> passenger_night;

				std::cout << " Minibus  : "; std::cin >> minibus_morning;
				std::cout << "                      "; std::cin >> minibus_afternoon;
				std::cout << "                                  "; std::cin >> minibus_night;

				std::cout << "           -----------------------------\n";
				std::cout << "            It the first stop?  [y/n] _\b"; std::cin >> change; if (change != 'y') type = false;
    		}
			
		#pragma endregion

		int max = 20;
        int num = rand() % int(max / 2 - 2) + 2; // counting from the final
    	
		StopBus Sobornaya(type, minibus_morning, minibus_afternoon, minibus_night, passenger_morning, passenger_afternoon, passenger_night, num);
		Sobornaya.loop();
    	
		std::cout << "\n\n";
    	
    } while (restart());
}