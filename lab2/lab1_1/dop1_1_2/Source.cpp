//2. Компоненты файла f – целые двухзначные числа(положительные и отрицательные).
//Полу - чить файл g, образованный из f включением только чисел кратных K.

#define _CRT_SECURE_NO_WARNINGS  fopen

#include<iostream>
#include<stdio.h>
#include<cstdio>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void addTheDataFileB(int size, int* a);

int main()
{
	setlocale(LC_ALL, "ru");
	int l = 7;
	int* a = new int[l];
	FILE* FILEA;

	string k;
	cout << "Введите число: ";
	getline(cin, k);

	while (k > "100" && k < "-100")
	{
		cout << "\nОшибка. Введите число: ";
		getline(cin, k);
	}

	int enteredNum = stoi(k),
		number,
		size = 0;

	if ((FILEA = fopen("f.txt", "r")) != NULL)
	{
		for (int i = 0, j = 0; i < l; i++)
		{
			fscanf(FILEA, "%d", &number);

			if (number % enteredNum == 0)
			{
				a[j++] = number;
				cout << a[j - 1] << "\t";
			}

			size = j;
		}
		cout << endl << endl;

		addTheDataFileB(size, a);

		fclose(FILEA);

	}

}

void addTheDataFileB(int size, int* a)
{
	FILE* FILEB;
	if ((FILEB = fopen("g.txt", "w")) != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			fprintf(FILEB, "%d\t", a[i]);
		}
	}
}