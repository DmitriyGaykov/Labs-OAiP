#include <iostream>
#include "check.h"

//1) ��� ��������� p1 �� ������ ��������� ������.�������� ������� ������ ���������� ������ ������,
//���������� ������ ��������� ���������(������ ������ �� ���������).

//2) ��� ��������� p1 �� ������ ��������� ������.�������� ������� ������ ����� �������� ���� ������� ������� ������.

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
		cout << "1 -	�������� ������\n";
		cout << "2 -	���������� ��������\n";
		cout << "3 -	����� �� �����\n";
		cout << "4 -	�������� ��������\n";
		cout << "5 -	����� ������\n";
		cout << "6 -	������� ������\n";
		cout << "7 -	�����\n";
		cout << "�������������� �������:\n";
		cout << "8 -    ������� ���������� ������ ������, ���������� ������ ��������� ���������\n";
		cout << "9 -    ������� ����� �������� ���� ������� ������� ������\n";
		cout << "��� �����?\n";
		gl(check);
		while (!isProved(check, 1, 9))
		{
			cls;
			cout << "1 -	�������� ������\n";
			cout << "2 -	���������� ��������\n";
			cout << "3 -	����� �� �����\n";
			cout << "4 -	�������� ��������\n";
			cout << "5 -	����� ������\n";
			cout << "6 -	������� ������\n";
			cout << "7 -	�����\n";
			cout << "��� �����?\n";
			cout << "�������������� �������:\n";
			cout << "8 -    ������� ���������� ������ ������, ���������� ������ ��������� ���������\n";
			cout << "9 -    ������� ����� �������� ���� ������� ������� ������\n";
			cout << "��� �����?\n";
			gl(check);
		}
		cls;
		point = stoi(check);
		switch (point)
		{
		case 1: // create tree
		{
			tree = createTree();
			cout << "������ �������\n";
			pause;
			break;
		}
		case 2: // add element
		{
			if (tree == nullptr)
			{
				cout << "������ �� �������\n";
				pause;
				break;
			}
			cout << "������� ��������\n";
			gl(check);
			while (!isProved(check, -2000000, 2000000))
			{
				cls;
				cout << "������� ��������\n";
				gl(check);
			}
			cls;
			tree = add(tree, stoi(check));
			cout << "������� ��������\n";
			pause;
			break;
		}
		case 3: // search
		{
			if (tree == nullptr)
			{
				cout << "������ �� �������\n";
				pause;
				break;
			}
			cout << "������� ��������\n";
			gl(check);
			while (!isProved(check, -2000000, 2000000))
			{
				cls;
				cout << "������� ��������\n";
				gl(check);
			}
			cls;
			Tree* temp = tree;
			while (temp != nullptr)
			{
				if (temp->value == stoi(check))
				{
					cout << "������� ������\n";
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
				cout << "������� �� ������\n";
			}
			pause;
			break;
		}
		case 4:// delete
		{
			if (tree == nullptr)
			{
				cout << "������ �� �������\n";
				pause;
				break;
			}
			cout << "������� ��������\n";
			gl(check);
			while (!isProved(check, -2000000, 2000000))
			{
				cls;
				cout << "������� ��������(-2000000 ->  2000000\n";
				gl(check);
			}
			cls;
			tree = delet(tree, stoi(check));
			cout << "������� ������\n";
			pause;
			break;
		}
		case 5: // output tree
		{
			if (tree == nullptr)
			{
				cout << "������ �� �������\n";
				pause;
				break;
			}
			cout << "������:\n";
			printTree(tree);
			pause;
			break;
		}
		case 6: // clear tree
		{
			if (tree == nullptr)
			{
				cout << "������ �� �������\n";
				pause;
				break;
			}
			tree = clearTree(tree);
			cout << "������ �������\n";
			pause;
			break;
		}
		case 7: // exit
		{
			cout << "�����\n";
			pause;
			isExit = true;
			break;
		}
		case 8: // count of left root
		{
			if (tree == nullptr)
			{
				cout << "������ �� �������!" << endl;
				pause;
				break;
			}
			Tree* p1 = tree;
			cout << "���������� ����� ������: " << countLR(p1) << endl;
			pause;
			break;
		}
		case 9:
		{
			if (tree == nullptr)
			{
				cout << "������ �� �������!" << endl;
				pause;
				break;
			}
			cout << "����� ���� �������� �� ���� ������: " << sumAll(tree) << endl;
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