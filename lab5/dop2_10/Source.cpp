//���������.�.�.�., ���� ��������, �����, ���(�, �).����������� ������� �� ���� ��������.
#include <iostream>
#include <windows.h>
#include <string>
#include "check.h"
using namespace std;
#define COUNTCITIZENS 30
#define cls system("cls")

enum Sex
{
	MALE = 1,
	WOMAN
};

union maskCitizen
{
	char FIO[50],
		 date[20],
		 point[20];

} datas;

struct Citizen
{
	char FIO[50],
		 date[20];

	Sex sex;

	void GetInfo()
	{
		cout << "FIO:\t\t" << FIO
			<< "\nBorn day:\t" << date
			<<"\nSex:\t\t";

		switch (sex)
		{
		case MALE:
			cout << "Male\n";
			break;
		case WOMAN:
			cout << "Woman\n";
			break;
		}
	}
} citizen, citizens[COUNTCITIZENS];

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	bool isExit = false;
	short iter = 0;

	while (!isExit)
	{
		cls;
		cout << "�������� ����� ����:\n"
			<< "1) �������� ������\n"
			<< "2) ����� ������ �� ���� ��������\n"
			<< "3) �����\n"
			<<"�������:\t";

		cin.getline(datas.point, 20);

		while (!isProved(datas.point, 1, 3))
		{
			cls;
			cout << "������. �������� ����� ���� �� 1 �� 3:\n"
				<< "1) �������� ������\n"
				<< "2) ����� ������ �� ���� ��������\n"
				<< "3) �����\n"
				<< "�������:\t";

			cin.getline(datas.point, 20);
		}

		cls;

		switch (atoi(datas.point))
		{
		case 1: // add
		{
			cout << "������� ���� ���:\t\t";
			cin.getline(datas.FIO, 50);

			while (CountWord(datas.FIO) != 3)
			{
				cls;
				cout << "������� ���� ���(3 �����):\t\t";
				cin.getline(datas.FIO, 50);
			}

			correctFIO(datas.FIO);
			assignStr(citizens[iter].FIO, datas.FIO);
			cls;

			cout << "������� ���� ��������:\t\t";
			cin.getline(datas.date, 20);

			while (!isProved(datas.date, "0123456789.") || !checkDate(datas.date))
			{
				cls;
				cout << "������� ���� ��������(������: ��.��.����):\t\t";
				cin.getline(datas.date, 20);
			}

			assignStr(citizens[iter].date, datas.date);
			cls;

			cout << "�� ������ ����?\n1) �������\n2) �������\n�������:\t\t";
			cin.getline(datas.point, 10);

			while (!isProved(datas.point, 1, 2))
			{
				cls;
				cout << "������. �� ������ ����?\n1) �������\n2) �������\n������� �� 1 �� 2:\t\t";
				cin.getline(datas.point, 10);
			}
			cls;

			switch (atoi(datas.point))
			{
			case 1:
				citizens[iter].sex = MALE;
				break;
			case 2:
				citizens[iter].sex = WOMAN;
				break;
			}

			cout << "�� �������� ��������:\n\n";
			citizens[iter++].GetInfo();
			cout << "\n��� ����������� ������� ����� ������!";
			cin.ignore();
			break;
		}
		case 2: // Research
		{
			if (iter == 0)
			{
				cout << "�������� ����������!";
				break;
			}

			cout << "������� ���� ��������:\t";
			cin.getline(datas.date, 20);

			while (!isProved(datas.date, "0123456789.") || !checkDate(datas.date))
			{
				cls;
				cout << "������� ���� ��������(������: ��.��.����):\t";
				cin.getline(datas.date, 20);
			}

			cls;
			bool isFound = false;
			for (int i = 0; i < iter; i++)
			{
				if (strcmp(datas.date, citizens[i].date) == 0)
				{
					citizens[i].GetInfo();
					isFound = true;
				}
			}

			if (!isFound)
				cout << "� ���� ������ �������� ���!";

			cout << "\n��� ����������� ������� ����� ������!";
			cin.ignore();

			break;
		}
		case 3: // Exit
		{
			isExit = true;
			cout << "����!";
			break;
		}
		}
	}
	return 0;
}