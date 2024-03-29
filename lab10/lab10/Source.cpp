﻿//Бином Ньютона определяется как : Сnm = n!/ (m!(n – m)!)
//Рекурсивно описать функцию  C(m, n), где 0 <= m <= n для би - номинального коэффициента Сn.
//
//Формулы имеют следующий вид :
//Сno = Сnn = 1;
//Сnm = Сn - 1m + Сn - 1m - 1
#include <iostream>
#include <windows.h>
#include "check.h"
//#define TEST
int fact(int m, int f = 1);
float fC(int N, int M);

void main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int m, n;
	float C;
	string check;
	cout << "Введите M - \t\t\t";
	getline(cin, check);
	while (!isProved(check, 0, 2000000))
	{
		cls;
		cout << "Введите M - \t\t\t";
		getline(cin, check);
	}
	cls;
	m = stoi(check);
	cout << "Введите N(чтобы N >= M) - \t\t\t";
	getline(cin, check);
	while (!isProved(check, m, 2000000))
	{
		cls;
		cout << "Введите N(чтобы N >= M) - \t\t\t";
		getline(cin, check);
	}
	cls;
	n = stoi(check);
	cout << "M  = " << m << endl
		 << "N  = " << n << endl;

#if defined(TEST)
	cout << "Fact N = " << fact(n) << endl;
#endif

	if (m == 0 || m == n)
	{
		C = 1;
	}
	else
	{
		C = fC(n, m);
	}
	cout << "C = " << C << endl
		 << "Проверка по формуле: Cnm = " << fC(n - 1, m) + fC(n - 1, m - 1) << endl;
}

int fact(int n, int f)
{
	if (n - 1 == 0 || n <= 0)		return f;
	else 
	{
		f *= n * (n - 1);
		return fact(n - 2, f); 
	}
}

float fC(int n, int m)
{
	float C;
	return C = float(fact(n)) / (float((fact(m)) * float(fact(n - m))));
}