//������ ������ �, � ������ � ��������� ��� �������� ������� �, �������
//������ ������������� �������� � ������� �������� ������.������ � 
//������������� ��  �����������, ��������� ��������� ���������� : ����� - ���, ���������� �����.
#include <iostream>
#include "check.h"

void main()
{
	setlocale(LC_ALL, "ru");
	int n, nB = 0;
	string check;
	do {
		cout << "������� ������ �������: ";
		gl(check);
	} while (!isProved(check, 1, INT_MAX));
	n = stoi(check);
	int* A = new int[n];
	int* B = new int[n];
	int* C = new int[n];
	int max = -100;
	int max_index = -100;
	cout << "������ �: ";
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
	cout << "������ �: ";
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
	cout << "\n\n������ � ����� ���������� ���������: ";
	for (int i = 0; i < nB; i++)
	{
		cout << B[i] << ((i + 1 != nB) ? " " : "\n\n");
	}
	cout << "���������� ��������� ������ " << timeBubl << " �����������\n";
	cout << "���������� ������� ����� ������ " << timeHoar << " �����������\n";
}