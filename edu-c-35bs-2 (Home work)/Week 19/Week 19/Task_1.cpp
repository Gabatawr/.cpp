#include "Header.h"

struct book
{
	char* title;
	char* author;
	char* publisher;
	char* genre;

	book ()
	{
		title     = nullptr;
		author    = nullptr;
		publisher = nullptr;
		genre     = nullptr;
	}

	~book ()
	{
		delete[] title;
		delete[] author;
		delete[] publisher;
		delete[] genre;
	}
	
	void empty ()
	{
		this->title     = nullptr;
		this->author    = nullptr;
		this->publisher = nullptr;
		this->genre     = nullptr;
	}

	void print () const
	{
		cout << "\n ┌╥──────━┓";
		cout << "\n │║ ----- │ Title:\t";     str_echo(this->title);
		cout << "\n │║ ----- │ Author:\t";    str_echo(this->author);
		cout << "\n │║ ----- │ Publisher:\t"; str_echo(this->publisher);
		cout << "\n │║ ----- │ Genre:\t";     str_echo(this->genre);
		cout << "\n └╨──────━┛";
	}

	void edit()
	{
		cout << "\n old Title: ";     str_echo(this->title);     cout << "; new Title: ";     str_cin(this->title);
		cout << "\n old Author: ";    str_echo(this->author);    cout << "; new Author: ";    str_cin(this->author);
		cout << "\n old Publisher: "; str_echo(this->publisher); cout << "; new Publisher: "; str_cin(this->publisher);
		cout << "\n old Genre: ";     str_echo(this->genre);     cout << "; new Genre: ";     str_cin(this->genre);
	}
	
	friend void book_rand(book*&, int count);

	friend void len_sort_in_range    (book* arr_book, int first, int last, int book_field);
	friend void qsort_by_letter_index(book* arr_book, int first, int last, int index, int book_field);
	friend int last_letter_pos       (book* arr_book, int first, int last, int index, int book_field);
	friend void alph_sort_by_index   (book* arr_book, int first, int last, int index, int book_field);
	friend void alph_sort            (book* arr_book, int arr_size, int book_field);

	char* operator [] (int index) const
	{
		if (index == 0) return &*this->title;
		if (index == 1) return &*this->author;
		if (index == 2) return &*this->publisher;
		if (index == 3) return &*this->genre;
		return nullptr;
	}
};


void rand_title    (char*& str);
void rand_author   (char*& str);
void rand_publisher(char*& str);
void rand_genre    (char*& str);


void do_task_1()
{
	do {
#pragma region Description
		system("cls");
		cout << "\n     Task 1:\t"
			<< "Разработайте программу «Библиотека»." << "\n\t\t"
			<< "Создайте структуру «Книга» (название, автор, издательство, жанр)." << "\n\t\t"
			<< "Создайте массив из 10 книг. Реализуйте для него следующие возможности:" << "\n\t\t"
			<< " - Редактировать книгу;" << "\n\t\t"
			<< " - Печать всех книг;" << "\n\t\t"
			<< " - Поиск книг по автору;" << "\n\t\t"
			<< " - Поиск книги по названию;" << "\n\t\t"
			<< " - Сортировка массива по названию книг;" << "\n\t\t"
			<< " - Сортировка массива по автору;" << "\n\t\t"
			<< " - Сортировка массива по издательству." << "\n"
			<< "___________________________________________________________________________________________________________________" << "\n\n";
#pragma endregion

		int count = 10;
		book* booklist = nullptr;
		book_rand(booklist, count);
		
		int choice = 0;
		do
		{
			choice = -1;
			while (choice < 0 || choice > 3)
			{
				cout << "\n 1. Печать\n 2. Поиск\n 3. Сортировка.\n 0. Выход\n Enter: _\b";
				cin >> choice;
			} 
			if (choice == 0) continue;
			
			switch (choice)
			{
			case 1:
				for (auto i = 0; i < count; i++)
				{
					cout << "\n #" << i + 1;
					booklist[i].print();
					cout << "\n--------------------------------------------------------------------------";
				}

				bookedit:
					cout << "\n Меню #0; Редактировать #"; cin >> choice;
					if (choice > 0 && choice <= count) booklist[choice - 1].edit();
				if (choice == 0) choice = -1;
				break;

			case 2:
				choice = -1;
				while (choice < 0 || choice > 2)
				{
					cout << "\n 1. По автору\n 2. По названию\n 0. Назад\n Enter: _\b";
					cin >> choice;
				}
				if (choice == 1 || choice == 2)
				{
					if (choice == 1) cout << "\n Введите автора: ";
					else             cout << "\n Введите название: ";
					char* str = str_cin();
					
					char* key = nullptr;
					bool trigger = false;
					for (auto i = 0; i < count; i++)
					{
						if (choice == 1) key = booklist[i].author;
						else             key = booklist[i].title;
						
						int c = str_count_word(key, str);
						if (c > 0)
						{
							cout << "\n #" << i + 1;
							booklist[i].print();
							cout << "\n--------------------------------------------------------------------------";
							if (!trigger) trigger = true;
						}
					}
					delete[] str;
					if (trigger) goto bookedit;
				}
				if (choice == 0) choice = -1;
				break;

			case 3:
				choice = -1;
				while (choice < 0 || choice > 3)
				{
					cout << "\n 1. По автору\n 2. По названию\n 3. По издательству\n 0. Назад\n Enter: _\b";
					cin >> choice;
				}
				if (choice == 0) choice = -1;
				else
				{
					int book_field = 0;
					if (choice == 1) book_field = 1;
					if (choice == 2) book_field = 0;
					if (choice == 3) book_field = 2;

					alph_sort(booklist, count, book_field);
				}
				break;
			}
		} while (choice != 0);
		
		delete[] booklist;
		
	} while (task_restart());
}


void book_rand(book*& booklist, int count)
{
	booklist = new book[count];
	
	for (auto i = 0; i < count; i++)
	{
		rand_title    (booklist[i].title);
		rand_author   (booklist[i].author);
		rand_publisher(booklist[i].publisher);
		rand_genre    (booklist[i].genre);
	}
}


void rand_title    (char*& str)
{
	// Общее количество строк в массиве
	const int count = 100;
	const int len_limit = 34;

	// Массив
	const char* data[count] = {
 "Accomplishment Of The Girl"
,"Adored By Love"
,"Advancement Of Physics"
,"Agent At The Museum"
,"Airplane Of Secrets"
,"Alive In The Dungeons"
,"Ancestors Of The Fields"
,"Angels Without Fear"
,"Animals And Boys"
,"Animals Of The Mountains"
,"Annihilation Of Suffering"
,"Bandits With Money"
,"Battle Of The Town"
,"Becoming The Apocolypse"
,"Books Of The World"
,"Boy And Angel"
,"Boy From The Forests"
,"Boys Of Perfection"
,"Carnage Of Time"
,"Clouds From Beyond The Grave"
,"Comedian Puzzle"
,"Comfort Of Your Garden"
,"Commanders From Outer Space"
,"Companion Of The Mountain"
,"Cool At My House"
,"Cow Of My House"
,"Crafting With My Father"
,"Descendants And Foreigners"
,"Dinosaurs And Birds"
,"Doctors And Rats"
,"Doctors And Traitors"
,"Dog Of The Wind"
,"Ducks Of Yesterday"
,"Enemies And Demons"
,"Fools Mocks Me"
,"Foundation Of Fond Memories"
,"Friends With A Crush"
,"Frightened Of The Portal"
,"Frozen By The North"
,"Giant In My Town"
,"Girl Of My Dreams"
,"Girlfriend With A Crush"
,"Growing By The Forest"
,"Helping The Stars"
,"History Without Glory"
,"Horses During Halloween"
,"Humans Of A Painting"
,"Hunter Of Darkness"
,"Husbands And Loves"
,"Inventor Of Damnation"
,"Inventors And Widows"
,"Jealous Of My Friend"
,"Knight Of Stunts"
,"Little Dragons And Little Birds"
,"Living In The City"
,"Longing For Eternity"
,"Lord Of Heaven"
,"Lords Of Reality"
,"Meeting In The End"
,"Moons Of The Jungle"
,"Obliteration Of Twilight"
,"People Of The East"
,"Pilot Of The Outlands"
,"Pocket Of Silver"
,"Puppies Of Stone"
,"Raven Makeover"
,"Revival Of The South"
,"Robots And Doctors"
,"Robots And Hobgoblins"
,"Robots Of The Flight"
,"Sailing Into The City"
,"Serpents And Soldiers"
,"Signs Of The East"
,"Skeletons And Freaks"
,"Slaves With Gold"
,"Snakes Of A Shadow"
,"Soldiers And Wives"
,"Soldiers Without Fear"
,"Songs Job"
,"Sounds Of The Abyss"
,"Spiders And Heroes"
,"Stranger And Dog"
,"Stranger Of War"
,"Strangers And Men"
,"Student At The Tombs"
,"Temptation During Lunch"
,"Temptation Under My Bed"
,"Toads And Little Birds"
,"Traitors With Sins"
,"Travel To The Angels"
,"Tree Of Nature"
,"Undoing Of Anguish"
,"Unity Without Faith"
,"Valentine In The Mountain"
,"Veteran Of The Sands"
,"Victory Of Mars"
,"Village Of The Moon"
,"Vultures And Wolves"
,"Vultures Without Eyes"
,"World Of Yearning"
	};

	// Рандомное число в диапазоне количества
	int n = rand() % count;

	// Копируем в строку
	str = new char[len_limit];
	int i = 0; while (data[n][i] != '\0') str[i] = data[n][i++];
	str[i] = '\0';

	// Обрезаем все лишнее после '\0'
	if (i < len_limit - 1) str_cut(str);
}

void rand_author   (char*& str)
{
	// Общее количество строк в массиве
	const int count = 100;
	const int len_limit = 24;

	// Массив
	const char* data[count] = {
 "Abril Nunez"
,"Adison Fox"
,"Aditya Waters"
,"Akira Frye"
,"Alec Miranda"
,"Alexzander Whitehead"
,"Alijah Allison"
,"Allan Zhang"
,"Amelie Hardy"
,"Anthony Summers"
,"Anton Diaz"
,"Armando Terry"
,"Asher Ellis"
,"Ashtyn Crosby"
,"Aylin Morris"
,"Bianca Bowers"
,"Bradley Trujillo"
,"Brady Simmons"
,"Brayan Buck"
,"Braydon Watson"
,"Bridger Fowler"
,"Brooklynn Salinas"
,"Bryanna Terry"
,"Cedric Torres"
,"Cesar Cohen"
,"Chelsea Villegas"
,"Cora Lewis"
,"Dana Berry"
,"Dangelo Landry"
,"Darwin Mahoney"
,"Davis Gill"
,"Dax Lang"
,"Devyn Park"
,"Donald Goodman"
,"Elaina Massey"
,"Elizabeth Knapp"
,"Emmalee Rivera"
,"Erin Hutchinson"
,"Eugene Case"
,"Fatima Haney"
,"Gilbert Wheeler"
,"Gisselle Stanley"
,"Gunner Morton"
,"Harold Norton"
,"Harry Ho"
,"Hayley Newton"
,"Heath Franco"
,"Heather Hunt"
,"Helen Howard"
,"Jada Alexander"
,"Jakayla Koch"
,"Jazlynn Grant"
,"Jenny May"
,"Jessie Cain"
,"Johnathon Lin"
,"Junior Nash"
,"Justus Cook"
,"Kael Hubbard"
,"Kaitlynn Ponce"
,"Kayla Hutchinson"
,"Kendall Reynolds"
,"Kingston Delgado"
,"Larissa Garza"
,"Layton Ayers"
,"Leon Khan"
,"Leon Sloan"
,"Lilly Owen"
,"Makena Allison"
,"Malachi Prince"
,"Mark Petty"
,"Matthew Ali"
,"Maya Boone"
,"Mckayla Browning"
,"Meghan Wilkinson"
,"Melody Carter"
,"Meredith Cooper"
,"Mohammad Baker"
,"Nathan Cline"
,"Nicole Hinton"
,"Nikhil Mcknight"
,"Paris Blevins"
,"Presley Hurst"
,"Raina Huang"
,"Raquel Long"
,"Raven Barnett"
,"Regina Neal"
,"Ruben Sandoval"
,"Sage Malone"
,"Sanai Bradford"
,"Sarai Santos"
,"Savanah Leon"
,"Savanah Mcknight"
,"Shannon Rivera"
,"Silas Reynolds"
,"Taniya Schmidt"
,"Teagan Watts"
,"Tiana Rose"
,"Tianna Leonard"
,"Wesley Frederick"
,"Zane Woods"
	};

	// Рандомное число в диапазоне количества
	int n = rand() % count;

	// Копируем в строку
	str = new char[len_limit];
	int i = 0; while (data[n][i] != '\0') str[i] = data[n][i++];
	str[i] = '\0';

	// Обрезаем все лишнее после '\0'
	if (i < len_limit - 1) str_cut(str);
}

void rand_publisher(char*& str)
{
	// Общее количество строк в массиве
	const int count = 100;
	const int len_limit = 32;

	// Массив
	const char* data[count] = {
 "Tiki Publishing"
,"Reed Elsevier"
,"Penguin Random House"
,"Harper Collins"
,"Simon and Schuster"
,"Phoenix Publishing and Media"
,"Phoenix Yard Books"
,"Pan Macmillan"
,"Bloomsbury"
,"Arbordale Publishing"
,"Arcade Publishing"
,"Arcadia Publishing"
,"Arkham House"
,"Armida Publications"
,"Bi Publishing"
,"Beacon Publishing"
,"John Blake Publishing"
,"Capstone Publishers"
,"Flame Tree Publishing"
,"Morgan James Publishing"
,"Manning Publications"
,"Mother Tongue Publishing"
,"Medknow Publications"
,"Tuttle Publishing"
,"Tachyon Publications"
,"City Lights Publishers"
,"Dover Publications"
,"Graywolf Press"
,"Dorrance Publishing Company"
,"Gantec Publishing Solutions"
,"Kensington Publishing Corp"
,"Ripple Grove Press"
,"North Atlantic Books"
,"Wiley"
,"Balboa Press"
,"BookPress Publishing"
,"Anchor Book Press"
,"Lee and Low Books"
,"The Open Book Press"
,"Hidden Brook Press"
,"Little Book Press"
,"Lakewater Press"
,"Stormbird Press"
,"Autumn House Press"
,"Inkwater Press"
,"TouchPoint Press"
,"Alchemy Press Book of Horrors"
,"Tradewind Books"
,"Blossom Spring Publishing"
,"Queer Pack"
,"Coffeetown Press"
,"Eerdmans"
,"Grey Book Press"
,"Hydra Publications"
,"Conundrum Press"
,"Chelsea Green Publishing"
,"House of Anansi Press"
,"August House Publishers"
,"Blue manatee press"
,"Shambhala"
,"Green Frog Publishing"
,"Brick Cave Media"
,"Living Springs Publishers LLP"
,"Korero Press"
,"City Lights Press"
,"Electio Publishing"
,"Weasel Press"
,"Alfresco Press"
,"Native Ink Press"
,"Virgogray Press"
,"Torquere Press"
,"Pants On Fire Press"
,"Figroot Press"
,"Christian Publishing"
,"Wordpool Press"
,"Ink Smith Publisher"
,"Wolfpack Publishing"
,"Moonshine Cove Publishing LLC"
,"WiDo Publishing"
,"Mason Press"
,"Neverland Publishing Company"
,"The Key Publishing House Inc"
,"Divertir Publishing"
,"John Hunt Publishing"
,"White Knuckle Press"
,"Anthem Press"
,"Writerists House"
,"Lore Lush Publishing"
,"Tiny Fox Press"
,"Echoic Mobile Press"
,"Blue Swan Publishing"
,"Regal House Publishing"
,"Ink Smith Publishing"
,"Tirgearr Publishing"
,"Triplicity Publishing"
,"Coventry House Publishing"
,"Sleepytown Press"
,"Leo Publishing LLC"
,"Biblio Publishing"
,"Press Horrs"
	};

	// Рандомное число в диапазоне количества
	int n = rand() % count;

	// Копируем в строку
	str = new char[len_limit];
	int i = 0; while (data[n][i] != '\0') str[i] = data[n][i++];
	str[i] = '\0';

	// Обрезаем все лишнее после '\0'
	if (i < len_limit - 1) str_cut(str);
}

void rand_genre    (char*& str)
{
	// Общее количество строк в массиве
	const int count = 10;
	const int len_limit = 12;

	// Массив
	const char* data[count] = {
 "Adventure"
,"Children"
,"Drama"
,"Fantasy"
,"Horror"
,"Humor"
,"Mystery"
,"Nonfiction"
,"Romance"
,"Sci-Fi"
	};

	// Рандомное число в диапазоне количества
	int n = rand() % count;

	// Копируем в строку
	str = new char[len_limit];
	int i = 0; while (data[n][i] != '\0') str[i] = data[n][i++];
	str[i] = '\0';

	// Обрезаем все лишнее после '\0'
	if (i < len_limit - 1) str_cut(str);
}


void len_sort_in_range(book* arr_book, int first, int last, int book_field)
{
	for (int i = first; i < last; i++)
		for (int j = i + 1; j <= last; j++)
			if (str_compare_length(arr_book[i][book_field], arr_book[j][book_field]) > 0) {
				book tmp = arr_book[i];
				arr_book[i] = arr_book[j];
				arr_book[j] = tmp;
				tmp.empty();
			}
}

void qsort_by_letter_index(book* arr_book, int first, int last, int index, int book_field)
{

	int f = first;
	int l = last;
	int mid = arr_book[(f + l) / 2][book_field][index];

	while (f < l) {
		while (arr_book[f][book_field][index] < mid) f++;
		while (arr_book[l][book_field][index] > mid) l--;
		if (f <= l) 
		{
			book tmp = arr_book[f];
			arr_book[f++] = arr_book[l];
			arr_book[l--] = tmp;
			tmp.empty();
		}
	}

	if (first < l) qsort_by_letter_index(arr_book, first, l, index, book_field);
	if (f < last) qsort_by_letter_index(arr_book, f, last, index, book_field);
}

int last_letter_pos(book* arr_book, int first, int last, int index, int book_field)
{
	for (int i = first + 1, tmp = arr_book[first][book_field][index]; i <= last; i++)
	{
		if (tmp == arr_book[i][book_field][index]) continue;
		return i - 1;
	}
	return last;
}

void alph_sort_by_index(book* arr_book, int first, int last, int index, int book_field)
{
	int f, l = last, ind = index;

	qsort_by_letter_index(arr_book, first, last, index, book_field);

	last = last_letter_pos(arr_book, first, last, index, book_field);
	f = last + 1;

	len_sort_in_range(arr_book, first, last, book_field);

	index++;
	while (first <= last)
	{
		if (arr_book[first][book_field][index] == '\0') { first++; continue; }
		break;
	}

	if (first < last) alph_sort_by_index(arr_book, first, last, index, book_field);
	if (f < l) alph_sort_by_index(arr_book, f, l, ind, book_field);
}

void alph_sort(book* arr_book, int arr_size, int book_field)
{
	for (auto first = 0, last = arr_size - 1; first < last; first = last + 1, last = arr_size - 1)
	{
		alph_sort_by_index(arr_book, first, last, 0, book_field);
		last = last_letter_pos(arr_book, first, last, 0, book_field);
	}
}