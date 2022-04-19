//В текстовом файле содержатся целые числа.Построить хеш - таблицу из чисел файла.
//Осуществить поиск введенного целого числа в хеш - таблице.

#include <iostream>
#include <fstream>
#include "check.h"
using namespace std;

struct HT
{
	struct List
	{
		int number = INT_MAX;
		int str;
		List* next = nullptr;
		List* end = nullptr;

		void pull(int name, int cost)
		{
			List* t = new List;
			t->number = cost;
			t->str = name;
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
	int hash(int key)
	{
		return key * (key + key) % SIZE;
	}

	bool add(int key, int cost)
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
				if (t->str == key)
				{
					return false;
				}
				t = t->next;
			}
			hashTable[place]->pull(key, cost);
		}
		return true;
	}

	void remove(int key)
	{
		int place = hash(key);
		List* t = hashTable[place]->end;
		List* preT = nullptr;
		while (t != nullptr)
		{
			if (t->str == key && preT == nullptr)
			{
				hashTable[place]->end = t->next;
				delete t;
				break;
			}
			else if (t->str == key && t->next == nullptr)
			{
				preT->next = nullptr;
				delete t;
				break;
			}
			else if (t->str == key)
			{
				preT->next = t->next;
				delete t;
				break;
			}
			preT = t;
			t = t->next;
		}
	}

	int get(int key)
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
				if (t->str == key)
				{
					return t->number;
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
	string path = "data.txt";
	int key = 1;
	string check;
	int number;
	ifstream file(path);

	while (!file.eof())
	{
		getline(file, check);
		if (isProved(check))
		{
			number = stoi(check);
			ht.add(key++, number);
		}
	}

	while (true)
	{
		do
		{
			cout << "Введите ключ: ";
			gl(check);
		} while (!isProved(check));

		number = stoi(check);

		cout << "Значение: " << ht.get(number) << endl << endl;
	}

	file.close();
}