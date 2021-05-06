
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main()
{
	double x, y, a, function, result;
	int nomer_function;

	cout << "Vvedite x : ";
	cin >> x;
	cout << "Vvedite y : ";
	cin >> y;
	cout << "Vibirite fuction: 1.sh(x), 2.x^2, 3.exp(x)" << endl;
	cout << "function : ";
	cin >> nomer_function;

	switch (nomer_function)
	{
	case 1: function = sinh(x);		break;
	case 2: function = pow(x, 2);	break;
	case 3: function = exp(x);		break;
	default: cout << "Ne vibrana function";		return 1;
	}

	a = x * y;

	if (a > 0)
	{
		result = tan(function) + x / cbrt(y);
	}
	else if (a < 0)
	{
		result = log(fabs(pow(function, 2) * y));
	}
	else
	{
		result = pow(function, 2) + pow(sin(y), 2);
	}

	cout << "Result = " << result << endl;
	return 0;
}
