//Ввести с клавиатуры строку символов, состоящую из цифр и слов,
//разделенных пробелами, и записать ее в файл.
//Прочитать из файла данные и вывести нечетные числа строки.

#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str;

	cout << "Введите строку: ";
	getline(cin, str);

	fstream file;
	string path = "data.txt";
	file.open(path, fstream::in | fstream::out);

	file << str;
	
	file.seekg(0);
	str = "";

	bool onlyNum = true;

	while (!file.eof())
	{
		char symb;

		file.get(symb);

		if (symb != ' ')
		{
			if (symb > '9' || symb < '0')
			{
				onlyNum = false;
			}

			str += symb;
		}
		
		else if (symb == ' ')
		{
			if (onlyNum && stoi(str) % 2 != 0)
			{
				cout << str << endl;
			}

			str = "";
			onlyNum = true;
		}
	}

	file.close();
	return 0;
}