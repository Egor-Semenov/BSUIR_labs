#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	double a, b, h, y, x, result, chislitel, znamenatel, t = 1, p = 1;
	int n;
	cout << "Vvedite a:";	cin >> a;
	cout << endl;
	cout << "Vvedite b:";	cin >> b;
	cout << endl;
	cout << "Vvedite n:";	cin >> n;
	cout << endl;

	h = (b - a) / 10;
	x = a;
	do
	{
		chislitel = result = znamenatel = 1;

		for (int i = 1; i <= n; i++)
		{
			p *= -1 * pow(x, 2) / 2 * i * (2 * i - 1);
			t = 2 * pow(i, 2);
			result += p * t;
		}

		y = (1 - pow(x, 2) / 2) * cos(x) - x / 2 * sin(x);

		cout << setw(15) << x << setw(15) << y << setw(15) << result << endl;
		x += h;

	} while (x <= b + 0.0001);

	return 0;
}
