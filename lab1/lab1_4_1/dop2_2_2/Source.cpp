//Написать функцию fsum с переменным числом
//параметров, в которой определяется сумма
//чисел типа int по формуле :
//S = a1 * a2 + a2 * a3 + a3 * a4 + . . . .

#include <iostream>
using namespace std;

int fsum(int n, ...);

void main() 
{
	cout << fsum(2, 2, 5) << endl;
	cout << fsum(3,4, 2, 5) << endl;
	cout << fsum(4, 2, 5, 10, 23) << endl;

}

int fsum(int n, ...) 
{
	int s = 0;
	int* a = &n;
	int* arr = new int[n];

	for (int i = 1; i <= n; i++)
		arr[i - 1] = *(a + i);
	
	for (int i = 0; i < n; ) 
	{

		if (i + 1 > n)
		{
			break;
		}
		else
		{
			s += arr[i] * arr[1 + i++];
		}
	}

	delete[]arr;
	return s;
}