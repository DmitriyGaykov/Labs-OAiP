//Ввести с клавиатуры строку символов, состоящую из групп цифр и нулей, и записать ее в файл.
//Про - читать из файла данные и вывести самую короткую группу.

#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;

int strSize(string);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str;

	cout << "Введите строку, состоящую из группу цифр и нулей: ";
	getline(cin, str);

	for (int i = 0; i < strSize(str); i++)
	{
		if (str[i] > '9' || str[i] < '0' && str[i] != ' ')
		{
			for (int j = i; j < strSize(str); j++)
			{
				str[j] = str[j + 1];
			}
			
			i--;
		}
	}

	cout << str << " - записана в файл" << endl;

	fstream file;
	string path = "file.txt";
	file.open(path, fstream::in | fstream::out);

	file << str;

	file.seekg(0);

	int minSize = 2000,
		cntGroups = 0,
		i = 0,
		Sizes[30];

	string group[30];

	while (!file.eof())
	{
		file >> str;
		cntGroups++;
		Sizes[i++] = strSize(str);
		group[i - 1] = str;

		if (minSize > strSize(str))
		{
			minSize = strSize(str);
		}
	}

	for (int i = 0; i < cntGroups; i++)
	{
		if (Sizes[i] == minSize)
		{
			cout << "\nМинимальная группа " << group[i] << endl;
		}
	}

	file.close();
	return 0;
}

int strSize(string str)
{
	int size = 0,
		i = 0;
	bool isEndl = false;


	while (!isEndl)
	{
		if (str[i++] == '\0')
		{
			isEndl = true;
		}
		else
		{
			size++;
		}
	}

	return size;
}