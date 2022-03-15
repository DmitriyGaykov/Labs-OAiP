#include <iostream>
#include <string>
#include "check.h"
#include <Windows.h>
#include <fstream>

#define cls system("cls")

using namespace std;
//Создать список, содержащий элементы целого типа.Найти сумму положительных двухзначных
//элементов или выдать сообщение, что таких элементов нет.

string path = "data.txt";
int cnt = 0;

struct Integer
{
	int num;
	Integer* next;
} *list, *newNum;

void writeToFile(int);
void del();
void append(int);
void outList();
void research(int);
int sum();

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	string mNum;
	int num;
	bool isExit = false;

	list = nullptr;
	fstream file;
	file.open(path, fstream::in);

	while (!file.eof())
	{
		newNum = new Integer;
		getline(file, mNum);
		if (mNum == "")
			break;
		num = stoi(mNum);
		newNum->num = num;
		newNum->next = list;
		list = newNum;
		cnt++;
	}
	file.close();


	while (!isExit)
	{
		cls;
		cout << "Выберите пункт:\n"
			<< "1) Добавить целое число!\n"
			<< "2) Удалить элемент!\n"
			<< "3) Поиск элемента!\n"
			<< "4) Вывод всех элементов списка\n"
			<< "5) Найти сумму положительных двухзначных чисел в списке\n"
			<< "6) Выход\n"
			<< "Ввовите:   ";

		getline(cin, mNum);

		while (!isProved(mNum, 1, 6))
		{
			cls;
			cout << "Выберите пункт(1 - 6):\n"
				<< "1) Добавить целое число!\n"
				<< "2) Удалить элемент!\n"
				<< "3) Поиск элемента!\n"
				<< "4) Вывод всех элементов списка\n"
				<< "5) Найти сумму положительных двухзначных чисел в списке\n"
				<< "6) Выход\n"
				<< "Ввовите:   ";

			getline(cin, mNum);
		}
		cls;

		switch (stoi(mNum))
		{
		case 1: // add;
		{
			cout << "Введите число:\t";
			getline(cin, mNum);

			while (!isProved(mNum, -200000, 200000))
			{
				cls;
				cout << "Введите число(от -200000 до 200000):\t";
				getline(cin, mNum);
			}
			cls; 

			append(stoi(mNum));
			cout << "Элемент " << mNum << " добавлен!";
			cnt++;
			Sleep(500);
			break;
		}
		case 2: // del
		{
			if (cnt == 0)
			{
				cout << "В списке нет данных!";
				Sleep(700);
				break;
			}
			del();
			break;
		}
		case 3: // research
		{
			if (cnt == 0)
			{
				cout << "В списке нет данных!";
				Sleep(700);
				break;
			}
			cout << "Введите число для поиска: ";
			getline(cin, mNum);

			while (!isProved(mNum))
			{
				cls;
				cout << "Введите ЧИСЛО для поиска: ";
				getline(cin, mNum);
			}
			cls;
			research(stoi(mNum));
			system("pause");
			break;
		}
		case 4: // output
		{
			if (cnt == 0)
			{
				cout << "В списке нет данных!";
				Sleep(700);
				break;
			}
			outList();
			cout << "\n\nДля продолжения нажмите любую клавишу!";
			system("pause");
			break;
		}
		case 5: // summ
		{
			if (cnt == 0)
			{
				cout << "В списке нет чисел!";
				Sleep(1000);
				break;
			}
			if (sum() == -1)
			{
				cout << "Таких чисел нет!";
				Sleep(1000);
				break;
			}
			cout << "Сумма равна = " << sum();
			cout << "\n\nДля продолжения нажмите любую клавишу!";
			system("pause");
			break;
		}
		case 6: // exit
		{
			isExit = true;
			cout << "Пока!";
			break;
		}
		}
	}
	return 0;
}

void append(int num)
{
	newNum = new Integer;
	newNum->num = num;
	newNum->next = list;
	list = newNum;
	writeToFile(num);
}
void outList()
{
	cout << "Элементы списка: \n";
	Integer* startList = list;
	for (int i = 1; i <= cnt; i++)
	{
		cout << i << ") " << list->num << endl;
		list = list->next;
	}
	list = startList;
}
void writeToFile(int num)
{
	fstream file;
	file.open(path, fstream::out | fstream::app);
	file << num << "\n";
	file.close();
}
void del()
{
	outList();
	Integer* startList = list;
	string num;
	cout << "\n\nВведите номер элемента, который хотите удалить: ";
	getline(cin, num);
	while (!isProved(num, 1, cnt))
	{
		cls;
		cout << "\n\nВведите номер элемента, который хотите удалить(от 1 до " << cnt << "): ";
		getline(cin, num);
	}
	fstream file;
	file.open(path, fstream::out);
	file.close();
	for (int i = 1; i <= cnt - 1; i++)
	{
		if (i + 1 != stoi(num))
		{
			writeToFile(list->num);
			list = list->next;
		}
		else
		{
			if (list->next->next != nullptr)
			{
				list->next = list->next->next; 
				list = list->next;
				writeToFile(list->num);
			}
		}
	}
	list = startList;
	cnt--;
}
void research(int num)
{
	Integer* start = list;
	bool isThere = false;
	for (int i = 1; i <= cnt; i++)
	{
		if (list->num == num)
		{
			cout << "Это число(" << num << ") есть в списке, его номер = " << i << endl << endl;
			isThere = true;
		}
		list = list->next;
	}
	list = start;
	if (!isThere)
		cout << "Этого числа нет в списке!" << endl << endl;
}
int sum()
{
	Integer* Start = list;
	int sum = 0;
	bool isNum = false;
	for (int i = 1; i <= cnt; i++)
	{
		if (list->num >= 10 && list->num < 100)
		{
			isNum = true;
			sum += list->num;
		}
		list = list->next;
	}
	list = Start;
	if (!isNum)
		return -1;
	else
		return sum;
}