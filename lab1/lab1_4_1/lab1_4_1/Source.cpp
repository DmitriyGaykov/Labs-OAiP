#include <iostream>
using namespace std;

//x3 + 2x – 1,
//ex - 2

float func1(float x)
{
	return x * x * x + 2 * x - 1;
}

float func2(float x)
{
	return exp(x)-2;
}

float dichotomy_method(float a, float b, float(*func)(float)) 
{
	float x = a, e = 0.001;

	while (abs(a - b) > 2 * e)
	{
		x = (a + b) / 2;
		if (func(x) * func(a) <= 0)
			b = x;
		else
			a = x;
	}
	return x;
}

int main() {

	cout << dichotomy_method(0, 2, func1) << endl;
	cout << dichotomy_method(1, 2, func2) << endl;

	return 0;
}