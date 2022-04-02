#include <iostream>
#include "check.h"

//1) Дан указатель p1 на корень непустого дерева.Написать функцию вывода количества вершин дерева,
//являющихся левыми дочерними вершинами(корень дерева не учитывать).

//2) Дан указатель p1 на корень непустого дерева.Написать функцию вывода суммы значений всех листьев данного дерева.

struct Tree
{
	int value;
	Tree *left;
	Tree *right;
} *tree;

Tree* createTree();
Tree* add(Tree*, int);
Tree* delet(Tree* Root, int key);
void printTree(Tree*);
Tree* clearTree(Tree*);
int countLR(Tree*, int cnt = 0);
int sumAll(Tree*, int sum = 0);

void main()
{
	setlocale(LC_ALL, "ru");
	tree = nullptr;
	string check;
	int count = 0,
		point;
	bool isExit = false;
	while (!isExit)
	{
		cls;
		cout << "1 -	создание дерева\n";
		cout << "2 -	добавление элемента\n";
		cout << "3 -	поиск по ключу\n";
		cout << "4 -	удаление элемента\n";
		cout << "5 -	вывод дерева\n";
		cout << "6 -	очистка дерева\n";
		cout << "7 -	выход\n";
		cout << "Дополнительные задания:\n";
		cout << "8 -    вывести количество вершин дерева, являющихся левыми дочерними вершинами\n";
		cout << "9 -    вывести сумму значений всех листьев данного дерева\n";
		cout << "ваш выбор?\n";
		gl(check);
		while (!isProved(check, 1, 9))
		{
			cls;
			cout << "1 -	создание дерева\n";
			cout << "2 -	добавление элемента\n";
			cout << "3 -	поиск по ключу\n";
			cout << "4 -	удаление элемента\n";
			cout << "5 -	вывод дерева\n";
			cout << "6 -	очистка дерева\n";
			cout << "7 -	выход\n";
			cout << "ваш выбор?\n";
			cout << "Дополнительные задания:\n";
			cout << "8 -    вывести количество вершин дерева, являющихся левыми дочерними вершинами\n";
			cout << "9 -    вывести сумму значений всех листьев данного дерева\n";
			cout << "ваш выбор?\n";
			gl(check);
		}
		cls;
		point = stoi(check);
		switch (point)
		{
		case 1: // create tree
		{
			tree = createTree();
			cout << "Дерево создано\n";
			pause;
			break;
		}
		case 2: // add element
		{
			if (tree == nullptr)
			{
				cout << "Дерево не создано\n";
				pause;
				break;
			}
			cout << "Введите значение\n";
			gl(check);
			while (!isProved(check, -2000000, 2000000))
			{
				cls;
				cout << "Введите значение\n";
				gl(check);
			}
			cls;
			tree = add(tree, stoi(check));
			cout << "Элемент добавлен\n";
			pause;
			break;
		}
		case 3: // search
		{
			if (tree == nullptr)
			{
				cout << "Дерево не создано\n";
				pause;
				break;
			}
			cout << "Введите значение\n";
			gl(check);
			while (!isProved(check, -2000000, 2000000))
			{
				cls;
				cout << "Введите значение\n";
				gl(check);
			}
			cls;
			Tree* temp = tree;
			while (temp != nullptr)
			{
				if (temp->value == stoi(check))
				{
					cout << "Элемент найден\n";
					break;
				}
				else if (temp->value > stoi(check))
				{
					temp = temp->left;
				}
				else
				{
					temp = temp->right;
				}
			}
			if (temp == nullptr)
			{
				cout << "Элемент не найден\n";
			}
			pause;
			break;
		}
		case 4:// delete
		{
			if (tree == nullptr)
			{
				cout << "Дерево не создано\n";
				pause;
				break;
			}
			cout << "Введите значение\n";
			gl(check);
			while (!isProved(check, -2000000, 2000000))
			{
				cls;
				cout << "Введите значение(-2000000 ->  2000000\n";
				gl(check);
			}
			cls;
			tree = delet(tree, stoi(check));
			cout << "Элемент удален\n";
			pause;
			break;
		}
		case 5: // output tree
		{
			if (tree == nullptr)
			{
				cout << "Дерево не создано\n";
				pause;
				break;
			}
			cout << "Дерево:\n";
			printTree(tree);
			pause;
			break;
		}
		case 6: // clear tree
		{
			if (tree == nullptr)
			{
				cout << "Дерево не создано\n";
				pause;
				break;
			}
			tree = clearTree(tree);
			cout << "Дерево очищено\n";
			pause;
			break;
		}
		case 7: // exit
		{
			cout << "Выход\n";
			pause;
			isExit = true;
			break;
		}
		case 8: // count of left root
		{
			if (tree == nullptr)
			{
				cout << "Дерево не создано!" << endl;
				pause;
				break;
			}
			Tree* p1 = tree;
			cout << "Количество левых вершин: " << countLR(p1) << endl;
			pause;
			break;
		}
		case 9:
		{
			if (tree == nullptr)
			{
				cout << "Дерево не создано!" << endl;
				pause;
				break;
			}
			cout << "Сумма всех значений из всех ветвей: " << sumAll(tree) << endl;
			pause;
			break;
		}
		}
	}
}

Tree* createTree()
{
	Tree *tree = new Tree;
	tree->left = nullptr;
	tree->right = nullptr;
	tree->value = 0;
	return tree;
}
Tree* add(Tree* tree, int value)
{
	if (tree == nullptr)
	{
		tree = new Tree;
		tree->left = nullptr;
		tree->right = nullptr;
		tree->value = value;
		return tree;
	}
	if (value < tree->value)
	{
		tree->left = add(tree->left, value);
	}
	else
	{
		tree->right = add(tree->right, value);
	}
	return tree;
}
Tree* min(Tree* tree)
{
	if (tree->left == nullptr)
	{
		return tree;
	}
	else
	{
		return min(tree->left);
	}
}
Tree* delet(Tree* Root, int key)
{
	if (Root == nullptr)
	{
		return Root;
	}
	if (key < Root->value)
	{
		Root->left = delet(Root->left, key);
	}
	else if (key > Root->value)
	{
		Root->right = delet(Root->right, key);
	}
	else
	{
		if (Root->left == nullptr)
		{
			Tree* temp = Root->right;
			delete Root;
			return temp;
		}
		else if (Root->right == nullptr)
		{
			Tree* temp = Root->left;
			delete Root;
			return temp;
		}
		Tree* temp = min(Root->right);
		Root->value = temp->value;
		Root->right = delet(Root->right, temp->value);
	}
	return Root;
}
void printTree(Tree* tree)
{
	Tree* tempR = tree->right;
	Tree* tempL = tree->left;
	if (tempR != nullptr)
	{
		printTree(tempR);
	}
	cout << tree->value << " ";
	if (tempL != nullptr)
	{
		printTree(tempL);
	}
}
Tree* clearTree(Tree* tree){
	Tree* tempR = tree->right;
	Tree* tempL = tree->left;
	if (tempR != nullptr)
	{
		clearTree(tempR);
	}
	if (tempR == nullptr)
	{
		delete tempR;
	}
	if (tempL != nullptr)
	{
		clearTree(tempL);
	}
	if (tempL == nullptr)
	{
		delete tempL;
	}
	tree = tree->right = tree->left = nullptr;
	return tree;
}
int countLR(Tree* tree, int cnt)
{
	if (tree->left != nullptr)
	{
		cnt += countLR(tree->left, cnt + 1);
	}
	if (tree->right != nullptr)
	{
		Tree* temp = tree->right;
		cnt += countLR(temp);
	}
	return cnt;
}
int sumAll(Tree* tree, int sum)
{
	if (tree->right != nullptr)
	{
		sum = sumAll(tree->right, sum + tree->right->value);
	}
	if (tree->left != nullptr)
	{
		sum = sumAll(tree->left, sum + tree->left->value);
	}
	return sum;
}