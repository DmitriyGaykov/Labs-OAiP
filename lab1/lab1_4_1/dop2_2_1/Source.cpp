//x3 + x – 3,
//cos3(x)
#include <iostream>
using namespace std;

float func1(float x)
{
	return pow(x,3) + x - 3;
}
float func2(float x) {
	return cos(3*x);
}


float dichotomy_method(float a, float b, float(*func)(float)) {  

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
	cout << dichotomy_method(1, 2, func2);

	return 0;
}

