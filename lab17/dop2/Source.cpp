//��� ������ �� 10 ���������.������ 4 �������� ����������� �� �����������, ��������� 4 �� ��������.
#include <iostream>
#include "check.h"

void main()
{
	setlocale(LC_ALL, "ru");
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << ((i + 1 != 10) ? "  " : "\n\n");
	}
	quickSort(a, 6, 9);
	SortMethodHoar(a, 0, 3);
	for (int i : a)
	{
		cout << i << "  ";
	}
}