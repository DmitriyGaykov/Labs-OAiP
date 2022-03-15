//Дополнить проект функциями очистки стека clear(), сохранения в файл и считывания из файла.
// 
//1) Разработать функцию, которая формирует стек Stack, включив в него по одному разу элементы,
//которые входят в стек Stack1, но не входят в стек Stack2.
//2) Разработать функцию, которая удаляет из стека первый отрицательный элемент, если такой есть.
//3) Разработать функцию, которая удаляет из стека первый положительная элемент, если такой есть.

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include "check.h"
#define cls system("cls")
#define pause system("pause")
#define MAX 40

using namespace std;

struct Stack
{
	int datas;
	Stack* next;
	Stack* head;
	Stack* end;
} *stack1, *stack2, *stack, *stop;

string check,
	   path = "datas.txt";

bool fstIsFull = false,
     secIsFull = false,
	 mainIsFull = false;

void pull(int num, struct Stack* stack);
void pull(struct Stack*, int, int i = 0);
void pop(struct Stack*, int i = 0);
bool isRepeat(struct Stack*, int num, int i = 0);
int del(struct Stack*, bool);
string clear(struct Stack*);

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	bool isExit = false;
	int num;

	stack1 = new Stack;
	stack2 = new Stack;
	stack = new Stack;

	stack1->head = stack1;
	stack2->head = stack2;
	stack->head = stack;
	
	fstream file;
	file.open(path, fstream::in);
	while (!file.eof())
	{
		getline(file, check);
		if (check == "")
			break;
		pull(stoi(check), stack);
	}
	file.close();

	while (!isExit)
	{
		cls;
		cout << "Выберите пункт меню:\n"
			<< "1) Записать данные в первый стек!\n"
			<< "2) Посмотреть данные первого стека!\n"
			<< "3) Записать данные во второй стек!\n"
			<< "4) Посмотреть данные второго стека!\n"
			<< "5) Проверить, а потом записать данные в основной стек!\n"
			<< "6) Вывод основного стека!\n"
			<< "7) Очистить стек!\n"
			<< "8) Удалить элемент стека!\n"
			<< "9) Выход!\n"
			<< "Вводите:\t";
		getline(cin, check);

		while (!isProved(check, 1, 9))
		{ 
			cls;
			cout << "Выберите пункт меню(ОТ 1 ДО 8):\n"
				<< "1) Записать данные в первый стек!\n"
				<< "2) Посмотреть данные первого стека!\n"
				<< "3) Записать данные во второй стек!\n"
				<< "4) Посмотреть данные второго стека!\n"
				<< "5) Проверить, а потом записать данные в основной стек!\n"
				<< "6) Вывод основного стека!\n"
				<< "7) Очистить стек!\n"
				<< "8) Удалить элемент стека!\n"
				<< "9) Выход!\n"
				<< "Вводите:\t";
			getline(cin, check);
		}
		cls;
		switch (stoi(check))
		{
		case 1://add to first
		{
			cout << "Сколько элементов будет записано в стек?" << "\t";
			getline(cin,check);
			while (!isProved(check, "0123456789"))
			{
				cls;
				cout << "Сколько элементов будет записано в стек(запишите числом!)?\t";
				getline(cin, check);
			}
			pull(stack1, stoi(check));
			cls;
			cout << "Данные записаны!" << endl;
			pause;
			break;
		}
		case 2:// output from stack1
		{
			if (stack1->head == stack1)
			{
				cout << "Данных нет!\n";
				pause;
				break;
			}
			pop(stack1);
			cout << "\n";
			pause;
			break;
		}
		case 3://add to sec
		{
			cout << "Сколько элементов будет записано в стек?" << "\t";
			getline(cin, check);
			while (!isProved(check, "0123456789"))
			{
				cls;
				cout << "Сколько элементов будет записано в стек(запишите числом!)?\t";
				getline(cin, check);
			}
			pull(stack2, stoi(check));
			cls;
			cout << "Данные записаны!" << endl;
			pause;
			break;
		}
		case 4:// output from stack2
		{
			if (stack1->head == stack1)
			{
				cout << "Данных нет!\n";
				pause;
				break;
			}
			pop(stack2);
			cout << endl;
			pause;
			break;
		}
		case 5: // add to main stack
		{
			if (stack1->head == stack1)
			{
				cout << "В первом стеке нет данных!\n";
				pause;
				break;
			}
			if (stack2->head == stack2)
			{
				cout << "Во втором стеке нет данных!\n";
				pause;
				break;
			}
			ofstream file;
			file.open(path, ofstream::app);
			while (stack1->head != stack1)
			{
				while (stack2->head != stack2)
				{
					if (stack1->head->datas != stack2->head->datas && !isRepeat(stack1, stack2->head->datas) && !isRepeat(stack2, stack1->head->datas))
					{
						pull(stack1->head->datas, stack);
						file << stack1->head->datas << "\n";
						break;
					}
					stack2->head = stack2->head->next;
				}
				stack2->head = stack2->end;
				stack1->head = stack1->head->next;
			}
			stack1->head = stack1->end;
			cout << "Данные записаны!" << endl;
			file.close();
			pause;
			break;
		}
		case 6: // out from main stack
		{
			if (stack->head == stack)
			{
				cout << "Данных нет!\n";
				pause;
				break;
			}
			pop(stack);
			cout << endl;
			pause;
			break;
		}
		case 7: // clear()
		{
			cout << clear(stack);
			pause;
			break;
		}
		case 8:// dell
		{
			cout << "Выберите пункт:\n"
				<< "1) Удалить первый отрицательный!\n"
				<< "2) Удалить первый положительный!\n"
				<< "Введите пункт:\t";
			getline(cin, check);

			while (!isProved(check, 1, 2))
			{
				cls;
				cout << "Выберите пункт:\n"
					<< "1) Удалить первый отрицательный!\n"
					<< "2) Удалить первый положительный!\n"
					<< "Введите пункт(1 или 2):\t";
				getline(cin, check);
			}
			cls;
			if (check == "1")
			{
				pop(stack);
				cout << endl << "\nПосле удаления:\n\n";
				int number = del(stack, false);
				if (number == 500000)
				{
					cout << "Нет отрицательных!\n\n";
				}
				else cout << "Элемент " << number << " удален!\n\n";
			}
			else if (check == "2")
			{
				pop(stack);
				cout << endl << "\nПосле удаления:\n\n";
				int number = del(stack, true);
				if (number == 500000)
				{
					cout << "Нет положительных!\n\n";
				}
				else cout << "Элемент " << number << " удален!\n\n";
			}
			pop(stack);
			pause;
			break;
		}
		case 9: //exit
		{
			isExit = true;
			cout << "Пока!\n";
			pause;
			break;
		}
		}


	}
	delete stack1;
	delete stack2;
	delete stack;
}

void pull(int num, struct Stack* stack)
{
	Stack* New = new Stack;
	New->datas = num;
	New->next = stack->head;
	stack->head = New;
	stack->end = stack->head;
}
void pull(struct Stack* stack, int cnt, int i)
{
	if (i < cnt)
	{
		Stack* add = new Stack;
		add->datas = rand() % 200 - 100;
		add->next = stack->head;
		stack->head = add;
		stack->end = stack->head;
		pull(stack, cnt, ++i);
	}
}
void pop(struct Stack* stack, int i)
{
	if (stack != stack->head)
	{
		cout << i + 1 << ") \t" << stack->head->datas << endl;
		stack->head = stack->head->next;
		pop(stack, ++i);
	}
	else
		stack->head = stack->end;
}
bool isRepeat(struct Stack* stack, int num, int i)
{
	if (i == 0)
	{
		stop = stack->head;
	}
	if (stack->head == stack)
	{
		stack->head = stop;
		return false;
	}

	stack->head = stack->head->next;

	if (stack->head != stack)
	{
		if (stack->head->datas == num)
		{
			stack->head = stop;
			return true;
		}
		else
			isRepeat(stack, num, ++i);
	}
	else
	{
		stack->head = stop;
		return false;
	}
}
string clear(struct Stack* stack)
{
	if (stack->head == stack)
		return "Данные удалены!\n";
	else
	{
		stop = stack->head->next;
		delete stack->head;
		stack->head = stop;
		stack->end = stack->head;
		if (clear(stack) != "Данные удалены!\n")
			clear(stack);
		else
			return "Данные удалены!\n";
	}

}	
int del(struct Stack* stack, bool isPos) 
{
	int num = 500000,
		i = 0;
	Stack* preData = stack->head;
	if (!isPos)
	{
		while (stack->head != stack)
		{
			if (stack->head->datas < 0)
			{
				num = stack->head->datas;
				stop = stack->head->next;
				delete stack->head;
				stack->head = stop;
				if (i == 0)
				{
					stack->end = stack->head;
				}
				if (i != 0)
				{
					preData->next = stack->head;
				}
				break;
			}
			if (i != 0)
			{
				preData = stack->head;
			}
			stack->head = stack->head->next;
			i++;
		}
	}
	else if (isPos)
	{
		while (stack->head != stack)
		{
			if (stack->head->datas > 0)
			{
				num = stack->head->datas;
				stop = stack->head->next;
				delete stack->head;
				stack->head = stop;
				if (i == 0)
				{
					stack->end = stack->head;
				}
				if (i != 0)
				{
					preData->next = stack->head;
				}
				break;
			}
			if (i != 0)
			{
				preData = stack->head;
			}
			i++;
			stack->head = stack->head->next;
		}
	}
	stack->head = stack->end;
	return num;
}