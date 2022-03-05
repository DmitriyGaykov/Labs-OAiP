//������� �����.�.�.�., ��� �����(�������, �������� � �.�.), 
//����� �����, ����� �� �����, ���� ���������� ���������.����� �� ������ �����.

#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;
#include "check.h"

#define CNT_CLIENTS 30
#define cls system("cls") 

bool is_in_Obj(char*,struct Clients*, int, int);

enum TYPE
{
	URGENT = 1,
	PREFER,
	OTHERS
};

union maskClients
{
	char FIO[50],
		type[50],
		date[20],
		point[10];

	char sum[20],
		number[20];
} datas;

struct Clients
{
	char FIO[50],
		 date[20];

	TYPE type;

	int sum,
		number;

	void GetDatas()
	{
		cout << "��� �������:\t\t\t" << FIO
			<< "\n������� ����:\t\t\t" << number
			<< "\n���� ��������� �������:\t\t" << date
			<< "\n������:\t\t\t\t" << sum
			<< "\n��� �����:\t\t\t";
		   
		switch (type)
		{
		case URGENT:
			cout << "�������" << endl;
			break;
		case PREFER:
			cout << "��������" << endl;
			break;
		case OTHERS:
			cout << "������" << endl;
			break;
		}
	}

} clients[CNT_CLIENTS];

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool isExit = false;
	int iter = 0;

	while (!isExit)
	{
		cls;
		cout << "�������� ����� ����:\n"
			<< "1) �������� �������\n"
			<< "2) ���������� � �������\n"
			<< "3) ����� �� �������\n"
			<< "�������: ";

		cin.getline(datas.point, 10);

		while (!isProved(datas.point, 1, 3))
		{
			cls;
			cout << "�������� ����� ����:\n"
				<< "1) �������� �������\n"
				<< "2) ���������� � �������\n"
				<< "3) ����� �� �������\n"
				<< "������� ����� �� 1 �� 3: ";

			cin.getline(datas.point, 10);
		}

		cls;
		switch (atoi(datas.point))
		{
		case 1: // add
		{
			// FIO
			{
				cout << "������� ��� �������:\t\t\t";
				cin.getline(datas.FIO, 50);

				while (CountWord(datas.FIO) != 3)
				{
					cout << "������� ��� �������(3 �����):\t\t";
					cin.getline(datas.FIO, 50);
				}

				correctFIO(datas.FIO);
				assignStr(clients[iter].FIO, datas.FIO);

			} 
			cout << endl; cls;
			// Type
			cout << endl; cls;
			{
				cout << "������� ��� �����:\n"
					<< "1) �������\n"
					<< "2) ��������\n"
					<< "3) ������\n"
					<< "�������: ";

				cin.getline(datas.type, 40);

				while (!isProved(datas.type, 1, 3))
				{
					cout << "������� ��� �����:\n"
						<< "1) �������\n"
						<< "2) ��������\n"
						<< "3) ������\n"
						<< "������� ����� �� 1 �� 3: ";

					cin.getline(datas.type, 40);
				}

				switch (atoi(datas.type))
				{
				case 1:
					clients[iter].type = URGENT;
					break;
				case 2:
					clients[iter].type = PREFER;
					break;
				case 3:
					clients[iter].type = OTHERS;
					break;
				}
			} 
			// Number
			cout << endl; cls;
			{
				cout << "������� ����� �������� �����:\t";
				cin.getline(datas.number, 40);

				int j = 0;

				while (!isProved(datas.number) || strlen(datas.number) != 6 || is_in_Obj(datas.number, clients, j, iter))
				{
					cout << "������. ������� ����� �������� �����(6 ����):\t";
					cin.getline(datas.number, 40);
				}

				clients[iter].number = atoi(datas.number);

			}
			// SUMM
			cout << endl; cls;
			{
				cout << "������� ����� �� �����? \t";
				cin.getline(datas.sum, 20);

				while (!isProved(datas.sum, "0123456789"))
				{
					cout << "������� ����� �� �����? ������� �������:\t";
					cin.getline(datas.sum, 20);
				}

				clients[iter].sum = atoi(datas.sum);
			}
			// Date
			cout << endl; cls;
			{
				cout << "���� ����������:\t\t\t";
				cin.getline(datas.date, 20);

				while (!checkDate(datas.date))
				{
					cout << "���� ����������(��.��.����):\t\t\t";
					cin.getline(datas.date, 20);
				}

				assignStr(clients[iter++].date, datas.date);

			}
			// The end
			cls;

			cout << "�� �������� ������������: \n\n";
			clients[iter - 1].GetDatas();
			cout << "\n��� ����������� ������� ����� �������!";

			cin.ignore();
			break;
		}
		case 2: // info
		{
			if (iter == 0)
			{
				cout << "�������� �������!";
				break;
			}

			cout << "������� ����� �������� �����: ";
			cin.getline(datas.number, 40);

			while (!isProved(datas.number) || strlen(datas.number) != 6)
			{
				cls;
				cout << "������� ���������� ������(����� �������� �����, 6 ����): ";
				cin.getline(datas.number, 40);
			}

			int j = 0;

			if (is_in_Obj(datas.number, clients, j, iter))
			{
				
			}

			cout << "\n��� ����������� ������� ����� �������!";
			cin.ignore();
			break;
		}
		case 3: // exit
		{
			isExit = true;
			cout << "����!";
			break; 
		}
		}
	}

	return 0;
}

bool is_in_Obj(char* str,struct Clients* client, int i, int end)
{
	if (i == end)
	{
		return false;
	}

	if (atoi(str) == client[i++].number)
	{
		cout << "����� ��� ����������!\n";
		clients[i].GetDatas();
		return true;
	}

	is_in_Obj(str, client, i, end);
}