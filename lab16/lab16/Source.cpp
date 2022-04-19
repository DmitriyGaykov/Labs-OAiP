//Ввести массив А, в массив В скопировать все элементы массива А, 
//имеющие четный индекс.Массив В отсортировать по убыванию, 
//используя алгоритмы сортировок : «пузырек», сортировка простой вставкой.
#include <iostream>
#include "check.h"

void main()
{
	setlocale(LC_ALL, "ru");
	int N, nB = 0;
	int* A;
	int* B;
	int* C;
	string check;
	do {
		cout << "Введите N: ";
		gl(check);
	} while (!isProved(check, 1, INT_MAX));
	N = stoi(check);
	A = new int[N];
	B = new int[N / 2 + 1];
	C = new int[N / 2 + 1];
	cout << "Массив А: ";
	for (int i = 0; i < N; i++)
	{
		A[i] = rand() % 40 - 20;
		cout << A[i] << ((i + 1) != N ? " " : "\n");
		if (i % 2 == 0)
		{
			C[nB] = B[nB] = A[i];
			nB++;
		}
	}

	int timeBubl, timeInst;
	int start;
	int end;
	start = clock();
	sortMethodPuz(B, nB);
	end = clock();
	timeBubl = end - start;
	start = clock();
	sortMethodShella(C, nB);
	end = clock();
	timeInst = end - start;

	cout << "Массив В: ";
	for (int i = 0; i < nB; i++)
	{
		cout << B[i] << ((i + 1) != nB ? " " : "\n");
	}
	cout << "Время сортировки пузырьком: " << timeBubl << " мс\n";
	cout << "Время сортировки простой вставкой: " << timeInst << " мс\n";

	delete[] A;
	delete[] B;
	delete[] C;
}