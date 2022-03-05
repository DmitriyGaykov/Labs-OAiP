//Клиенты банка.Ф.И.О., тип счета(срочный, льготный и т.д.), 
//номер счета, сумма на счете, дата последнего изменения.Выбор по номеру счета.

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
		cout << "ФИО клиента:\t\t\t" << FIO
			<< "\nЛицевой счет:\t\t\t" << number
			<< "\nДата последних измений:\t\t" << date
			<< "\nБаланс:\t\t\t\t" << sum
			<< "\nТип счета:\t\t\t";
		   
		switch (type)
		{
		case URGENT:
			cout << "Срочный" << endl;
			break;
		case PREFER:
			cout << "Льготный" << endl;
			break;
		case OTHERS:
			cout << "Другое" << endl;
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
		cout << "Выберите пункт меню:\n"
			<< "1) Добавить клиента\n"
			<< "2) Информация о клиенте\n"
			<< "3) Выход из системы\n"
			<< "Вводите: ";

		cin.getline(datas.point, 10);

		while (!isProved(datas.point, 1, 3))
		{
			cls;
			cout << "Выберите пункт меню:\n"
				<< "1) Добавить клиента\n"
				<< "2) Информация о клиенте\n"
				<< "3) Выход из системы\n"
				<< "Введите пункт от 1 до 3: ";

			cin.getline(datas.point, 10);
		}

		cls;
		switch (atoi(datas.point))
		{
		case 1: // add
		{
			// FIO
			{
				cout << "Введите ФИО клиента:\t\t\t";
				cin.getline(datas.FIO, 50);

				while (CountWord(datas.FIO) != 3)
				{
					cout << "Введите ФИО клиента(3 слова):\t\t";
					cin.getline(datas.FIO, 50);
				}

				correctFIO(datas.FIO);
				assignStr(clients[iter].FIO, datas.FIO);

			} 
			cout << endl; cls;
			// Type
			cout << endl; cls;
			{
				cout << "Введите тип счета:\n"
					<< "1) Срочный\n"
					<< "2) Льготный\n"
					<< "3) Другое\n"
					<< "Вводите: ";

				cin.getline(datas.type, 40);

				while (!isProved(datas.type, 1, 3))
				{
					cout << "Введите тип счета:\n"
						<< "1) Срочный\n"
						<< "2) Льготный\n"
						<< "3) Другое\n"
						<< "Введите пункт от 1 до 3: ";

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
				cout << "Введите номер лицевого счета:\t";
				cin.getline(datas.number, 40);

				int j = 0;

				while (!isProved(datas.number) || strlen(datas.number) != 6 || is_in_Obj(datas.number, clients, j, iter))
				{
					cout << "Ошибка. Введите номер лицевого счета(6 цифр):\t";
					cin.getline(datas.number, 40);
				}

				clients[iter].number = atoi(datas.number);

			}
			// SUMM
			cout << endl; cls;
			{
				cout << "Сколько денег на счету? \t";
				cin.getline(datas.sum, 20);

				while (!isProved(datas.sum, "0123456789"))
				{
					cout << "Сколько денег на счету? Введите цифрами:\t";
					cin.getline(datas.sum, 20);
				}

				clients[iter].sum = atoi(datas.sum);
			}
			// Date
			cout << endl; cls;
			{
				cout << "Дата заполнения:\t\t\t";
				cin.getline(datas.date, 20);

				while (!checkDate(datas.date))
				{
					cout << "Дата заполнения(ДД.ММ.ГГГГ):\t\t\t";
					cin.getline(datas.date, 20);
				}

				assignStr(clients[iter++].date, datas.date);

			}
			// The end
			cls;

			cout << "Вы добавили пользователя: \n\n";
			clients[iter - 1].GetDatas();
			cout << "\nДля продолжения нажмите любую клавишу!";

			cin.ignore();
			break;
		}
		case 2: // info
		{
			if (iter == 0)
			{
				cout << "Добавьте клиента!";
				break;
			}

			cout << "Введите номер лицевого счета: ";
			cin.getline(datas.number, 40);

			while (!isProved(datas.number) || strlen(datas.number) != 6)
			{
				cls;
				cout << "Введите корректные данные(номер лицевого счета, 6 цифр): ";
				cin.getline(datas.number, 40);
			}

			int j = 0;

			if (is_in_Obj(datas.number, clients, j, iter))
			{
				
			}

			cout << "\nДля продолжения нажмите любую клавишу!";
			cin.ignore();
			break;
		}
		case 3: // exit
		{
			isExit = true;
			cout << "Пока!";
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
		cout << "Номер уже существует!\n";
		clients[i].GetDatas();
		return true;
	}

	is_in_Obj(str, client, i, end);
}