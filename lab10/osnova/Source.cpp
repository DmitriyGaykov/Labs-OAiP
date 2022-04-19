//Дано n различных натуральных чисел(n = 5).Напечатать все перестановки этих чисел.
#include <iostream>
#include "check.h"
#include <vector>
#include <set>

const int MAX = 5;
set<int> combs;
void remove(vector<int>, int);

void main()
{
	setlocale(LC_ALL, "ru");
	string check;
	unsigned int n;
	bool isRep = false;
	vector<int> numbers;
	cout << "Введите N: ";
	gl(check);
	while (!isProved(check, 1, MAX))
	{
		cls;
		cout << "Ошибка. Введите N(1 - " << MAX << "): ";
		gl(check);
	}
	cls;
	n = stoi(check);
	ent; ent;
	for (int i = 0, num; i < n; i++)
	{
		isRep = false;
		num = rand() % n + 1;
		for (int j : numbers)
		{
			if (j == num)
			{
				i--;
				isRep = true;
				break;
			}

		}
		if (!isRep)
		{
			numbers.push_back(num);
		}
	}
	cout << "Созданные числа: \t";
	for (auto i : numbers)
	{
		cout << i << ";\t";
	}
	ent;
	remove(numbers, n);
	ent;
	int point = 1;
	for (auto i : combs)
	{
		cout << point++ << ")\t" << i << endl;
	}
}

void remove(vector<int> numbers, int n)
{
	bool isRep;
	int Comb = 0,
		mainN = 0;
	int* Nums = new int[n];
	if (combs.size() != fact(n))
	{
		for (int i = 0, num; i < n; i++)
		{
			isRep = false;
			num = rand() % n;
			for (int j = 0; j < i; j++)
			{
				if (Nums[j] == num)
				{
					isRep = true;
					i--;
					break;
				}
			}
			if (!isRep)
			{
				Nums[i] = num;
			}
		}
		for (int i = pow(10, n - 1), j = 0; i >= 1; i /= 10, j++)
		{
			mainN += i * numbers[Nums[j]];
		}
		combs.insert(mainN);
		delete[] Nums;
		return remove(numbers, n);
	}
	delete[]Nums;
}