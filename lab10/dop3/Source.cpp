// sqrt(1 + (n + 1) * sqrt(1 + (n + 2) * sqrt(1 + (n + n)*sqrt))))
#include <iostream>
#include "check.h"

float f(int n, float F = 1.0);
unsigned int n;

void main()
{
	setlocale(LC_ALL, "ru");
	float y;
	string check;
	cout << "������� N: ";
	gl(check);
	while (!isProved(check, 1, 2000000))
	{
		cls;
		cout << "������� N(1 - 2.000.000): ";
		gl(check);
	}
	cls;
	n = stoi(check);
	cout << "������� ����� = " << f(n) << endl;
}

float f(int N, float F)
{
	if (N == 0)
	{
		return F;
	}
	else
	{
		F = sqrt(1 + (n + N) * F);
		return f(N - 1, F);
	}
}

