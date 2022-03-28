#include <iostream>
#include <fstream>
#include "check.h"
//deleteEvery�(int m) � ������� �������� ������� � - ��� �������� ������.
//addXBegin (int x) � ������� ���������� �������� x � ������ ������.
//returnN � ������� ����������� ��������� ��������, ���� ������ ���� � ����������� ������� � ��������� ������.
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

struct Address
{
	char name[NAME_SIZE] = "";
	char city[CITY_SIZE] = "";
	Address* next;
	Address* prev;
} *head, *last;
//-----------------------------------------------------------
int menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1. ���� �����" << endl;
	cout << "2. �������� ������� � - ��� �������� ������" << endl;
	cout << "3. ����� �� �����" << endl;
	cout << "4. �����" << endl;
	cout << "5. ���������� �������� � ������ ������" << endl;
	cout << "6. �����" << endl;
	cout << endl;
	do
	{
		cout << "��� �����: ";
		cin.sync();
		gets_s(s);
		cout << endl;
		c = atoi(s);
	} while (c < 0 || c > 6);
	return c;
}
//-----------------------------------------------------------
void insert(Address* e, Address** phead, Address** plast) //���������� � ����� ������
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
//-----------------------------------------------------------
Address* setElement()      // �������� �������� � ���� ��� �������� � ���������� 
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "������ ��������� ������ ������";
		return NULL;
	}
	cout << "������� ���: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "������� �����: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(Address* phead, Address* plast)      //����� ������ �� �����
{
	Address* t = phead;
	if (t == NULL)
		return;
	while (t)
	{
		cout << t->name << ' ' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], Address** phead)    // ����� ����� � ������
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "��� �� �������" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}
//-----------------------------------------------------------
//void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // �������� ����� {	struct Address *t = *phead;	
//{
//	while (t)
//	{
//		if (!strcmp(name, t->name))  break;
//		t = t->next;
//	}
//	if (!t)
//		cerr << "��� �� �������" << endl;
//	else
//	{
//		if (*phead == t)
//		{
//			*phead = t->next;
//			if (*phead)
//				(*phead)->prev = NULL;
//			else
//				*plast = NULL;
//		}
//		else
//		{
//			t->prev->next = t->next;
//			if (t != *plast)
//				t->next->prev = t->prev;
//			else
//				*plast = t->prev;
//		}
//		delete t;
//		cout << "������� ������" << endl;
//	}
//}
//-----------------------------------------------------------
Address* del_M_elms(int M, Address* last);
void addXBegin(Address* x);
bool returnN();
int main(void)
{
	head = NULL;
	last = NULL;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2: {
			if (returnN())
			{
				cout << "������ ����!" << endl;
				break;
			}
			string M;
			cout << "������� M: ";
			getline(cin, M);

			while (!isProved(M, 1, 1000))
			{
				cout << "������� M(�� 1 �� 1000): ";
				getline(cin, M);
			}

			last = del_M_elms(stoi(M), last);
			//delet(dname, &head, &last);
		}
			  break;
		case 3:  
			if (returnN())
			{
				cout << "������ ����!" << endl;
				break;
			}
			outputList(head, last);
			break;
		case 4: {
			if (returnN())
			{
				cout << "������ ����!" << endl;
				break;
			}
			char fname[NAME_SIZE];
			cout << "������� ���: ";
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			find(fname, &head);
		}
			  break;
		case 5: // add to begin
		{
			cout << "���������� �������� � ������ ������:\n\n";
			addXBegin(setElement());
			break;
		}
		case 6:  exit(0);
		default: exit(1);
		}
	}
	return 0;
}

Address* del_M_elms(int M, Address* last)
{
	int cnt = 1;
	Address* temp, * st = head;
	while (head != NULL)
	{
		if (cnt++ % M == 0)
		{
			if (head->next == NULL && head->prev != NULL)
			{
				head->prev->next = NULL;
				last = head->prev;
				delete head;
				head = last;
				break;
			}
			else if (head->prev == NULL && head->next != NULL)
			{
				head->next->prev = NULL;
				st = head->next;
				temp = head->next;
				delete head;
				head = temp;
				continue;
			}
			else if (head->prev == NULL && head->next == NULL)
			{
				delete head;
				head = NULL;
				last = NULL;
				head = NULL;
				st = NULL;
			}
			else
			{
				head->prev->next = head->next;
				temp = head->next;
				delete head;
				head = temp;
				continue;
			}
		}
		else head = head->next;
	}
	head = st;
	return last;
}
void addXBegin(Address* x)
{
	if (head)
	{
		head->prev = x;
		x->next = head;
		x->prev = NULL;
		head = x;
	}
	else
	{
		head = x;
		last = x;
		x->prev = NULL;
		x->next = NULL;
	}
}
bool returnN()
{
	bool isClear;
	head == NULL ? isClear = true : isClear = false;
	return isClear;
}