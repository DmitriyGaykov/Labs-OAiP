//Каждый элемент списка студентов содержит фамилию, имя, год рождения, курс, номер группы,
//оценки по пяти предметам.Упорядочить студентов по курсу, причем студенты одного курса должны 
//располагаться в алфавит - ном порядке.Найти средний балл каждой группы по каждому предмету.
//Определить самого старшего студента и самого младшего студентов.Для каждой группы найти лучшего 
//с точки зрения успеваемости студента

// #define TEST
#define MAXCNTSTUDENTINGROUP 20
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

struct Student
{
	string LastName;
	string FirstName;
	string date = "11.01.2999";
	int course;
	int group;
	float avr = 10.0;
	int marks[5] = {10, 10, 10, 10, 10};
	int maxMark = -1;

	string exams[5] = {"Русский", "Математика", "История", "Английский", "Физика"};

	Student* next;
	Student* head;
	Student* end;
	Student* prev;

	void GetInfo();
} *students, *newSt;

struct Course
{
	struct Group
	{
		int cnt = 0;
		float avr[5] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
		Student* student[MAXCNTSTUDENTINGROUP];
	} group[5];
}course[4];

#include "check.h"

void append();
void output();
void sort();
void top();

int cnt = 0;

int main()
{
	bool isExit = false;
	int point;
	string check;
	
	students->end = students->head = students = new Student;
	students->head->prev = students;

	while (!isExit)
	{
		ru;
		cls;
		cout << "1) Добавить студента!\n"
			<< "2) Вывести средний балл каждой группы!\n"
			<< "3) Вывести данные о самом младшем и самом старшем студенте\n"
			<< "4) Вывести топ студентов по успеваемости из каждой группы!\n"
			<< "5) Вывести всех студентов!\n"
			<< "Вводите: ";
		getline(cin, check);

		while (!isProved(check, 1, 5))
		{
			cls;
			cout << "1) Добавить студента!\n"
				<< "2) Вывести средний балл каждой группы!\n"
				<< "3) Вывести данные о самом младшем и самом старшем студенте\n"
				<< "4) Вывести топ студентов по успеваемости из каждой группы!\n"
				<< "5) Вывести всех студентов!\n"
				<< "Вводите от 1 до 5: ";
			getline(cin, check);
		}
		cls;

		point = stoi(check);

		switch (point)
		{
		case 1: // add
		{
			cnt++;
			students->head = students->end;
			cout << "Введите фамилию студента: ";
			getline(cin, students->head->LastName);
			while (CountWord(students->head->LastName) != 1 || !isProved(students->head->LastName, "ABCDEFGHIJKLMNOPQRSTUVWXYZАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюяzyxwvutsrqponmlkjihgfedcba") || !((students->head->LastName[0] >= 'A' && students->head->LastName[0] <= 'Z') || (students->head->LastName[0] >= 'А' && students->head->LastName[0] <= 'Я')))
			{
				cls;
				cout << "Введите фамилию студента одним словом: ";
				getline(cin, students->head->LastName);
			}
			cls;
			cout << "Введите имя студента: ";
			getline(cin, students->head->FirstName);
#if defined(TEST)
			while (CountWord(students->head->FirstName) != 1)
#else
			while (CountWord(students->head->FirstName) != 1 || !isProved(students->head->FirstName, "ABCDEFGHIJKLMNOPQRSTUVWXYZАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюяzyxwvutsrqponmlkjihgfedcba") || !((students->head->FirstName[0] >= 'A' && students->head->FirstName[0] <= 'Z') || (students->head->FirstName[0] >= 'А' && students->head->FirstName[0] <= 'Я')))
#endif
			{
				cls;
				cout << "Введите имя студента одним словом: ";
				getline(cin, students->head->FirstName);
			}
			cls;

#if !defined(TEST)
			cout << "Введите дату рождения: ";
			getline(cin, students->head->date);
			while (!checkDate(students->head->date))
			{
				cls;
				cout << "Введите дату рождения(ФОРМАТ: ДД.ММ.ГГГГ): ";
				getline(cin, students->head->date);
			}
			cls;
#endif

			cout << "Введите курс студента: ";
			getline(cin, check);
			while (!isProved(check, 1, 4))
			{
				cls;
				cout << "Введите курс студента от 1 до 4): ";
				getline(cin, check);
			}
			students->head->course = stoi(check);
			cls;

			cout << "Введите группу студента: ";
			getline(cin, check);
			while (!isProved(check, 1, 5))
			{
				cls;
				cout << "Введите группу студента(от 1 до 5): ";
				getline(cin, check);
			}
			students->head->group = stoi(check);
			cls;

#if !defined(TEST)
			cout << "Введите оценки по экзаменам!" << endl;
			int sum = 0;
			for (int i = 0; i < 5; i++)
			{
				cout << students->head->exams[i] << " : ";
				getline(cin, check);
				while (!isProved(check, 1, 10))
				{
					cls;
					cout << students->head->exams[i] << "(от 1 до 10) : ";
					getline(cin, check);
				}
				students->head->marks[i] = stoi(check);
				sum += students->head->marks[i];
				cls;
			}
			students->head->avr = float(sum) / 5.0;
#endif

			cout << "Вы добавили:\n\n";
			students->head->GetInfo();
			course[students->head->course - 1].group[students->head->group - 1].student[course[students->head->course - 1].group[students->head->group - 1].cnt] = students->head;
			course[students->head->course - 1].group[students->head->group - 1].cnt++;
			append();
			sort();
			ent;
			pause;
			break;
		}
		case 2: // avr groups
		{
			float sum = 0.0;
			for (int i = 0; i < 4; i++)
			{
				ent;
				cout << "Курс:\t\t\t\t\t\t\t\t" << i + 1 << endl << endl;
				for (int j = 0; j < 5; j++)
				{
					cout << "Группа:\t\t\t\t\t\t\t\t" << j + 1 << endl << endl;
					if (course[i].group[j].cnt == 0)
						continue;
					for (int k = 0; k < 5; k++)
					{
						for(int m = 0; m < course[i].group[j].cnt; m++)
							sum += course[i].group[j].student[m]->marks[k];
						course[i].group[j].avr[k] = sum / course[i].group[j].cnt;
						cout << "Предмет:\t\t\t\t\t\t\t" << students->exams[k] << endl
							<< "Средний балл группы:\t\t\t\t\t\t" << course[i].group[j].avr[k] << endl << endl;
						sum = 0;
					}
					ent; ent;
				}
				ent;
				cout << setw(120) << setfill('-');
				cout << " ";
				ent;
			}
			pause;
			break;
		}
		case 3: // smallest and oldest student
		{
			int* year = new int[cnt],
				*mon = new int[cnt],
				*day = new int[cnt];

			int max, min;

			string mask1,
				   mask2;

			string date;

			for (int i = 0; i < cnt; i++)
			{
				date = students->head->date;
				mask1 = date[0];
				mask2 = date[1];
				day[i] = stoi(mask1) * 10 + stoi(mask2);
				mask1 = date[3];
				mask2 = date[4];
				mon[i] = stoi(mask1) * 10 + stoi(mask2);
				mask1 = date[6];
				mask2 = date[7];
				year[i] = stoi(mask1) * 1000 + stoi(mask2) * 100;
				mask1 = date[8];
				mask2 = date[9];
				year[i] += stoi(mask1) * 10 + stoi(mask2);
				if(students->head->next != students->end) 
					students->head = students->head->next;
			}
			students->head = students;
			min = max = 0;

			for (int i = 0; i < cnt; i++)
			{
				if (year[i] >= year[max])
				{
					if (year[i] == year[max])
					{
						if (mon[i] >= mon[max])
						{
							if (mon[i] == mon[max])
							{
								if (day[i] >= day[max])
								{
									max = i;
								}
							}
							else
							{
								max = i;
							}
						}
					}
					else
					{
						max = i;
					}
				}
				if (year[i] <= year[min])
				{
					if (year[i] == year[min])
					{
						if (mon[i] <= mon[min])
						{
							if (mon[i] == mon[min])
							{
								if (day[i] <= day[min])
								{
									min = i;
								}
							}
							else
							{
								min = i;
							}
						}
					}
					else
					{
						min = i;
					}
				}
			}

			for (int i = 0; i < cnt; i++)
			{
				if (max == i)
				{
					cout << "Самый молодой студент:\n\n";
					students->head->GetInfo();
					ent; ent;
				}
				if (min == i)
				{
					cout << "Самый старый студент:\n\n";
					students->head->GetInfo();
					ent; ent;
				}
				students->head = students->head->next;
			}
			students->head = students;
			pause;
			delete[] year;
			delete[] mon;
			delete[] day;
			break;
		}
		case 4: // top
		{
			top();
			pause;
			break;
		}
		case 5: // output
		{
			output();
			pause;
			break;
		}
	
		}

	}

	return 0;
}

void append()
{
	newSt = new Student;
	Student* temp = students->head;
	students->head = newSt;
	temp->next = students->head;
	students->end = students->head;
	students->head->prev = temp;
	students->head = students;
}

void Student::GetInfo()
{
	cout << "Информация о студенте:\n"
		<< "Фамилия:\t\t\t\t\t" << this->LastName << endl
		<< "Имя:\t\t\t\t\t\t" << this->FirstName << endl
		<< "Курс:\t\t\t\t\t\t" << this->course << endl
		 << "Группа:\t\t\t\t\t\t" << this->group << endl
		 << "Дата рождения:\t\t\t\t\t" << this->date << endl << endl
		 << "Оценки по экзаменам:\t\t\t\t\t" << endl;
	ent;
	outArr(this->marks, 5);
	ent;
	ent;
	cout << "Средний балл:\t\t\t\t\t" << this->avr;
	ent;
}

void output()
{
	ent; ent;
	if (students->head == students->end)
	{
		students->head = students;
		return;
	}
	else
	{
		cout << setw(120) << setfill('-');
		cout << " ";
		ent; ent;
		students->head->GetInfo();
		students->head = students->head->next;
		ent; ent;
		output();
	}
}

void sortMethodPuz(Student** arr, int N)
{
	Student* num;
	bool isSorted = false;

	for (int i = 0; i < N; i++)
	{
		if (arr[i]->LastName[0] > arr[i + 1]->LastName[0])
		{
			num = arr[i];
			arr[i] = arr[i + 1];
			isSorted = true;
			arr[i + 1] = num;
		}
		if (N == i + 2)
		{
			if (!isSorted)
				break;
			else
			{
				isSorted = false;
				i = 0;
			}
		}
	}
}

void sortMethodShella(Student** arr, int N)
{
	if (N == 1)
		return;
	Student* num;
	for (int i = 0; i < (cnt - 1); i++)
	{
		sortMethodPuz(arr, N);
	}
	for (int i = 1; i < N; i++)
		for (int j = i; j > 0 && arr[j - 1]->course > arr[j]->course; j--)
		{
			num = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = num;
		}

	arr[0]->next = arr[1];

	for (int i = 1; i < (cnt - 1); i++)
	{
		arr[i]->prev = arr[i - 1];
		arr[i]->next = arr[i + 1];
	}

	arr[cnt - 1]->prev = arr[cnt - 2];
	arr[cnt - 1]->next = students->end;
	students = arr[0];
}

void sort(Student** arr, int N)
{
	if (N == 1)
		return;
	Student* num;
	for (int i = 1; i < N; i++)
		for (int j = i; j > 0 && arr[j - 1]->avr < arr[j]->avr; j--)
		{
			num = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = num;
		}
}


void sort()
{
	Student** arr = new Student*[cnt];
	students->head = students;
	for (int i = 0; i < cnt; i++)
	{
		arr[i] = students->head;
		if(students->head->next != students->end) 
			students->head = students->head->next;
	}
	students->head = students;
	sortMethodShella(arr, cnt);
	students->head = students;
	delete[] arr;
}

void top()
{
	Student** arr = new Student*[cnt];
	int groups[20];
	bool isThere = false;
	for (int i = 0; i < cnt; i++)
	{
		arr[i] = students->head;
		if (students->head->next != students->end)
			students->head = students->head->next;
	}

	students->head = students;

	sort(arr, cnt);
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int m = 0; m < cnt; m++)
			{
				for (int k = 0; k < course[i].group[j].cnt; k++)
				{
					if (arr[m] == course[i].group[j].student[k])
					{
						cout << "Фамилия:\t\t\t\t" << course[i].group[j].student[k]->LastName << endl
							<< "Курс:\t\t\t\t\t" << course[i].group[j].student[k]->course << endl
							<< "Группа:\t\t\t\t\t" << course[i].group[j].student[k]->group << endl
							<< "Средний балл:\t\t\t\t" << course[i].group[j].student[k]->avr << endl << endl << endl;

						k = 1000;
						m = 1000;
					}
				}
			}
		}
	}

	delete[] arr;
}