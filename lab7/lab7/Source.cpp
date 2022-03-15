//��������� ������ ��������� ������� ����� clear(), ���������� � ���� � ���������� �� �����.
// 
//1) ����������� �������, ������� ��������� ���� Stack, ������� � ���� �� ������ ���� ��������,
//������� ������ � ���� Stack1, �� �� ������ � ���� Stack2.
//2) ����������� �������, ������� ������� �� ����� ������ ������������� �������, ���� ����� ����.
//3) ����������� �������, ������� ������� �� ����� ������ ������������� �������, ���� ����� ����.

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
		cout << "�������� ����� ����:\n"
			<< "1) �������� ������ � ������ ����!\n"
			<< "2) ���������� ������ ������� �����!\n"
			<< "3) �������� ������ �� ������ ����!\n"
			<< "4) ���������� ������ ������� �����!\n"
			<< "5) ���������, � ����� �������� ������ � �������� ����!\n"
			<< "6) ����� ��������� �����!\n"
			<< "7) �������� ����!\n"
			<< "8) ������� ������� �����!\n"
			<< "9) �����!\n"
			<< "�������:\t";
		getline(cin, check);

		while (!isProved(check, 1, 9))
		{ 
			cls;
			cout << "�������� ����� ����(�� 1 �� 8):\n"
				<< "1) �������� ������ � ������ ����!\n"
				<< "2) ���������� ������ ������� �����!\n"
				<< "3) �������� ������ �� ������ ����!\n"
				<< "4) ���������� ������ ������� �����!\n"
				<< "5) ���������, � ����� �������� ������ � �������� ����!\n"
				<< "6) ����� ��������� �����!\n"
				<< "7) �������� ����!\n"
				<< "8) ������� ������� �����!\n"
				<< "9) �����!\n"
				<< "�������:\t";
			getline(cin, check);
		}
		cls;
		switch (stoi(check))
		{
		case 1://add to first
		{
			cout << "������� ��������� ����� �������� � ����?" << "\t";
			getline(cin,check);
			while (!isProved(check, "0123456789"))
			{
				cls;
				cout << "������� ��������� ����� �������� � ����(�������� ������!)?\t";
				getline(cin, check);
			}
			pull(stack1, stoi(check));
			cls;
			cout << "������ ��������!" << endl;
			pause;
			break;
		}
		case 2:// output from stack1
		{
			if (stack1->head == stack1)
			{
				cout << "������ ���!\n";
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
			cout << "������� ��������� ����� �������� � ����?" << "\t";
			getline(cin, check);
			while (!isProved(check, "0123456789"))
			{
				cls;
				cout << "������� ��������� ����� �������� � ����(�������� ������!)?\t";
				getline(cin, check);
			}
			pull(stack2, stoi(check));
			cls;
			cout << "������ ��������!" << endl;
			pause;
			break;
		}
		case 4:// output from stack2
		{
			if (stack1->head == stack1)
			{
				cout << "������ ���!\n";
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
				cout << "� ������ ����� ��� ������!\n";
				pause;
				break;
			}
			if (stack2->head == stack2)
			{
				cout << "�� ������ ����� ��� ������!\n";
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
			cout << "������ ��������!" << endl;
			file.close();
			pause;
			break;
		}
		case 6: // out from main stack
		{
			if (stack->head == stack)
			{
				cout << "������ ���!\n";
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
			cout << "�������� �����:\n"
				<< "1) ������� ������ �������������!\n"
				<< "2) ������� ������ �������������!\n"
				<< "������� �����:\t";
			getline(cin, check);

			while (!isProved(check, 1, 2))
			{
				cls;
				cout << "�������� �����:\n"
					<< "1) ������� ������ �������������!\n"
					<< "2) ������� ������ �������������!\n"
					<< "������� �����(1 ��� 2):\t";
				getline(cin, check);
			}
			cls;
			if (check == "1")
			{
				pop(stack);
				cout << endl << "\n����� ��������:\n\n";
				int number = del(stack, false);
				if (number == 500000)
				{
					cout << "��� �������������!\n\n";
				}
				else cout << "������� " << number << " ������!\n\n";
			}
			else if (check == "2")
			{
				pop(stack);
				cout << endl << "\n����� ��������:\n\n";
				int number = del(stack, true);
				if (number == 500000)
				{
					cout << "��� �������������!\n\n";
				}
				else cout << "������� " << number << " ������!\n\n";
			}
			pop(stack);
			pause;
			break;
		}
		case 9: //exit
		{
			isExit = true;
			cout << "����!\n";
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
		return "������ �������!\n";
	else
	{
		stop = stack->head->next;
		delete stack->head;
		stack->head = stop;
		stack->end = stack->head;
		if (clear(stack) != "������ �������!\n")
			clear(stack);
		else
			return "������ �������!\n";
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