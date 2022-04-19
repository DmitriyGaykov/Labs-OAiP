#include <iostream>
#include "check.h"

//������ ������ �, � ������ � ��������� ��� �������� ������� �, ������� ������ ������,
//������ �� ���� - ��� ����������� �������� � �������� ���������.������ � �������������
//�� �����������, ��������� ���� - ����� ���������� : ���������� �������, ���������� �����.

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
	cout << "������ �: ";
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 50 - 25;
		cout << A[i] << ((i + 1 != n) ? "  " : "\n");
	}
	cout << "������ �: ";
	for (int i = 0; i < n - 1; i += 2)
	{
		if (A[i + 1] % 2 != 0)
		{
			B[nB++] = A[i];
			C[nB - 1] = A[i];
			cout << B[nB - 1] << ((i + 2 != n) ? "  " : "\n");
		}
	}
	int timeSel, timeHoar;
	int start;
	int end;
	start = clock();
	sortMethodSelection(B, nB);
	end = clock();
	timeSel = end - start;
	start = clock();
	SortMethodHoar(C, 0, nB - 1);
	end = clock();
	timeHoar = end - start;
	cout << "\n\n������ � ����� ���������� �������: ";
	for (int i = 0; i < nB; i++)
	{
		cout << C[i] << ((i + 1 != nB) ? "  " : "\n");
	}
	cout << "����� ������� ����� " << timeSel << " �����������\n";
	cout << "����� ����� ����� " << timeHoar << " �����������\n";
}