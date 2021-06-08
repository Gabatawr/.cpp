#include "header.h"
#include "Reservoir.h"

/**
 * Тема:
 *   Константная функция­член, explicit конструктор.
 *
 * Задание.
 *   Разработать класс Reservoir (водоем). Класс должен обязательно иметь поле «название».
 *   
 *   Класс должен содержать: конструктор по умолчанию, конструктор с параметрами,
 *   при необходимости реализовать деструктор и конструктор копирования.
 *   
 *   Добавить методы для:
 *     1. Определения приблизительного объема (ширина*длина*максимальная глубина);
 *     2. Определения площади водной поверхности;
 *     3. Метод для проверки относятся ли водоемы к одному типу (море-море; бассейн-пруд);
 *     4. Для сравнения площади водной поверхности водоемов одного типа;
 *     5. Для копирования объектов;
 *     6. Остальные методы на усмотрение разработчика (методы set и get).
 *     
 *   Написать интерфейс для работы с классом.
 *   Реализовать динамический массив объектов класса с возможностью добавления, удаления объектов из массива.
 *   Реализовать возможность записи информации об объектах массива в текстовый файл, бинарный файл.
 *   
 *   Используйте explicit конструктор и константные функции-члены (например, для отображения данных о водоёме и т.д.).
 */

void help()
{
    std::cout << "\n command list: print | add # | remove # | save bin/txt | exit";
}
//-------------------
void print(Reservoir**&, unsigned);
void add(Reservoir**&, unsigned&, int);
void remove(Reservoir**&, unsigned&, int);
//void save(String&);
//-------------------


void meeting_5()
{
    unsigned size = rand() % 17 + 3;
    auto SweetWater = new Reservoir*[size];
    for (auto i = 0; i < static_cast<int>(size); i++) SweetWater[i] = new Reservoir;
	
    String command;
	
    while (true)
    {
        std::cout << "\n\n -? :help\tEnter: ";
        std::cin >> command;
        
        if (command.has("print")) { print(SweetWater, size); continue; }
    	
        if (command.has("add")) { add(SweetWater, size, command.to_int()); continue; }
        if (command.has("remove")) { remove(SweetWater, size, command.to_int()); continue; }
    	
        //if (command.has("save")) { save(command); continue; }
        
        if (command.has("-?")) { help(); continue; }
        if (command.has("exit")) return;

        std::cout << "\n Invalid command..";
        
    }
}

void print(Reservoir**& list, unsigned size)
{
    std::cout << "\n ## | Name\t\t| width\t\t| length\t| max deep\t| area\t\t\t| value"
		<< "\n ---+-------------------+---------------+---------------+---------------+-----------------------+-----------";
	for (auto i = 0; i < static_cast<int>(size); i++)
	{
        std::cout << "\n " << (i < 9 ? "0" : "") << i + 1
            << " | " << list[i]->name
            << (list[i]->name.len() > 9 ? "\t" : "\t\t") << "| " << list[i]->width
            << "\t\t| " << list[i]->length
            << "\t\t| " << list[i]->max_deep
            << "\t\t| " << list[i]->get_area()
            << "\t\t| " << list[i]->get_volume();
	}
}

void add(Reservoir**& new_list, unsigned& size, int index)
{
    if (index == 0) index++;
	
    Reservoir** old_list = new_list;
    new_list = new Reservoir*[++size];

	for (auto i = 0; i < static_cast<int>(size); i++)
	{
        if (i < index - 1) new_list[i] = old_list[i];
        else if (i == index - 1) new_list[i] = new Reservoir;
        else new_list[i] = old_list[i - 1];
	}
    std::cout << "\n Reservoir added";
}

void remove(Reservoir**& new_list, unsigned& size, int index)
{
    if (index == 0 || index > static_cast<int>(size)) return;

    Reservoir** old_list = new_list;
    new_list = new Reservoir * [--size];

    for (auto i = 0; i < static_cast<int>(size); i++)
    {
        if (i < index - 1) new_list[i] = old_list[i];
        if (i == index - 1) delete old_list[i];
        if (i >= index - 1) new_list[i] = old_list[i + 1];
    }

    std::cout << "\n Reservoir removed";
}

//void save(String&);