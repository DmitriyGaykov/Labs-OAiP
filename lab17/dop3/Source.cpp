//Дан массив из 15 целых чисел на отрезке[-5; 5].Упорядочить массив, удалив повторяющиеся элементы.
#include <iostream>
#include "check.h"
using namespace std;
#define N 15

void main()
{
	setlocale(LC_ALL, "ru");
	int a[N];
	int n = N;
	for (auto& i : a)
	{
		i = rand() % 11 - 5;
		cout << i << " ";
	}
	cout << endl;
	sortMethodPuz(a, N);
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] == a[i + 1])
		{
			for (int j = i; j < n - 1; j++)
			{
				a[j] = a[j + 1];
			}
			i--;
			n--;
		}
	}
	ent;

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
	ent;
}