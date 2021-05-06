#include <iostream>
#include <string>

using namespace std;
int main()
{
	struct Vedomosti
	{
		char surname[40];
		char adress[40];
		int exam_marks[4];
		double Average_mark;
	} *students;

	int Number_of_students;
	cout << "Vvedite kolvo studentov:";
	cin >> Number_of_students;
	students = new Vedomosti[Number_of_students];

	double t = 0;
	char f[40];
	char a[40];

	for (int i = 0; i < Number_of_students; i++)
	{
		cout << "Vvedite surname" << endl;
		cin >> (students[i].surname);

		cout << "Vvedite adress" << endl;
		cin >> students[i].adress;
		
		cout << "Vvedite marks for exam" << endl;
		students[i].Average_mark = 0;
		for (int j = 0; j < 4; j++)
		{
			cout << "Exam " << j + 1 << " :";
			cin >> students[i].exam_marks[j];
			cout << endl;
			students[i].Average_mark += students[i].exam_marks[j] / 4;
		}
	}

	
	for (int i = 0; i < Number_of_students - 1; i++)
	{
		if (strcmp(students[i].surname, students[i + 1].surname) > 0)
		{
			strcpy_s(f, students[i].surname);
			strcpy_s(students[i].surname, students[i + 1].surname);
			strcpy_s(students[i + 1].surname, f);

			strcpy_s(a , students[i].adress);
			strcpy_s(students[i].adress , students[i + 1].adress);
			strcpy_s(students[i + 1].adress , a);

			t = students[i].Average_mark;
			students[i].Average_mark = students[i + 1].Average_mark;
			students[i + 1].Average_mark = t;
		}
	}
	cout << "spisok:" << endl;
	for (int i = 0; i < Number_of_students; i++)
	{
		if ((students[i].Average_mark >= 4.5) && ((strcmp(students[i].adress, "minsk") == 0) || (strcmp(students[i].adress, "Minsk") == 0)))
			cout << students[i].surname << endl;;
	}
	delete[] students;
}