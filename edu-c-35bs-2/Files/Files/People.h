#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


const char*defFileName = "People.dat";

struct Date
{
	char day;
	char month;
	int year;
};

void saveData(Date* d, const char* filename = nullptr) {
	if (filename == nullptr) {
		filename = defFileName;
	}
	FILE* fp;
	fp = fopen(filename, "w");
	if (fp == NULL)
	{
		perror("Error occured while opening data.txt");
		exit(0);
	}
	int size = sizeof(struct Date);
	char* ptr;
	ptr = (char*) d;

	for (int i = 0; i < size; i++)
	{
		putc(*ptr, fp);
		ptr++;
	}

	fclose(fp);
}


void loadData(Date& d, const char* filename = nullptr) {
	if (filename == nullptr) {
		filename = defFileName;
	}
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		perror("Error occured while opening data.txt");
		exit(0);
	}

}


struct People
{
	int Id;
	char Name[20];
	char Phone[15];
	Date dob;

#pragma region �� ������ ������


	//void echo()
	//{
	//	std::cout << "������� " << Id << "\n ���: " << Name
	//		<< "\n ���� ���.: " << (int)dob.day << ":" << (int)dob.month << ":" << (int)dob.year;
	//	std::cout << "\n";
	//}


	//void save(const char* filename = nullptr) {
	//	if (filename == nullptr) {
	//		filename = defFileName;
	//	}
	//	FILE* fp;
	//	fp = fopen(filename, "w");
	//	if (fp == NULL)
	//	{
	//		perror("Error occured while opening data.txt");
	//		exit(0);
	//	}
	//	// TODO Int ����� ������ �������������������� char*
	//	// � ��� �� ������.
	//	putc(Id, fp);

	//	for (int i = 0; i < 80; i++) {
	//		putc(Name[i], fp);
	//	}

	//	putc(dob.day, fp);
	//	putc(dob.month, fp);
	//	putc(dob.year, fp);

	//	fclose(fp);
	//}

	//void load(const char* filename = nullptr ) {
	//	if (filename == nullptr) {
	//		filename = defFileName;
	//	}

	//	FILE* fp = fopen(filename, "r");
	//	if (fp == NULL)
	//	{
	//		perror("Error occured while opening data.txt");
	//		exit(0);
	//	}

	//	Id = getc(fp);
	//	for (int i = 0; i < 80; i++) {
	//		Name[i] = getc(fp);
	//	}

	//	dob.day = getc(fp);
	//	dob.month= getc(fp);
	//	dob.year = getc(fp);

	//	fclose(fp);
	//}
#pragma endregion

};

struct MyBook
{
	int size = 2;
	People* peoples;
	
	MyBook() {
		peoples = new People[size];
	}

	void save(const char* filename = nullptr) {
		if (filename == nullptr) {
			filename = defFileName;
		}
		FILE* fp;
		fp = fopen(filename, "w");
		if (fp == NULL)
		{
			perror("Error occured while opening data.txt");
			exit(0);
		}
		// ���������� ���������� ��������
		char *c;
		c = (char *)&size;
		for (int i = 0; i < sizeof(int); i++)
		{
			putc(*c++, fp);
		}

		// ����������� ���������� � ���� ��� ���������
		c = (char *)peoples;
		int sizeInByte = size * sizeof(struct People);
		for (int i = 0; i < sizeInByte; i++)
		{
			putc(*c, fp);
			c++;
		}
		fclose(fp);
	}

	void load(const char* filename = nullptr) {
		if (filename == nullptr) {
			filename = defFileName;
		}
		FILE* fp;
		fp = fopen(filename, "r");
		if (fp == NULL)
		{
			perror("Error occured while opening data.txt");
			exit(0);
		}

		int sizeInt = sizeof(int);
		int *pti = (int *)malloc(sizeInt);
		int c;
		// ��������� ���������� ��������
		char* buffer = (char *)pti;
		while (sizeInt > 0)
		{
			c = getc(fp);
			if (c == EOF) break;
			*buffer = c;
			buffer++;
			sizeInt--;
		}
		size = *pti;

		std::cout << " ����� � �������� ����� �������:" << size;
		std::cout << " ������� ��������� ��������� � �����: " << ftell(fp) << "\n";

		// �������� ������ ��� ����������� ��������
		if (peoples != nullptr) {
			delete peoples;
			peoples = nullptr;
		}
		peoples = (People*)malloc(size * sizeof(struct People));
		buffer = (char*) peoples;
		// ����� ��������� ����������� �� �����
		while ((c = getc(fp)) != EOF)
		{
			*buffer = c;
			buffer++;
		}

		fclose(fp);
	}

	void loadOne(const char* filename = nullptr) {
		if (filename == nullptr) {
			filename = defFileName;
		}
		FILE* fp;
		fp = fopen(filename, "r");
		if (fp == NULL)
		{
			perror("Error occured while opening data.txt");
			exit(0);
		}

		int sizeInt = sizeof(int);
		int *pti = (int *)malloc(sizeInt);
		int c;
		// ��������� ���������� ��������
		char* buffer = (char *)pti;
		while (sizeInt > 0)
		{
			c = getc(fp);
			if (c == EOF) break;
			*buffer = c;
			buffer++;
			sizeInt--;
		}
		size = *pti;

		std::cout << " ����� � �������� ����� �������:" << size ;
		std::cout << "\n ����� ����� (�� 0) ������ ��������� ???";
		int num; std::cin >> num;
		fseek(fp, sizeInt + num * sizeof(struct People), SEEK_SET);
		// TODO -  ������� ���� �������� � ������� �� �� �����

		
		
	}
};