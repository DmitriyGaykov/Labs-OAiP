//#include <iostream>
//#include "check.h"
//
//const int SIZE = 32;
//
//struct HashTable
//{
//	int array[SIZE];
//
//	HashTable()
//	{
//		for (auto i : array)
//		{
//			i = INT_MAX;
//		}
//	}
//
//	int hash(int key)
//	{
//		return key % SIZE;
//	}
//
//	HashTable* pull(int key, int value)
//	{
//		int place = hash(int(key));
//		if (key != INT_MAX)
//		{
//			this->array[place] = value;
//		}
//		else
//		{
//			for (int i = place; i < SIZE; i++)
//			{
//				if (array[i] != INT_MAX)
//				{
//					array[i] = value;
//					break;
//				}
//			}
//		}
//		return this;
//	}
//
//	int get(int key)
//	{
//		int place = hash(int(key));
//		return array[place];
//	}
//};
//
//void mfdbain()
//{
//	HashTable* tbl = new HashTable;
//	tbl->pull(12, 32)->pull(13, 4231);
//	cout << tbl->get(12) << endl
//		<< tbl->get(13);
//}