#define _CRT_SECURE_NO_WARNINGS  fopen

/*
1 LABA  ���� 4 � 2 ����� ����
2 ���� ����� ����
3 ���� ������ ������ ��������� 3 �����
4 ���� 1 �������� �  2 ���� �� 5
5 ���� �� ����� 3 ������� ��� ����
6 ���� �� ����� 3 ����
7 ���� 1 �� 5 , ��� ������, � ��� ���� �� 4
8 ���� 1 �� 5, ��� ������, � ���� �� 4 -��

*/

//���������� ����� f � ����� ����������� �����.�������� ���� g, ������������ ��
//f �������� - �� ������ ����� ������� ���������� �����, ��������� � ����������.
#include<iostream>
#include<stdio.h>
#include<cstdio>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void addTheDataFileB(int size, int* a);

int main()
{
	setlocale(LC_ALL, "ru");
	int l = 7;
	int* a = new int[l];
	FILE* FILEA;

	string num;
	cout << "������� �����: ";
	getline(cin, num);

	while (num > "99" || num < "10")
	{
		cout << "\n������� ����������� �����: ";
		getline(cin, num);
	}

	int enteredNum = stoi(num),
		number,
		size = 0;

	if ((FILEA = fopen("f.txt", "r")) != NULL)
	{
		for (int i = 0, j = 0; i < l; i++)
		{
			fscanf(FILEA, "%d", &number);

			if (number > enteredNum) 
			{
				a[j++] = number;
				cout << a[j - 1] << "\t";
			}

			size = j;
		}
		cout << endl << endl;

		addTheDataFileB(size, a);

		fclose(FILEA);
		
	}

}

void addTheDataFileB(int size, int* a)
{
	FILE* FILEB;
	if ((FILEB = fopen("g.txt", "w")) != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			fprintf(FILEB, "%d\t", a[i]);
		}
	}
}
