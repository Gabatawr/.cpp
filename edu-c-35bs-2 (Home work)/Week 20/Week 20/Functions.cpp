#include "Header.h"

void rand_name(char*& first, char*& last)
{
	// Общее количество строк в массиве
	const int count = 200;
	const int len_limit = 12;

	// Массив
	const char* data[count] = {
"Abril", "Nunez",
"Adison", "Fox",
"Aditya", "Waters",
"Akira", "Frye",
"Alec", "Miranda",
"Alexzander", "Whitehead",
"Alijah", "Allison",
"Allan", "Zhang",
"Amelie", "Hardy",
"Anthony", "Summers",
"Anton", "Diaz",
"Armando", "Terry",
"Asher", "Ellis",
"Ashtyn", "Crosby",
"Aylin", "Morris",
"Bianca", "Bowers",
"Bradley", "Trujillo",
"Brady", "Simmons",
"Brayan", "Buck",
"Braydon", "Watson",
"Bridger", "Fowler",
"Brooklynn", "Salinas",
"Bryanna", "Terry",
"Cedric", "Torres",
"Cesar", "Cohen",
"Chelsea", "Villegas",
"Cora", "Lewis",
"Dana", "Berry",
"Dangelo", "Landry",
"Darwin", "Mahoney",
"Davis", "Gill",
"Dax", "Lang",
"Devyn", "Park",
"Donald", "Goodman",
"Elaina", "Massey",
"Elizabeth", "Knapp",
"Emmalee", "Rivera",
"Erin", "Hutchinson",
"Eugene", "Case",
"Fatima", "Haney",
"Gilbert", "Wheeler",
"Gisselle", "Stanley",
"Gunner", "Morton",
"Harold", "Norton",
"Harry", "Ho",
"Hayley", "Newton",
"Heath", "Franco",
"Heather", "Hunt",
"Helen", "Howard",
"Jada", "Alexander",
"Jakayla", "Koch",
"Jazlynn", "Grant",
"Jenny", "May",
"Jessie", "Cain",
"Johnathon", "Lin",
"Junior", "Nash",
"Justus", "Cook",
"Kael", "Hubbard",
"Kaitlynn", "Ponce",
"Kayla", "Hutchinson",
"Kendall", "Reynolds",
"Kingston", "Delgado",
"Larissa", "Garza",
"Layton", "Ayers",
"Leon", "Khan",
"Leon", "Sloan",
"Lilly", "Owen",
"Makena", "Allison",
"Malachi", "Prince",
"Mark", "Petty",
"Matthew", "Ali",
"Maya", "Boone",
"Mckayla", "Browning",
"Meghan", "Wilkinson",
"Melody", "Carter",
"Meredith", "Cooper",
"Mohammad", "Baker",
"Nathan", "Cline",
"Nicole", "Hinton",
"Nikhil", "Mcknight",
"Paris", "Blevins",
"Presley", "Hurst",
"Raina", "Huang",
"Raquel", "Long",
"Raven", "Barnett",
"Regina", "Neal",
"Ruben", "Sandoval",
"Sage", "Malone",
"Sanai", "Bradford",
"Sarai", "Santos",
"Savanah", "Leon",
"Savanah", "Mcknight",
"Shannon", "Rivera",
"Silas", "Reynolds",
"Taniya", "Schmidt",
"Teagan", "Watts",
"Tiana", "Rose",
"Tianna", "Leonard",
"Wesley", "Frederick",
"Zane", "Woods"
	};

	// odd - first, even - last
	int n, i;

	do { n = rand() % count; } while (n % 2 != 0);
	delete[] first; first = new char[len_limit];
	i = 0; while (data[n][i] != '\0') first[i] = data[n][i++];
	first[i] = '\0';
	if (i < len_limit - 1) str_cut(first);

	do { n = rand() % count; } while (n % 2 == 0);
	delete[] last; last = new char[len_limit];
	i = 0; while (data[n][i] != '\0') last[i] = data[n][i++];
	last[i] = '\0';
	if (i < len_limit - 1) str_cut(last);
}

#pragma region Technical Functions

bool task_restart()
{
	cout << "\n Restart task? (0 / 1)\n Enter: _\b";
	char u_enter; cin >> u_enter;

	if (u_enter == '1') return true;
	if (u_enter == '0') return false;

	cout << " Invalid command..\n";
	return task_restart();
}

#pragma endregion