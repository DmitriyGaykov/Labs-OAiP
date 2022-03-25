//1) Создать очередь для символов и функции для ввода, вывода и определения размера очереди.
//Ввести символы с экрана в очередь.В случае совпадения вводимого символа с последним
//элементом оче - реди удалить первых три элемента.
// 
// Максимальный размер очереди ввести с клавиатуры.
// 
//2) Создать очередь для символов и функции для ввода, вывода и удаления элементов очереди.
//Ввести символы с клавиатуры в очередь.После введения 5го символа в ответ на каждый
//вводимый удалять по одному элементу из очереди.
// 
//3) Создать очередь для символов и функции для ввода, вывода, удаления и определения размера
//очереди. Ввести символы с экрана в очередь. В случае совпадения вводимого символа с первым
//элементом очереди вывести оче-редь и ее размер. 
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
void output(int  i = 1)
{
	symbs = symbs->next;
	cout << i++ << ") " << symbs->symb << ";\t";
	if (symbs->next != symbs->end)
		return output(i);
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
void del2()
{
	Char* temp;
	cnt--;
	symbs = symbs->next;
	temp = symbs->next;
	delete symbs;
	symbs = temp;
	start->next = symbs;
	symbs = start;
}
void del(int num)
{
	cnt--;
	Char* preEl = start;
	for (int i = 0; i < num; i++)
	{
		preEl = symbs;
		symbs = symbs->next;
	}
	symbs != symbs->end ? preEl->next = symbs->next : symbs->end = preEl;
	Char* temp = symbs->next;
	delete symbs;
	symbs = temp;
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
			<< "5. Delete elements!\n"
			<< "6. Exit!\n"
			<< "Enter menu point needed you: ";
		getline(cin, mN);
		
		while (!isProved(mN, 1, 6))
		{
			cls;
			cout << "1. Input symbol to queue\n"
				<< "2. Output queue\n"
				<< "3. Show queue size\n"
				<< "4. Enter element to delete 3 first elements!\n"
				<< "5. Delete elements!\n"
				<< "6. Exit!\n"
				<< "Enter menu point needed you: ";
			getline(cin, mN);
		}
		point = stoi(mN);
		
		cls;
		switch (point)
		{
		case 1: // input
		{
			if(cnt == 5)
				del2();
			else cnt++;

			if (cnt > MAX)
			{
				cout << "List is filled!" << endl;
				pause;
				break;
			}
			cout << "Enter a symbol: ";
			getline(cin, mStr);

			while (mStr.size() != 1 || mStr == "" || mStr== " " || mStr == " ")
			{
				cls;
				cout << "Enter one symbol(non-void): ";
				getline(cin, mStr);
			}
			cls;

			symb = mStr[0];
			input(symb);

			if (cnt > 1 && start->next->symb == mStr[0])
			{
				cout << "It was entered the symbol, that is first in queue!\n"
					<< "Queue size = " << cnt << endl;
				output();
				ent;
				pause;
			}
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
		case 5: // delete
		{
			if (cnt == 0)
			{
				cout << "Fill queue!" << endl;
				pause;
				break;
			}
			output();
			ent;
			ent;
			cout << "Choise the element point to delete its: ";
			getline(cin, mN);

			while (!isProved(mN, 1, cnt))
			{
				cls;
				cout << "Choise the element point to delete its(from 1 to " << cnt << "): ";
				getline(cin, mN);
			}

			del(stoi(mN));

			break;
		}
		case 6: // Exit
		{
			isExit = true;
			pause;
			break;
		}
		}
	}

	return 0;
}