
#include <iostream>

using namespace std;
int main()
{
	int first[5];
	int second[5];
	cout << "Vvedite elementi pervogo massiva :" << endl;
	for (int i = 0; i < 5; i++)
	{
		int c;
		cin >> c;

		first[i] = c;
	}
	cout << "Vvedite elementi vtorogo massiva :" << endl;
	for (int i = 0; i < 5; i++)
	{
		int d;
		cin >> d;
		second[i] = d;
	}

	for (int i = 0; i < 5; i++)
	{
		int schetchik = 0;
		for (int j = 0; j < 5; j++)
		{

			if (first[i] < second[j])
			{
				schetchik++;
			}
			
			if (schetchik == 5)
			{
				cout << first[i] << " ";
			}
		}

	}
	return 0;
}