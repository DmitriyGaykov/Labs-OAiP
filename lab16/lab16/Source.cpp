//������ ������ �, � ������ � ����������� ��� �������� ������� �, 
//������� ������ ������.������ � ������������� �� ��������, 
//��������� ��������� ���������� : ��������, ���������� ������� ��������.
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
		cout << "������� N: ";
		gl(check);
	} while (!isProved(check, 1, INT_MAX));
	N = stoi(check);
	A = new int[N];
	B = new int[N / 2 + 1];
	C = new int[N / 2 + 1];
	cout << "������ �: ";
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

	cout << "������ �: ";
	for (int i = 0; i < nB; i++)
	{
		cout << B[i] << ((i + 1) != nB ? " " : "\n");
	}
	cout << "����� ���������� ���������: " << timeBubl << " ��\n";
	cout << "����� ���������� ������� ��������: " << timeInst << " ��\n";

	delete[] A;
	delete[] B;
	delete[] C;
}