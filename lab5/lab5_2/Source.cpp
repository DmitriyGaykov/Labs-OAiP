//������ ����������.����� �����, ��������, ������������, ������ ����������
//(����������� ����������, �����, �������� ���������, ������������� � �.�.), 
//�������������(�������, �����, �������) � ������� ����� � ������ ������.
//����� ���� �� ����.������������� ����� ����������� � ������� ������������.

#include <iostream>
#include <string>
#include <Windows.h>
#include <cstring>
#include <fstream>
using namespace std;
#define COUNTBOOKS 30
#include "check.h"

enum background
{
	BUY = 1,
	ROBBERY,
	GIFT
};

union libr
{
	int id;

	char author[50],
		title[50],
		date[50],
		genre[50];

	char origin[50];
	bool isThere = false;
} datas;

struct Library
{
	int id;

	string author,
		title,
		date,
		genre;

	background origin;

	bool isThere = false;

	void SetDatas()
	{
		system("cls");

		cout << "������� �������� �����: ";
		getline(cin, title);

		cout << "\n������� ������: ";
		getline(cin, author);

		cout << "\n������� ��� ����������: ";
		cin.getline(datas.date, 50);

		while (!isProved(datas.date, 0, 2022))
		{
			cout << "\n������� ��� ����������(�� 0 �� 2022): ";
			cin.getline(datas.date, 50);
		}

		short diff = 4 - strlen(datas.date);

		if (diff == 0)
		{
			this->date = datas.date;
		}
		else
		{
			char checkedDate[50] = "",
				 symb[] = "0";

			for (int i = 0; i < diff; i++)
			{
				strcat_s(checkedDate, symb);
			}

			strcat_s(checkedDate, datas.date);

			this->date = checkedDate;
		}

		cout << "\n������� ���� �����: ";
		getline(cin, genre);

		cout << "\n������ ������������� �����(1. �������,2. �����,3. �������): ";
		cin.getline(datas.origin, 50);

		while (!isProved(datas.origin, 1, 3))
		{
			cout << "\n������ ������������� �����(\n1. �������,\n2. �����,\n3. �������\n): ";
			cin.getline(datas.origin, 50);
		}

		switch (atoi(datas.origin))
		{
		case 1:
			this->origin = BUY;
			break;
		case 2:
			this->origin = ROBBERY;
			break;
		case 3:
			this->origin = GIFT;
			break;
		}

		cout << "\n����� ���� � ����������? \n1) ��\n2) ���\n�������: ";
		string pointMenu;
		getline(cin, pointMenu);

		while (pointMenu != "1" && pointMenu != "2")
		{
			cout << "������� 1 ��� 2! ";
			getline(cin, pointMenu);
		}

		if (pointMenu == "1")
			isThere = true;
		else
			isThere = false;

		system("cls");
		cout << "���������� ���������!";
		Sleep(800);

		system("cls");
	}

	void SaveBook()
	{
		id = 0;

		system("cls");
		fstream file;
		string path = "data.txt";
		file.open(path, fstream::in | fstream::out | fstream::app);

		this->id = GetLastID() + 1;

		file << id << "\n";
		file << this->title << "\n";
		file << this->author << "\n";
		file << this->date << "\n";
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
		datas.id = 0;

		if (ID != "")
		{
			datas.id = stoi(ID);
		}

		file.close();
		return datas.id;
	}

	void GetDatas()
	{
		cout << "ID:\t\t\t" << id
			<< "\n�������� �����:\t\t" << title
			<< "\n��� ����������:\t\t" << date
			<< "\n�����:\t\t\t" << author
			<< "\n����:\t\t\t" << genre;

		switch (origin)
		{
		case BUY:
			cout << "\n�������������:\t\t�������" << endl;
			break;
		case ROBBERY:
			cout << "\n�������������:\t\t�����" << endl;
			break;
		case GIFT:
			cout << "\n�������������:\t\t�������" << endl;
			break;
		default:
			cout << "\n�������������:\t\t����������" << endl;
			break;
		}
	}

	void GetDatasFromFile()
	{
		ifstream file;
		string path = "data.txt";
		file.open(path);

		string ID,
			isThere,
			origin;

		/*file.getline(title, 50);
		file.getline(author, 50);
		file.getline(date, 50);
		file.getline(genre, 50);
		file.getline(origin, 50);*/
		getline(file, ID);
		getline(file, title);
		getline(file, author);
		getline(file, date);
		getline(file, genre);
		getline(file, origin);
		getline(file, isThere);

		this->origin = background(stoi(origin));
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
			isThere,
			origin;
		/*file.getline(title, 50);
		file.getline(author, 50);
		file.getline(date, 50);
		file.getline(genre, 50);
		file.getline(origin, 50);*/
		getline(file, ID);
		getline(file, title);
		getline(file, author);
		getline(file, date);
		getline(file, genre);
		getline(file, origin);
		getline(file, isThere);

		this->origin = background(stoi(origin));
		this->id = stoi(ID);
		this->isThere = stoi(isThere);

		file.close();
	}

} book[COUNTBOOKS];

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");

	bool isExit = false;
	int bookNum = 0;

	for (int i = 0; i < book[0].GetLastID(); i++)
	{
		book[bookNum++].GetDatasFromFile(i);
	}

	while (!isExit)
	{
		system("cls");

		cout << "�������� ����� ����:"
			<< "\n1. ���� ��������� ��������� � ����������; "
			<< "\n2. ����� ��������� ��������� � ���������� ����;"
			<< "\n3. �������� �������� ����������������� ����������;"
			<< "\n4. ����� ����������;"
			<< "\n5. �����"
			<< "\n������� ����� ����: ";

		string pointMenu;

		getline(cin, pointMenu);

		if (pointMenu > "7" || pointMenu < "1")
			continue;

		switch (stoi(pointMenu))
		{
		case 1: // add Book
		{
			book[bookNum++].SetDatas();
			book[bookNum - 1].SaveBook();
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
		case 3: // Del book
		{

			system("cls");

			for (int i = 0; i < book[0].GetLastID(); i++)
			{
				book[i].GetDatas();
				cout << "\n";
			}

			cout << "������� ���� �����, ������� ������ �������: ";
			string ID_toDel;
			getline(cin, ID_toDel);

			while (stoi(ID_toDel) < 0 || stoi(ID_toDel) > book[0].GetLastID())
			{
				cout << "������������ ����. ������� ��� ������: ";
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

			bookNum = 0;
			for (int i = 0; i < book[0].GetLastID(); i++)
			{
				book[bookNum++].GetDatasFromFile(i);
			}
			break;
		}
		case 4: // Research book
		{
			system("cls");
			string year;
			cout << "������� ��� ������� �����: ";
			getline(cin, year);

			while (!isProved(year, 0, 2022))
			{
				cout << "������� ��� ������� �����(�� 0000 �� 2022)";
				getline(cin, year);
			}

			short diff = 4 - year.size();

			for (int i = 0; i < diff; i++)
			{
				year = '0' + year;
			}

			bool isNotCoin = false;
			system("cls");

			for (int i = 0; i < COUNTBOOKS; i++)
			{
				if (book[i].date == year)
				{
					book[i].GetDatas();
					isNotCoin = true;
				}
				else if (!isNotCoin && book[i].date != year)
				{
					isNotCoin = false;
				}
			}

			if (!isNotCoin)
			{
				cout << "���������� ���!";
			}

			cin.ignore();
			break;
		}
		case 5: // Exit
		{
			isExit = true;
			break;
		}
		}
	}
}