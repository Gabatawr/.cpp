#include "Header.h"

struct car
{
	double length;
	double clearance;
	double engine_volume;
	double engine_power;
	double wheel_diameter;
	char* color;
	char* gearbox;

	car(bool autocomplete)
	{
		if (autocomplete)
		{
			length = 4400;
			clearance = 40;
			engine_volume = 4;
			engine_power = 400;
			wheel_diameter = 40;
			color = new char[6] {'b', 'l', 'a', 'c', 'k', '\0' };
			gearbox = new char[5] {'a', 'u', 't', 'o', '\0'};
		}
		else
		{
			cout << "\n - Length mm: ";        cin >> length;
			cout << " - Clearance mm: ";       cin >> clearance;
			cout << " - Engine volume cm3: ";  cin >> engine_volume;
			cout << " - Engine power h.p.: ";  cin >> engine_power;
			cout << " - Wheel diameter mm: ";  cin >> wheel_diameter;
			cout << " - Color: ";              color = str_cin();
			cout << " - Type of gearbox: ";    gearbox = str_cin();
		}
	}

	void print () const
	{
		cout << " Parameters car:";
		if (this->length > 0)         cout << "\n - Length: "           << this->length << "mm";
		if (this->clearance > 0)      cout << "\n - Clearance: "        << this->clearance << "mm";
		if (this->engine_volume > 0)  cout << "\n - Engine volume: "    << this->engine_volume << "cm3";
		if (this->engine_power > 0)   cout << "\n - Engine power: "     << this->engine_power << "h.p.";
		if (this->wheel_diameter > 0) cout << "\n - Wheel diameter: "   << this->wheel_diameter << "mm";
		if (this->color != nullptr)   cout << "\n - Color: ";           str_echo(this->color);
		if (this->gearbox != nullptr) cout << "\n - Type of gearbox: "; str_echo(this->gearbox);
	}

	~car()
	{
		delete[] this->color; 
		delete[] this->gearbox;
	}
};

void do_task_4()
{
	do {
		#pragma region Description
			system("cls");
			cout << "\n     Task 4:\t"
				<< "Реализовать структуру «Автомобиль»" << "\n\t\t"
				<< "(длина, клиренс, объем двигателя, мощность двигателя, диаметр колес, цвет, тип коробки передач)." << "\n\t\t"
				<< "Создайте функции для задания значений, отображения значений, поиска значений." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
		#pragma endregion

		bool autocomplete = true;
		cout << " Autocomplete car parameters? (1 / 0): _\b";
		cin >> autocomplete;
		
		car tmp(autocomplete);
		cout << "\n";
		
		tmp.print();
		
		cout << "\n\n";
	} while (task_restart());
}