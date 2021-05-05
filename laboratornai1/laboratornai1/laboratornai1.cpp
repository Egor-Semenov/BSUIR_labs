#include <iostream>
#include <math.h>

using namespace std;
int main()
{
	double x, y, z, s, a, b, c, d;
	cout << "Vvedite x: ";
	cin >> x;
	cout << "Vvedite y: ";
	cin >> y;
	cout << "Vvedite z: ";
	cin >> z;

	a = pow(y, pow(fabs(x), 1 / 3.));
	b = pow(cos(y), 3) * fabs(x - y);
	c = 1 + (pow(sin(z), 2) / sqrt(x + y));
	d = exp(fabs(x - y)) + (x / 2);

	s = a + (b * (c / d));
	cout << "S =" << s;

	return 0;
}