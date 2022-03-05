// Создать список, содержащий символы.Найти символ, равный введенному с клавиатуры, вывести его и следующий за ним символ.
#include <iostream>
#include <string>
#include "check.h"
#include <Windows.h>
#include <fstream>

#define cls system("cls")

using namespace std;

string path = "data.txt";
int cnt = 0;

struct Symbol
{
	char symb;
	Symbol* next;
} *list, * newNum;

void writeToFile(char);
void del();
void append(char);
void outList();
void research(char);
int sum();

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	string mNum;
	char symb;
	bool isExit = false;

	list = nullptr;
	fstream file;
	file.open(path, fstream::in);

	while (!file.eof())
	{
		newNum = new Symbol;
		getline(file, mNum);
		if (mNum == "")
			break;
		symb = mNum[0];
		newNum->symb = symb;
		newNum->next = list;
		list = newNum;
		cnt++;
	}
	file.close();


	while (!isExit)
	{
		cls;
		cout << "Выберите пункт:\n"
			<< "1) Добавить символ!\n"
			<< "2) Удалить элемент!\n"
			<< "3) Поиск элемента!\n"
			<< "4) Вывод всех элементов списка\n"
			<< "5) Выход\n"
			<< "Ввовите:   ";

		getline(cin, mNum);

		while (!isProved(mNum, 1, 5))
		{
			cls;
			cout << "Выберите пункт(1 - 5):\n"
				<< "1) Добавить целое число!\n"
				<< "2) Удалить элемент!\n"
				<< "3) Поиск элемента!\n"
				<< "4) Вывод всех элементов списка\n"
				<< "5) Выход\n"
				<< "Ввовите:   ";

			getline(cin, mNum);
		}
		cls;

		switch (stoi(mNum))
		{
		case 1: // add;
		{
			cout << "Введите cимвол:\t";
			getline(cin, mNum);

			while (mNum.size()!=1)
			{
				cls;
				cout << "Введите один символ:\t";
				getline(cin, mNum);
			}
			cls;

			append(mNum[0]);
			cout << "Элемент \"" << mNum << "\" добавлен!";
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
			cout << "Введите символ: ";
			getline(cin, mNum);

			while (mNum.size() != 1)
			{
				cls;
				cout << "Введите один символ для поиска: ";
				getline(cin, mNum);
			}
			cls;
			research(mNum[0]);

			cout << "\n\n\nДля продолжения нажмите любую клавишу!" << endl;
			cin.ignore();
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
			cin.ignore();
			break;
		}
		case 5: // exit
		{
			isExit = true;
			cout << "Пока!";
			break;
		}
		}
	}
	return 0;
}

void append(char symb)
{
	newNum = new Symbol;
	newNum->symb = symb;
	newNum->next = list;
	list = newNum;
	writeToFile(symb);
}
void outList()
{
	cout << "Элементы списка: \n";
	Symbol* startList = list;
	for (int i = 1; i <= cnt; i++)
	{
		cout << i << ") " << list->symb << endl;
		list = list->next;
	}
	list = startList;
}
void writeToFile(char symb)
{
	fstream file;
	file.open(path, fstream::out | fstream::app);
	file << symb << "\n";
	file.close();
}
void del()
{
	outList();
	Symbol* startList = list;
	string symb;
	cout << "\n\nВведите номер элемента, который хотите удалить: ";
	getline(cin, symb);
	while (!isProved(symb, 1, cnt))
	{
		cls;
		cout << "\n\nВведите номер элемента, который хотите удалить(от 1 до " << cnt << "): ";
		getline(cin, symb);
	}
	fstream file;
	file.open(path, fstream::out);
	file.close();
	for (int i = 1; i <= cnt - 1; i++)
	{
		if (i + 1 != stoi(symb))
		{
			writeToFile(list->symb);
			list = list->next;
		}
		else
		{
			if (list->next->next != nullptr)
			{
				list->next = list->next->next;
				list = list->next;
				writeToFile(list->symb);
			}
		}
	}
	list = startList;
	cnt--;
}
void research(char symb)
{
	Symbol* start = list;
	bool isNothing = true;
	for (int i = 1; i <= cnt; i++)
	{
		if (list->symb == symb)
		{
			cout << "Этот сивол есть в списке(" << symb << ") есть в списке, его номер = " << i << endl;
			isNothing = false;
			if (list->next != nullptr)
				cout << "Следующий за ним элемент: " << list->next->symb << endl << endl;
		}
		list = list->next;
	}
	if (isNothing)
		cout << "Такого символа нет!";
	list = start;
}
int sum()
{
	Symbol* Start = list;
	int sum = 0;
	bool isNum = false;
	for (int i = 1; i <= cnt; i++)
	{
		if (list->symb >= 10 && list->symb < 100)
		{
			isNum = true;
			sum += list->symb;
		}
		list = list->next;
	}
	list = Start;
	if (!isNum)
		return -1;
	else
		return sum;
}