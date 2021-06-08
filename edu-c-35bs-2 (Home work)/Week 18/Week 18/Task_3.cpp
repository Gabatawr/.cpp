#include "Complex.h"
#include "Header.h"

void do_task_3()
{
	do {
		#pragma region Description
			system("cls");
			cout << "\n     Task 3:\t"
				<< "Создайте структуру, описывающую комплексное число." << "\n\t\t"
				<< "Реализуйте арифметические операции с комплексными числами: сумму, разность, умножение, деление." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
		#pragma endregion

		using gab::complex;
		double ar = 0, ai = 0, br = 0, bi = 0;

		cout << " A = (a+bi) a: "; cin >> ar;
		cout << " A = (" << ar << "+bi) b: "; cin >> ai;
		complex A(ar, ai);
		cout << " A = (" << A << ")\n\n";

		cout << " B = (a+bi) a: "; cin >> br;
		cout << " B = (" << br << "+bi) b: "; cin >> bi;
		complex B(br, bi);
		cout << " B = (" << B << ")\n\n";

		cout << "\n " << A << " + " << B << " = " << A + B;
		cout << "\n " << A << " - " << B << " = " << A - B;
		cout << "\n " << A << " * " << B << " = " << A * B;
		cout << "\n " << A << " / " << B << " = " << A / B;

		cout << "\n\n";
		
	} while (task_restart());
}
