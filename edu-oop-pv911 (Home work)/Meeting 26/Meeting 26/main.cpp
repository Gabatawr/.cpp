#include "header.h"

#pragma region Description

	/**
	 * Тема:
	 *   Потоки.
	 *   
	 * Задание:
	 *   Создать класс СПРАВОЧНИК со следующими полями:
	 *   1. Название фирмы;
	 *   2. Владелец;
	 *   3. Телефон;
	 *   4. Адрес;
	 *   5. Род деятельности.
	 *
	 *   Реализовать следующие возможности:
	 *   1. Поиск по названию;
	 *   2. Поиск по владельцу;
	 *   3. Поиск по номеру телефона;
	 *   4. Поиск по роду деятельности;
	 *   5. Показ всех записей и добавление.
	 *     
	 *   Вся информация, должна сохранятся в файле, должна быть реализована возможность добавления новых данных. 
	 */

#pragma endregion

void help()
{
    cout
        << "\n print  all  -key :all"
        << "\n print # # # -key :number(s)"
        << "\n print # > # -key :range\n"

        << "\n del     #        :number"
        << "\n del   # > #      :range"

        << "\n\n search \"*\" or '*' -key :*what find?"

        << "\n\n sort -key / add # -key / edit # -key / save / exit"

        << "\n\n -key ────────╮"
          << "\n -c :company  │"
          << "\n -b :busyness │"
          << "\n -o :owner    │"
          << "\n -p :phone    │"
          << "\n -a :address  │"
          << "\n ─────────────╯\n";
}

int main()
{
#pragma region Presetting

    srand(time(0));
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

#pragma endregion

    const char* file = "list.save";
    Directory notebook(file);
	
    string commands;

    while (true)
    {
        cout << "\n\n -? :help\tEnter: ";
        std::getline(cin,commands);
        key->set(commands);
        cout << endl;

        if (commands.find("print")  != string::npos) { notebook.print  (commands); continue; }
        if (commands.find("search") != string::npos) { notebook.search (commands); continue; }
        if (commands.find("edit")   != string::npos) { notebook.edit   (commands); continue; }
        if (commands.find("add")    != string::npos) { notebook.add    (commands); continue; }
        if (commands.find("del")    != string::npos) { notebook.del    (commands); continue; }
        if (commands.find("save")   != string::npos) { notebook.save   (file);     continue; }
        if (commands.find("-?")     != string::npos) { help();                     continue; }
        if (commands.find("exit")   != string::npos) {                             return 0; }

        cout << " Invalid command..";
    }
}