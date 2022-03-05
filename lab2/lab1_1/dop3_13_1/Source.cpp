//Компоненты файла fileA –  целые числа, значения которых повторяются.
//Получить файл fileB, образованный из fileA числами, которые встречаются в fileA более 2 раз.

#define _CRT_SECURE_NO_WARNINGS  fopen

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void addTheDataFileB(int size, int* a);

int main()
{
	setlocale(LC_ALL, "ru");
	const int l = 15;
	int a[l];

	int countsRep[l],
		numbers[l];

	FILE* FILEA;

	int number,
		num = 0;

	if ((FILEA = fopen("fileA.txt", "r")) != NULL)
	{
		for (int i = 0; i < l; i++)
		{
			fscanf(FILEA, "%d", &number);
			a[i] = number;
		}

		for (int i = 0, cntRepeating = 1; i < l; i++, cntRepeating = 1) 
		{
			for (int j = 0; j < l; j++)
			{
				if(a[j] == a[i] && j < i)
				{
					break;
				}
				if (a[i] == a[j] && i != j)
				{
					cntRepeating++;
				}
			}

			if (cntRepeating > 2)
			{
				numbers[num++] = a[i];
				cout << numbers[num - 1] << "\t";
			}
		}

		cout << endl << endl;

		addTheDataFileB(num ,numbers);

		fclose(FILEA);

	}

}

void addTheDataFileB(int size, int* a)
{
	FILE* FILEB;
	if ((FILEB = fopen("fileB.txt", "w")) != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			fprintf(FILEB, "%d\t", a[i]);
		}
	}
}