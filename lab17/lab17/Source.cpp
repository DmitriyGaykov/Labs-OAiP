//���������� ������� ������� �������, ���������� �����, ������������� ����������
#include <iostream>
#include "check.h"

void main()
{
	setlocale(LC_ALL, "ru");
	int n;
	string check;
	do {
		cout << "������� N: ";
		gl(check);
	} while (!isProved(check, 1, INT_MAX));
	n = stoi(check);
	int* A = new int[n];
	int* B = new int[n];
	int* C = new int[n];

	cout << "������: ";
	for (int i = 0; i < n; i++)
	{
		A[i] = B[i] = C[i] = rand() % 201 - 100;
		// cout << A[i] << ((i + 1 != n) ? " " : "\n");
	}
	int timeS, timeH, timeP;
	int start;
	int end;
	start = clock();
	sortMethodShella(A, n);
	end = clock();
	timeS = end - start;
	start = clock();
	SortMethodHoar(B, 0, n - 1);
	end = clock();
	timeH = end - start;
	start = clock();
	sortMethodPyram(C, n);
	end = clock();
	timeP = end - start;
	cout << "����� ����������: \n";
	/*for (int i = 0; i < n; i++)
	{
		cout << C[i] << ((i + 1 != n) ? " " : "\n");
	}*/
	cout << "����� ���������� �� ������ ������ �������: " << timeS << " ��" << endl;
	cout << "����� ���������� �� ������ �����: " << timeH << " ��" << endl;
	cout << "����� ���������� �� ������ �������������: " << timeP << " ��" << endl;
}