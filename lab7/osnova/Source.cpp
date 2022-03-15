//Создать стек с целочисленным информационным полем.Заполнить его длинами строк, считанных из файла.Распечатать
//на экране содержимое стека.Указать номер и длину последней самой короткой строки файла.
#include <iostream>
#include <windows.h>
#include <fstream>
#include "check.h"
using namespace std;

struct Integer
{
	Integer* head,
			 *next,
			 *end;

	int num;
} *Area,* NewEl;

string path = "data.txt";

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Area = new Integer;
	Area->head = Area;

	int min = 9000,
		numStr,
		i = 0;
	string str = " ";

	fstream file;
	file.open(path, fstream::in);

	while (!file.eof())
	{
		str = "";
		getline(file, str);
		if (str.size() <= min)
		{
			min = str.size();
			numStr = i + 1;
		}
		NewEl = new Integer;
		NewEl->num = str.size();
		NewEl->next = Area->head;
		Area->head = NewEl;
		i++;
		cout << i << ") " << str << endl;
	}

	ent;
	ent;
	cout << "Длина самой короткой строки = " << min
		<< "\nЕе номер = " << numStr << endl;

	cout << "Стек состоит из:\n";
	i = 1;
	while (Area->head != Area)
	{
		cout << i++ << ") " << Area->head->num << endl;
		NewEl = Area->head->next;
		delete Area->head;
		Area->head = NewEl;
	}

	file.close();
	return 0;
}