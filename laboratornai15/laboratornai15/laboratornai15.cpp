#include <iostream>

using namespace std;
struct List_elements {
	char inf;
	List_elements* next;
	List_elements* prev;
};

struct List {
	List_elements* head = nullptr;
	List_elements* tail = nullptr;

	bool empty()
	{
		if (head)	return false;
		else return true;
	}

	void push(char inf)
	{
		List_elements* tmp = new List_elements;
		tmp->inf = inf;
		tmp->next = nullptr;

		if (!head)
		{
			tmp->prev = nullptr;
			head = tail = tmp;
			return;
		}

		tail->next = tmp;
		tmp->prev = tail;
		tail = tmp;

	}

	void print()
	{
		List_elements* tmp = head;
		while (tmp != nullptr)
		{
			cout << tmp->inf << " ";
			tmp = tmp->next;
		}
	}

	void Delete()
	{
		List_elements* tmp = head;
		head = head->next;
		delete tmp;

		if (!head)
		{
			tail = nullptr;
		}
		else
		{
			head->prev = nullptr;
		}
	}

	void sort()
	{
		for (List_elements* spt = head->next; spt != nullptr; spt = spt->next)
		{
			for (List_elements* tmp = head; tmp != nullptr; tmp = tmp->next)
			{
				if (tmp->inf > spt->inf)		swap(tmp->inf, spt->inf);
			}
		}
		
	}
};

int main()
{
	List List1;
	List List2;
	List List3;

	char FirstListElement;
	char SecondListElement;
	int FirstListSize;
	int SecondListSize;
	cout << "Enter the number of list1 elements:";
	cin >> FirstListSize;

	for (int i = 0; i < FirstListSize; i++)
	{
		cout << "Enter the list element:";
		cin >> FirstListElement;
		List1.push(FirstListElement);
	}

	List1.print();

	cout << endl;

	cout << "Enter the number of list2 elements:";
	cin >> SecondListSize;

	for (int i = 0; i < SecondListSize; i++)
	{
		cout << "Enter the list element:";
		cin >> SecondListElement;
		List2.push(SecondListElement);
	}

	List2.print();

	cout << endl;

	for (List_elements* pointer = List1.head; pointer != nullptr; pointer = pointer->next)
	{
		List3.push(pointer->inf);
	}
	
	for (List_elements* pointer = List2.head; pointer != nullptr; pointer = pointer->next)
	{
		List3.push(pointer->inf);
	}

	List3.sort();
	
	cout << "sorted List3:";
	List3.print();

	List1.Delete();
	List2.Delete();
	List3.Delete();

	cout << endl;
	List3.print();
	return 0;
}