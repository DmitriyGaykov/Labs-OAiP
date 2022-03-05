//Написать функцию fmax с переменным числом параметров, которая находит минимальное из чисел типа int или из чисел типа int,
//тип параметров определяется с помощью первого параметра функции.

#include <iostream>
using namespace std;

int fmax(int n, ...);

void main()
{
	cout << fmax(4, 1, -5, 2323, 232) << endl;
	cout << fmax(2, 1, -5) << endl;
	cout << fmax(3, -90, -5, 22432);
}

int fmax(int n, ...)
{
	int* numbers = new int[n];
	int min = *(&n + 1);

	for (int i = 1; i <= n; i++)
	{
		numbers[i - 1] = *(&n + i);
		if (min > numbers[i - 1])
		{
			min = numbers[i - 1];
		}
	}

	delete[] numbers;
	return min;
}
