//	ввод элементов структуры с клавиатуры;
//	вывод элементов структуры в консольное окно;
//	удаление заданной структурированной переменной;
//	поиск информации;
//	запись информации в файл;
//	чтение данных из файла.

//Личная библиотека.Автор книги, название, издательство, раздел библиотеки
//(специальная литература, хобби, домашнее хозяйство, беллетристика и т.д.),
//происхождение(покупка, кража, подарок) и наличие книги в данный момент.
//Выбор книг по автору.

#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
using namespace std;

struct Library
{
	int id = 0;

	string author,
		   title,
		   publisher,
		   genre,
		   origin;

	bool isThere = false;

	void SetDatas()
	{
		system("cls");

		cout << "Введите название книги: ";
		cin.ignore();
		getline(cin, title);

		cout << "\nВведите автора: ";
		getline(cin, author);

		cout << "\nВведите публикатора: ";
		getline(cin, publisher);

		cout << "\nВведите жанр книги: ";
		getline(cin, genre);

		cout << "\nКакого происхождение книги: ";
		getline(cin, origin);

		cout << "\nКнига есть в библиотеке? \n1) Да\n2) Нет\nВведите: ";
		string pointMenu;
		getline(cin, pointMenu);

		while (pointMenu != "1" && pointMenu != "2")
		{
			cout << "Введите 1 или 2! ";
			getline(cin, pointMenu);
		}

		if (pointMenu == "1")
			isThere = true;
		else
			isThere = false;

		system("cls");
		cout << "Информация сохранена!";
		Sleep(800);

		system("cls");
	}

	void SaveBook()
	{
		system("cls");
		fstream file;
		string path = "data.txt";
		file.open(path, fstream::in | fstream::out | fstream::app);

		int id = GetLastID() + 1;

		file << id << "\n";
		file << this->title << "\n";
		file << this->author << "\n";
		file << this->publisher << "\n";
		file << this->genre << "\n";
		file << this->origin << "\n";
		file << this->isThere << "\n";

		file.close();
	}

	int GetLastID()
	{
		string trash;
		string path = "data.txt";
		ifstream file;
		file.open(path);

		int i = 0;
		string ID,
			   fakeID;

		if (!file.is_open())
			return this->id;

		while (!file.eof())
		{
			if (i++ % 7 == 0)
			{
				getline(file, fakeID);

				if (fakeID != "")
				{
					ID = fakeID;
				}
			}
			else
			{
				getline(file, trash);
			}
		}
		int id = 0;

		if (ID != "")
		{
			id = stoi(ID);
		}

		file.close();
		return id;
	}

	void GetDatas()
	{
		cout << "ID:\t\t\t" << id
			<< "\nНазвание книги:\t\t" << title
			<< "\nПубликатор:\t\t" << publisher
			<< "\nАвтор:\t\t\t" << author 
			<< "\nЖанр:\t\t\t" << genre
			<<"\nПроисхождение:\t\t" << origin << endl;
	}

	void GetDatasFromFile()
	{
		ifstream file;
		string path = "data.txt";
		file.open(path);

		string ID,
			   isThere;
		/*file.getline(title, 50);
		file.getline(author, 50);
		file.getline(publisher, 50);
		file.getline(genre, 50);
		file.getline(origin, 50);*/
		getline(file, ID);
		getline(file, title);
		getline(file, author);
		getline(file, publisher);
		getline(file, genre);
		getline(file, origin);
		getline(file, isThere);

		id = stoi(ID);
		this->isThere = stoi(isThere);

		file.close();
	}

	void GetDatasFromFile(int i)
	{
		ifstream file;
		string path = "data.txt";
		file.open(path);

		i *= 7;
		int j = 0;
		string trash;

		while (j++ < i)
		{
			getline(file, trash);
		}

		string ID,
			isThere;
		/*file.getline(title, 50);
		file.getline(author, 50);
		file.getline(publisher, 50);
		file.getline(genre, 50);
		file.getline(origin, 50);*/
		getline(file, ID);
		getline(file, title);
		getline(file, author);
		getline(file, publisher);
		getline(file, genre);
		getline(file, origin);
		getline(file, isThere);

		this->id = stoi(ID);
		this->isThere = stoi(isThere);

		file.close();
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");

	bool isExit = false;
	int bookNum = 0;
	Library book[20];

	for (int i = 0; i < book[0].GetLastID(); i++)
	{
		book[bookNum++].GetDatasFromFile(i);
	}

	while (!isExit)
	{
		system("cls");

		cout << "Выберите пункт меню:"
			<< "\n1. Ввод элементов структуры с клавиатуры; "
			<< "\n2. Вывод элементов структуры в консольное окно;"
			<< "\n3. Удаление заданной структурированной переменной;"
			<< "\n4. Поиск информации;"
			<< "\n5. Запись информации в файл;"
			<< "\n6. Чтение данных из файла."
			<< "\n7. Выход"
			<< "\nВведите пункт меню: ";

		string pointMenu;

		getline(cin, pointMenu);

		if (pointMenu > "7" || pointMenu < "1")
			continue;

		switch (stoi(pointMenu))
		{
		case 1: // add Book
		{
			book[bookNum++].SetDatas();
			break;
		}
		case 2: // Get info
		{
			system("cls");
			for (int i = 0; i < book[0].GetLastID(); i++)
			{
				book[i].GetDatas();
				cout << "\n";
			}
			Sleep(4000);

			break;
		}
		case 3: // Dell book
		{

			system("cls");

			for (int i = 0; i < book[0].GetLastID(); i++)
			{
				book[i].GetDatas();
				cout << "\n";
			}

			cout << "Введите айди книги, которую хотите удалить: ";
			string ID_toDel;
			getline(cin, ID_toDel);

			while (stoi(ID_toDel) < 0 || stoi(ID_toDel) > book[0].GetLastID())
			{
				cout << "Некорректный айди. Введите его заного: ";
				getline(cin, ID_toDel);
			}

			bookNum--;

			int lastID = book[0].GetLastID();

			ofstream fout;
			fout.open("data.txt");
			fout.close();
			bool isDel = false;

			for (int i = 0; i < lastID; i++)
			{
				if (book[i].id == stoi(ID_toDel))
				{
					isDel = true;
				}
				else
				{
					if (isDel)
					{
						book[i].id -= 1;
					}

					book[i].SaveBook();
				}
			}

			bookNum = -1;
			for (int i = 0; i < book[0].GetLastID(); i++)
			{
				book[++bookNum].GetDatasFromFile(i);
			}
			break; 
		}
		case 4: // Research book
		{
			system("cls");
			string hint;
			cout << "Введите какой-нибудь признак книги: ";
			getline(cin, hint);

			bool isCoincidence = false;

			for (int i = 0; i < bookNum; i++)
			{
				if (book[i].author == hint)
				{
					book[i].GetDatas();
					Sleep(2000);
					isCoincidence = true;
					break;
				}
				else if (book[i].title == hint)
				{
					book[i].GetDatas();
					Sleep(2000);
					isCoincidence = true;
					break;
				}
				else if (book[i].genre == hint)
				{
					book[i].GetDatas();
					Sleep(2000);
					isCoincidence = true;
					break;
				}
				else if (book[i].origin == hint)
				{
					book[i].GetDatas();
					Sleep(2000);
					isCoincidence = true;
					break;
				}
				else
				{
					isCoincidence = false;
				}
			}
			if (!isCoincidence)
			{
				cout << "Совпадений нет!";
			}
			Sleep(5000);
			break;
		}
		case 5: // Save to file
		{
			system("cls");
			if (bookNum == -1)
			{
				cout << "Вы еще не создали книгу! Выберите пункт 1";
				Sleep(1000);
				break;
			}

			book[bookNum - 1].SaveBook();
			break;
		}
		case 6: // Read struct from file
		{
			book[bookNum].GetDatasFromFile();
			book[bookNum].GetDatas();
			Sleep(1000);
			break;
		}
		case 7: // Exit
		{
			isExit = true;
			break;
		}
		}
	}
}