#define _CRT_SECURE_NO_WARNINGS  fopen

// омпоненты файла fileA Ц целые отличные от нул€ числа, причем положительных чисел столько же,
//сколько отрицательных.ѕолучить файл fileB, в котором не было бы двух соседних чисел с одинаковым
//знаком(сохранить пор€док следовани€ чисел).

#include<iostream>
#include<stdio.h>
#include<cstdio>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void correctArr(int size, int* a);
void addTheDataFileB(int size, int* a);

int main()
{
	int l = 10;
	int* a = new int[l];
	FILE* FILEA;

	if ((FILEA = fopen("fileA.txt", "r")) != NULL)
	{
		for (int i = 0; i < l; i++)
		{
			fscanf(FILEA, "%d", &a[i]);
			cout << a[i] << endl;
		}
		cout << endl;
		fclose(FILEA);
		correctArr(l, a);
	}
	delete[] a;
}

void correctArr(int size, int* arr) 
{
	int* negNums = new int[size / 2],
	   * posNums = new int[size / 2];
	
	bool firstPos = false;

	for (int i = 0, negI = 0, posI = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			negNums[negI++] = arr[i];
		}
		else
		{
			posNums[posI++] = arr[i];

			if (i == 0)
				firstPos = true;
		}
	}

	for (int i = 0, negI = 0, posI = 0; i < size; i++)
	{
		if (i % 2 == 0 && firstPos)
		{
			arr[i] = posNums[posI++];
		}
		else if (i % 2 != 0 && firstPos)
		{
			arr[i] = negNums[negI++];
		}
		else if (i % 2 != 0 && !firstPos)
		{
			arr[i] = posNums[posI++];
		}
		else if (i % 2 == 0 && !firstPos)
		{
			arr[i] = negNums[negI++];
		}
	}

	addTheDataFileB(size, arr);
	delete[] negNums;
	delete[] posNums;
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
	fclose(FILEB);
}
