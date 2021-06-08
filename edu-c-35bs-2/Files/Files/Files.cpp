#define _CRT_SECURE_NO_WARNINGS

#include <ctime>
#include <iostream>
#include <Windows.h>

#include <stdio.h>
#include <stdlib.h>

#include "People.h"

using namespace  std;



int main()
{
#pragma region  настройки приложения
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(nullptr));
#pragma endregion

	// MyBook* b = new MyBook();
	//b->load();
	//cout << "\n" << b->peoples[0].Name;


	
	MyBook* b = new MyBook();
	b->peoples[0].dob.day = 10;
	b->peoples[0].dob.month = 4;
	b->peoples[0].dob.year = 1977;
	const char* name = "Olexander Nykytin";
	for (int i = 0; i < 18 ; i++) {
		b->peoples[0].Name[i] = name[i];
	}
	b->peoples[0].Name[18] = '\0';

	const char* phone = "+380965747708";
	for (int i = 0; i < 13; i++) {
		b->peoples[0].Phone[i] = phone[i];
	}
	b->peoples[0].Phone[13] = '\0';
	//----------------
	b->peoples[1].dob.day = 11;
	b->peoples[1].dob.month = 12;
	b->peoples[1].dob.year = 1980;
	const char* name1 = "Александр Никитин";
	for (int i = 0; i < 18; i++) {
		b->peoples[1].Name[i] = name1[i];
	}
	b->peoples[1].Name[18] = '\0';

	const char* phone1 = "+380675599450";
	for (int i = 0; i < 13; i++) {
		b->peoples[1].Phone[i] = phone1[i];
	}
	b->peoples[1].Phone[13] = '\0';

	b->save();
	
	


	//People p = { 257,"Olexander Nykytin", {10,4,1977} };
	//p.save();
	//p.load();
	//p.echo();




}

