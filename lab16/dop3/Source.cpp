//������ ������ �.� ������ � ����������� �������� ������� �, ������� ������ ������.
//������ � ������������� �� �����������, ��������� ��������� ���������� : ��������,
//���������� �������.

#include <iostream>
#include "check.h"

void main()
{
	setlocale(LC_ALL, "ru");
	int n, nB = 0;
	string check;
	do
	{
		cout << "������� N: ";
		gl(check);
	} while (!isProved(check, 1, INT_MAX));
	n = stoi(check);
	int* A = new int[n];
	int* B = new int[n];
	int* C = new int[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 101 - 50;
		if (i % 2 == 0)
		{
			C[nB] = B[nB] = A[i];
			nB++;
		}
		cout << A[i] << ((i + 1 != n) ? " " : "\n");
	}
	cout << "\n������ �:\n";
	for (int i = 0; i < nB; i++)
	{
		cout << B[i] << ((i + 1 != nB) ? " " : "\n");
	}
	int timeBubl, timeSel;
	int start;
	int end;
	start = clock();
	sortMethodPuz(B, nB);
	end = clock();
	timeBubl = end - start;
	start = clock();
	sortMethodSelection(C, nB);
	end = clock();
	timeSel = end - start;
	cout << "\n������ � ��������������� �� �����������:\n";
	for (int i = 0; i < nB; i++)
	{
		cout << C[i] << ((i + 1 != nB) ? " " : "\n");
	}
	cout << "\n����� ���������� ���������: " << timeBubl << " ��\n";
	cout << "����� ���������� �������: " << timeSel << " ��\n";
}