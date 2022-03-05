#define _CRT_SECURE_NO_WARNINGS  fopen

/*
1 LABA  одно 4 и 2 пятых допы
2 лаба любые допы
3 лаба только вторые подпункты 3 штуки
4 лаба 1 основное и  2 допа из 5
5 лаба на выбор 3 задания как допы
6 лаба на выбор 3 допа
7 лаба 1 из 5 , как основа, и три допа из 4
8 лаба 1 из 5, как основа, и допы из 4 -го

*/

//Компоненты файла f – целые двухзначные числа.Получить файл g, образованный из
//f включени - ем только чисел больших некоторого числа, вводимого с клавиатуры.
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

	string num;
	cout << "Введите число: ";
	getline(cin, num);

	while (num > "99" || num < "10")
	{
		cout << "\nВведите двухзначное число: ";
		getline(cin, num);
	}

	int enteredNum = stoi(num),
		number,
		size = 0;

	if ((FILEA = fopen("f.txt", "r")) != NULL)
	{
		for (int i = 0, j = 0; i < l; i++)
		{
			fscanf(FILEA, "%d", &number);

			if (number > enteredNum) 
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
