
#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	int max;
	int jmax;
	int min;
	int jmin;
	

	int rows;
	cout << "Vvedite kolichestvo rows:";
	cin >> rows;
	cout << endl;

	int cols;
	cout << "Vvedite kolichestvo colomns:";
	cin >> cols;

	cout << "Vvedite elementi massiva" << endl;

	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "arr[" << i << "][" << j << "]:";
			cin >> arr[i][j];
			cout << endl;
		}
	}

	for (int i = 0; i < rows; i++)
	{
		min = arr[i][0];
		jmin = 0;

		for (int j = 1; j < cols; j++)
		{
			if (arr[i][j] < min) { min = arr[i][j];	jmin = j; }
		}

		bool bp = true;
		for (int k = 0; k < rows; k++)
		{
			if (arr[k][jmin] > min) { bp = false;	break; }
		}
		if (bp)		cout << "Row:" << i << setw(15) << "Colomn:" << jmin << endl;

		max = arr[i][0];
		jmax = 0;

		for (int j2 = 1; j2 < cols; j2++)
		{
			if (arr[i][j2] > max) { max = arr[i][j2];	jmax = j2; }
		}

		bool bp2 = true;
		for (int k2 = 0; k2 < rows; k2++)
		{
			if (arr[k2][jmax] < max) { bp2 = false;	break; }
		}

		if (bp2)		cout << "Row:" << i << setw(15) << "Colomn:"  << jmax << endl;
	}
	return 0;
}
