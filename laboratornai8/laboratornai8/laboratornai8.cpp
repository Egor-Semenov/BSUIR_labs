
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef double(*uf)(double, double, int& k);

void tabl(double, double, double, double, uf);

double y(double, double, int&);
double s(double, double, int&);

int main()
{

	cout << setw(8) << "x" << setw(15) << "y(x)" << setw(10) << "k" << endl;
	tabl(-1, 1.3, 0.5, 0.00001, y);
	cout << endl;
	cout << setw(8) << "x" << setw(15) << "s(x)" << setw(10) << "k" << endl;
	tabl(-1, 1.3, 0.5, 0.00001, s);

	return 0;
}

void tabl(double a, double b, double h, double eps, uf fun)
{
	int k = 0;
	double sum;

	for (double x = a; x <= (b + h / 2); x += h)
	{
		sum = fun(x, eps, k);
		cout << setw(8) << x << setw(15) << sum << setw(10) << k << endl;
	}

}

double y(double x, double eps, int &k)
{
	double y_function = (2 * x * sin(x) - 2 + cos(x)) / 4;
	return y_function;
}

double s(double x, double eps, int& k)
{
	double sum, colculation;
	sum = 0;
	colculation = 1;
	k = 0;
	int n = 2;

	while (fabs(colculation) > eps)
	{
		colculation =  pow(-1,n+1)*cos(n * x) / (pow(n, 2) - 1);
		
		sum += colculation;
		n++;
		k++;
	}

	return sum;
}