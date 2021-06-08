#include "header.h"

int main()
{
#pragma region Presetting

	srand(time(0));
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

#pragma endregion
	
	do { system("cls");

		int gold_light = 0, gold_dark = 0;
		int* gold = nullptr;
		
		List<gab::Character*> Army[2];
		for (auto i = 0; i < 100; i++) Army[0].push_head(gab::Character::get(rand() % 100, rand() % 100, gab::Type((rand() % 3) + 3))); // Dark
		for (auto i = 0; i < 100; i++) Army[1].push_head(gab::Character::get(rand() % 100, rand() % 100, gab::Type(rand() % 3)));       // Light

		// random first side
		int one = rand() % 2, two = rand() % 2;
		while (one == two) { two = rand() % 2; }

		// table
		std::cout << "\n Team\t+/-     char\t\t Team\t+/-     gold\n------------------------------------------------------";
		
		// battle
		bool win;
		while (true)
		{
			if (not Army[one].empty())
			{
				if (not Army[two].empty())
				{
					if (Army[one].head()->make_damage() > Army[two].head()->get_hp())
					{
						Army[one].head()->get_side() == 1 ? gold = &gold_light : gold = &gold_dark;
						int gold_tmp = Army[two].head()->death();
						delete Army[two].pop_head();
						
						std::cout << "\n" << (Army[one].head()->get_side() == 0 ? " Light" : " Dark") << "\t-1\t" << Army[two].size() << "\t\t"
								          << (Army[one].head()->get_side() == 1 ? " Light" : " Dark") << "\t+" << gold_tmp <<"\t" << (*gold += gold_tmp);

						if (*gold >= 100)
						{
							*gold -= 100;
							Army[one].push_head(gab::Character::get(rand() % 100, rand() % 100, gab::Type(Army[one].head()->get_side() == 1 ? rand() % 3 : (rand() % 3) + 3)));
							std::cout << "\n" << (Army[one].head()->get_side() == 1 ? " Light" : " Dark") << "\t+1\t" << Army[one].size() << "\t\t"
										      << (Army[one].head()->get_side() == 1 ? " Light" : " Dark") << "\t-100\t" << *gold;
						}
					}
					else Army[two].head()->take_damage(Army[one].head()->make_damage());
				}
				else
				{
					win = Army[one].head()->get_side();
					break;
				}
			}
			else
			{
				win = Army[two].head()->get_side();
				break;
			}
			std::swap(one, two);
		}

		// result
		std::cout << "\n\n Winer army: " << (win == 1 ? "Light" : "Dark") << "\n\n";
		
	} while (restart());
}