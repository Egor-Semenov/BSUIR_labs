#include <iostream>
#include <cmath>

using namespace std;

double sol(int, double);
double solr(int, double);

int main()
{
	double x;
	cout << "Vvedite x: ";
	cin >> x;

	int n;
	cout << "Vvedite n: ";
	cin >> n;

	cout << "s (ne rekurs) = " << sol(n, x) << endl;
	cout << "s (rekurs) = " << solr(n, x) << endl;
	return 0;
}

double sol(int n, double x)
{
	double s = 1;
	for (int i = 1; i <= n; i++)
	{
		s *= x;
	}

	return s;
}

double solr(int n, double x)
{
	if (n == 0)		return 1;
	else if (n == 1)		return x;
	else if (n % 2 == 0)
	{
		return pow(solr(n / 2, x), 2);
	}
	else if (n % 2 == 1)
	{
		return x * solr(n - 1, x);
	}
}
