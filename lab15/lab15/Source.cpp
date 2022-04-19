//����� - ����.������� ��� - ������� �� ���������� ������ :
//��������� ������, �������� ������.���� � ��������� ������.

#include <iostream>
#include "check.h"
using namespace std;

struct HT
{
	struct List
	{
		int cost = INT_MAX;
		string name;
		List* next = nullptr;
		List* end = nullptr;

		void pull(string name, int cost)
		{
			List* t = new List;
			t->cost = cost;
			t->name = name;
			t->next = this->end;
			this->end = t;
		}

		List()
		{
			end = nullptr;
		}
	};

	static const int SIZE = 32;

	List** hashTable;

	HT()
	{
		hashTable = new List * [SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			hashTable[i] = new List;
		}
	}
	int hash(string key)
	{
		int sum = 0;
		for (auto i : key)
		{
			sum += int(i);
		}
		return abs(sum) % SIZE;
	}

	bool add(string key, int cost)
	{
		int place = hash(key);
		if (hashTable[place]->end == nullptr)
		{
			hashTable[place]->pull(key, cost);
		}
		else
		{
			List* t = hashTable[place]->end;
			while (t != nullptr)
			{
				if (t->name == key)
				{
					return false;
				}
				t = t->next;
			}
			hashTable[place]->pull(key, cost);
		}
		return true;
	}

	void remove(string key)
	{
		int place = hash(key);
		List* t = hashTable[place]->end;
		List* preT = nullptr;
		while (t != nullptr)
		{
			if (t->name == key && preT == nullptr)
			{
				hashTable[place]->end = t->next;
				delete t;
				break;
			}
			else if (t->name == key && t->next == nullptr)
			{
				preT->next = nullptr;
				delete t;
				break;
			}
			else if (t->name == key)
			{
				preT->next = t->next;
				delete t;
				break;
			}
			preT = t;
			t = t->next;
		}
	}

	int get(string key)
	{
		int place = hash(key);
		if (hashTable[place]->end == nullptr)
		{
			return 0;
		}
		else
		{
			List* t = hashTable[place]->end;
			while (t != nullptr)
			{
				if (t->name == key)
				{
					return t->cost;
				}
				t = t->next;
			}
		}
		return 0;
	}
};

static const int SIZE = 32;

void main()
{
	setlocale(LC_ALL, "ru");
	HT ht;
	string check;
	bool isExit = false;
	int point;
	try {
		while (!isExit)
		{
			do {
				cls;
				cout << "�������� �����\n";
				cout << "1. �������� �����\n";
				cout << "2. ����� ������\n";
				cout << "3. ������� �����\n";
				cout << "4. �����\n";
				cout << "�������:  ";
				gl(check);
			} while (!isProved(check, 1, 4));
			cls;
			point = stoi(check);
			switch (point)
			{
			case 1:
			{
				string name, cost;
				cout << "������� �������� ������:  ";
				gl(name);
				do {
					cls;
					cout << "������� ��������� ������:  ";
					gl(cost);
				} while (!isProved(cost, 1, INT_MAX));
				if (ht.add(name, stoi(cost)))
				{
					cout << "����� ��������!\n";
				}
				else
				{
					cout << "����� ��� ����!\n";
				}
				pause;
				break;
			}
			case 2:
			{
				string name;
				cout << "������� �������� ������:  ";
				gl(name);
				cout << "��������� ������:  " << ht.get(name) << endl;
				pause;
				break;
			}
			case 3:
			{
				string name;
				cout << "������� �������� ������:  ";
				gl(name);
				if (ht.get(name) == INT_MAX)
				{
					cout << "����� �� ������!\n";
				}
				else
				{
					cout << "����� ������!\n";
					ht.remove(name);
				}
				pause;
				break;
			}
			case 4:
			{
				pause;
				isExit = true;
				break;
			}
			}
		}
	}
	catch (const char* ex)
	{
		cls;
		cout << "�������� ������ �������" << endl;
	}
}