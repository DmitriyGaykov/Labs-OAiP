//Ввести с клавиатуры строку, состоящую из цифр и слов, разделенных пробелами, и записать ее в файл.
//Прочитать из файла данные, подсчитать количество символов в самом длинном слове и вывести его.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main()
{
	string str;

	cout << "Enter the string: ";
	getline(cin, str);

	ofstream fout;
	string path = "file.txt";
	fout.open(path);

	fout << str;

	fout.close();

/////////////////////////////////////////////////////////////////////////////

	ifstream fin;
	fin.open(path);

	string newStr,
		   maxWord;

	short countSymb[20],
		  size = 0,
		  maxSize = size,
		  order;

	while (!fin.eof())
	{
		fin >> newStr;
		countSymb[size++] = newStr.size();

		if (newStr.size() >= maxSize)
		{
			order = size - 1;
			maxSize = newStr.size();
			maxWord = newStr;
		}
	}

	cout << "The longest word is \"" << maxWord << "\"\nThere is " << maxSize << " element\n";


	fin.close();
}