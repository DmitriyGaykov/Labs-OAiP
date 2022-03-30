#include <iostream>
#include "check.h"

//��������� ��������� � ������ �����, ��������� ��������.
//y = sin(x) + sin(2x) + sin(3x) + ... + sin(nx);
int x;
float sinus(int n, float y = 0.0, int i = 1);

void main()
{
	setlocale(LC_ALL, "ru");
	string check;
	int n,
		y;
	cout << "������� N - ";
	gl(check);
	while (!isProved(check, 1, 2000000))
	{
		cls;
		cout << "������� N(�� 1 �� 2000000) - ";
		gl(check);
	}
	cls;
	n = stoi(check);
	cout << "������� X - ";
	gl(check);
	while (!isProved(check, -2000000, 2000000))
	{
		cls;
		cout << "������� X(�� -2000000 �� 2000000) - ";
		gl(check);
	}
	x = stoi(check);
	cout << "\x1B[32m"  << sinus(n) << "\033[0m" << endl;
}

float sinus(int n, float y, int i)
{
	if (n == 0) return y;
	else
	{
		cout << "sin(" << n << " * " << x << ")";
		(n - 1) == 0 ? cout << " = " : cout << " + ";
		if (i % 6 == 0) ent;
		y += sin(n * x);
		return sinus(n - 1, y, ++i);
	}
}