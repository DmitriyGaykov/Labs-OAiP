//Скопировать в файл FILE2 только те строки из FILE1,
//которые начинаются с буквы «А».Подсчитать количество слов в FILE2.

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int strSize(string str);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream file1;
	string path1 = "file1.txt";
	file1.open(path1);

	fstream file2;
	string path2 = "file2.txt";
	file2.open(path2, fstream::in | fstream::out);

	string str,
		   trash;

	bool isA = false,
		 isWord = false;

	short numStr[20],
		  i = 0,
		  j = 0,
		  cntWords = 0;

	while (!file1.eof())
	{
		getline(file1, str);

		if (str[0] == 'A' || str[0] == 'a')
		{
			isWord = false;

			file2 << str << "\n";

			for (int i = 0; i < strSize(str); i++)
			{
				if (str[i] != ' ' && !isWord)
				{
					cntWords++;
					isWord = true;
				}

				if (str[i] == ' ')
				{
					isWord = false;
				}
			}
		}
	}

	cout << "Количество слов в " << path2 << " - " << cntWords << endl;

	file2.close();
	file1.close();
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