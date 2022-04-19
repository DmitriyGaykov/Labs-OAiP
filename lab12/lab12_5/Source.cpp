#include <iostream>
#include "check.h"

//Изучить работу с красно - черными деревьями.Реализовать основные операции 
//над красно - черным деревом.В красно - черном дереве найти путь от корня
//к некоторому листу, содержащий минимальное количество красных вершин.

struct Tree
{
	int value;
	Tree* left;
	Tree* right;
	Tree* parent;
	bool color;
}*tree;

void main()
{

}