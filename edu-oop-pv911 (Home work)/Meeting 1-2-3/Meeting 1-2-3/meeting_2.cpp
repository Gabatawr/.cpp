#include "header.h"

#include "Contact.h"
#include "Group.h"

/*
 * Тема:
 *   Конструкторы, деструкторы
 *
 * Задание.
 *   Создайте приложение "Телефонная книга".
 *   
 *   Необходимо хранить данные об абоненте (ФИО, домашний телефон, рабочий телефон, мобильный телефон,
 *   дополнительная информация о контакте) внутри соответствующего класса.
 *   
 *   Наполните класс переменными-членами, функциями-членами, конструкторами,
 *   inline-функциями-членами, используйте инициализаторы, реализуйте деструктор.
 *   
 *   Обязательно необходимо выделять динамически память под ФИО.
 *   
 *   Предоставьте пользователю возможность добавлять новых абонентов, удалять абонентов,
 *   искать абонентов по ФИО, показывать всех абонентов, сохранять информацию в файл и загружать из файла.
 */

void help()
{
    std::cout
		<< "\n print  all  -key :all"
		<< "\n print 1,5,3 -key :number(s)"
		<< "\n print 1..10 -key :range"

        << "\n\n search \"*\" or '*' -key :*what find?"
	
        << "\n\n sort -key / add # -key / edit # -key / remove # / save / exit"
	
        << "\n\n -key ────────────╮"
		<<   "\n -n :name         │"
		<<   "\n -h :home phone   │"
		<<   "\n -w :work phone   │"
		<<   "\n -m :mobile phone │"
		<<   "\n -i :info         │"
		<<   "\n ─────────────────╯\n";
}

void meeting_2()
{
    Group Alpha((char*)"group.txt");
    char* commands = nullptr;
	
    while (true) 
    {
        delete[] commands;
        std::cout << "\n\n -? :help\tEnter: ";
    	commands = str_in();std::cout << "\n";
    	
        if (str_has_word(commands, (char*)"print" )) { Alpha.print (commands); continue; }
        if (str_has_word(commands, (char*)"search")) { Alpha.search(commands); continue; }
        if (str_has_word(commands, (char*)"edit"  )) { Alpha.edit  (commands); continue; }
        if (str_has_word(commands, (char*)"sort"  )) { Alpha.sort  (commands); continue; }
        if (str_has_word(commands, (char*)"add"   )) { Alpha.add   (commands); continue; }
        if (str_has_word(commands, (char*)"remove")) { Alpha.remove(commands); continue; }
        if (str_has_word(commands, (char*)"save"  )) { Alpha.save  ();         continue; }
        if (str_has_word(commands, (char*)"-?"    )) { help        ();         continue; }
        if (str_has_word(commands, (char*)"exit"  )) { return; }
    	
        std::cout << " Invalid command..";
    }
}