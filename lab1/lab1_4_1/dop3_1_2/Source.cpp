//Написать функцию fmin с переменным числом
//параметров, в которой определяется
//минимальное из чисел типа int.

#include <iostream>
using namespace std;

int fmin(int n, ...);

void main()
{
	cout << fmin(4, 1, -5, 2323, 232) << endl;
	cout << fmin(2, 1, -5) << endl;
	cout << fmin(3, -90, -5, 22432);
}

int fmin(int n, ...)
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