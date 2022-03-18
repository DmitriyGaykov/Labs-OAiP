//Создать очередь для символов и функции для ввода, вывода и определения размера очереди.
//Ввести символы с экрана в очередь.В случае совпадения вводимого символа с последним
//элементом оче - реди удалить первых три элемента.
// Максимальный размер очереди ввести с клавиатуры.
#include <iostream>
#include <windows.h>
#include "check.h"

struct Char
{
	char symb;
	Char* next;
	Char* end;
} *symbs, *newSymb, *start;

int cnt = 0;
int MAX;

void input(char s)
{
	newSymb = new Char;
	symbs->end->next = newSymb;
	newSymb->symb = s;
	symbs->end = newSymb;
	symbs = start;
}
void output()
{
	symbs = symbs->next;
	cout << symbs->symb << ";\t";
	if (symbs->next != symbs->end)
		return output();
	symbs = start;
}
bool research(char s)
{
	while (symbs != symbs->end)
	{
		symbs = symbs->next;
		if (symbs->symb == s)
		{
			symbs = start;
			return true;
		}
	}
	symbs = start;
	return false;
}
void del()
{
	Char* temp;
	symbs = symbs->next;
	for (int i = 1; i <= 3; i++)
	{
		cnt--;
		if (symbs->next == symbs->end)
		{
			delete symbs;
			symbs = start;
			symbs->end = start;
			break;
		}
		temp = symbs->next;
		delete symbs;
		symbs = temp;
		start->next = symbs;
	}
	symbs = start;
}

int main()
{
	ru;
	string mN,
		   mStr;
	int point;
	char symb;
	bool isExit = false;
	symbs = new Char;
	start = symbs;
	symbs->end = symbs;

	cout << "Enter max size of queue: ";
	getline(cin, mN);

	while (!isProved(mN, 1, 2000000))
	{
		cls;
		cout << "Enter max size of queue(number from 0 to 20000000): ";
		getline(cin, mN);
	}
	cls;
	MAX = stoi(mN);

	while (!isExit)
	{
		cls;
		cout << "1. Input symbol to queue\n"
			<< "2. Output queue\n"
			<< "3. Show queue size\n"
			<< "4. Enter element to delete 3 first elements!\n"
			<< "5. Exit!\n"
			<< "Enter menu point needed you: ";
		getline(cin, mN);
		
		while (!isProved(mN, 1, 5))
		{
			cls;
			cout << "1. Input symbol to queue\n"
				<< "2. Output queue\n"
				<< "3. Show queue size\n"
				<< "4. Enter element to delete 3 first elements!\n"
				<< "5. Exit!\n"
				<< "Enter menu point needed you: ";
			getline(cin, mN);
		}
		point = stoi(mN);
		
		cls;
		switch (point)
		{
		case 1: // input
		{

			cnt++;
			if (cnt > MAX)
			{
				cout << "List is filled!" << endl;
				pause;
				break;
			}
			cout << "Enter a symbol: ";
			getline(cin, mStr);

			while (mStr.size() != 1 || mStr == "" || mStr== " ")
			{
				cls;
				cout << "Enter one symbol(non-void): ";
				getline(cin, mStr);
			}
			cls;

			symb = mStr[0];
			input(symb);
			break;
		}
		case 2: // output
		{
			if (cnt == 0)
			{
				cout << "List is clear!" << endl;
				pause;
				break;
			}
			output();
			ent;
			pause;
			break;
		}
		case 3: // Snow list size
		{
			cout << "Size list = " << cnt << " elements" << endl;
			pause;
			break;
		}
		case 4: // res + del
		{
			if (cnt == 0)
			{
				cout << "List is clear!" << endl;
				pause;
				break;
			}
			cout << "Enter element: ";
			getline(cin, mStr);
			while (mStr.size() != 1 || mStr == "")
			{
				cls;
				cout << "Enter one element: ";
				getline(cin, mStr);
			}
			cls;
			if (research(mStr[0]))
				del();
			
			pause;
			break;
		}
		case 5: // Exit
		{
			isExit = true;
			pause;
			break;
		}
		}
	}

	return 0;
}