#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//1.Скопировать из файла FILE1 в файл FILE2 все строки, которые не содержат
//цифры.Подсчитать количество строк, которые начинаются на букву «А» в файле FILE2.

void main()
{
	ifstream fin;
	string path1 = "file1.txt";
	fin.open(path1);

	ofstream fout;
	string path2 = "file2.txt";
	fout.open(path2);

	if (!fout.is_open() || !fin.is_open())
	{
		cout << "Проблема с файлом!" << endl;
	}
	else
	{
		string strF1;
		bool isNumber = false;
		char numbers[] = "0123456789";

		while (!fin.eof())
		{
			getline(fin, strF1);

			for (int i = 0; i < strF1.size(); i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (strF1[i] == numbers[j])
					{
						isNumber = true;
						break;
					}

					else
					{
						isNumber = false;
					}
				}

				if (isNumber)
					break;
			}

			if (!isNumber)
			{
				fout << strF1 << "\n";
			}
		}
	}

	fin.close();
	fout.close();

	ifstream file2_in;
	file2_in.open(path2);
	
	string str;
	short count_A = 0;

	while (!file2_in.eof())
	{
		getline(file2_in, str);

		if (str[0] == 'A')
		{
			count_A++;
		}
	}
	cout << "Count of string, that start from A = " << count_A << endl;

	file2_in.close();
}