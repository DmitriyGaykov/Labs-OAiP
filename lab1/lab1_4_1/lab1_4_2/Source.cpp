//Написать функцию days с переменным числом параметров, которая находит количество
//дней, про - шедших между двумя датами(параметрами функции являются даты в формате «дд.мм.гг».

#include <iostream>

using namespace std;

int days(int datesNum, ...);

int main()
{
	setlocale(LC_ALL, "ru");
	days(2, 151003, 300104);
	days(3, 110212, 230413, 300104);
	days(5, 021224, 301244, 010343, 220522, 010101);
}

int days(int n, ...)
{
	int* pN = &n + 1;

	int* dates = new int[n],
		* days = new int[n];

	for (int i = 0; i < n; i++)
	{
		dates[i] = *(pN + i);
	}

	for (int i = 0; i < n; i++)
	{
		int el = dates[i],
			ostatok;

		short counter = 0;

		days[i] = 0;

		for (int j = 0; j < 6; j+=2)
		{
			ostatok = el % 100;
			el /= 100;
			counter++;

			if (counter == 1)
			{
				days[i] += 365 * ostatok;
			}

			else if (counter == 2)
			{
				days[i] += 30 * ostatok;
			}

			else if (counter == 3)
			{
				days[i] += ostatok;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if( i + 1 != n)
			cout << "Промежуток между " << i + 1 << " и " << i + 2 << " датами - " << abs(days[i] - days[i + 1]) << endl;
	}

	cout << endl << endl;

	delete[] dates;
	delete[] days;
	return 0;
}