//Ввести массив А, в массив В перенести все элементы массива А, стоящие
//правее максимального элемента и имеющие нечетный индекс.Массив В 
//отсортировать по  возрастанию, используя алгоритмы сортировок : «пузы - рек», сортировка Хоара.
#include <iostream>
#include "check.h"

void main()
{
	setlocale(LC_ALL, "ru");
	int n, nB = 0;
	string check;
	do {
		cout << "Введите размер массива: ";
		gl(check);
	} while (!isProved(check, 1, INT_MAX));
	n = stoi(check);
	int* A = new int[n];
	int* B = new int[n];
	int* C = new int[n];
	int max = -100;
	int max_index = -100;
	cout << "Массив А: ";
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 100 - 50;
		if (A[i] > max)
		{
			max = A[i];
			max_index = i;
		}
		cout << A[i] << ((i + 1 != n) ? " " : "\n\n");
	}
	cout << "Массив В: ";
	for (int i = max_index; i < n; i++)
	{
		if (i % 2 != 0)
		{
			B[nB++] = A[i];
			C[nB - 1] = A[i];
			cout << A[i] << ((i + 1 != n) ? " " : "\n\n");
		}
	}
	int timeBubl, timeHoar;
	int start;
	int end;
	start = clock();
	sortMethodPuz(B, nB);
	end = clock();
	timeBubl = end - start;
	start = clock();
	SortMethodHoar(C, 0, nB - 1);
	end = clock();
	timeHoar = end - start;
	cout << "\n\nМассив В после сортировки пузырьком: ";
	for (int i = 0; i < nB; i++)
	{
		cout << B[i] << ((i + 1 != nB) ? " " : "\n\n");
	}
	cout << "Сортировка пузырьком заняла " << timeBubl << " миллисекунд\n";
	cout << "Сортировка методом Хоара заняла " << timeHoar << " миллисекунд\n";
}