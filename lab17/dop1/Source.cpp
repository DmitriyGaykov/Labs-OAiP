//��� ������ ����� �����, ���������� ��������� �������� ���� ������ � ����������.
//����� ������������ ������� ������� � ��� �����, ��� �������, ��� ��� �������� 
//��������.����� ����������� ������� �������.
#include <iostream>
#include "check.h"

void main()
{
	setlocale(LC_ALL, "ru");
	int n, el;
	string check;
	do
	{
		cout << "������� N: ";
		gl(check);
	} while (!isProved(check, 1, INT_MAX));
	n = stoi(check);
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		el = rand() % 10001 - 5000;
		for (int j = i; j >= 0; j--)
		{
			if (el == arr[j] && i > 0)
			{
				i--;
				break;
			}
			if (j == 0)
			{
				arr[i] = el;
				cout << arr[i] << (i + 1 != n ? " " : "\n");
			}
		}
	}
	SortMethodHoar(arr, 0, n - 1);
	cout << "����������� �������: " << arr[0] << "\n";
}