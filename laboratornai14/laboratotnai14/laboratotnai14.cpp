#include <iostream>


using namespace std;


struct stack_element {
	int inf;
	stack_element* next;
	stack_element* min_element_position;
};

struct Stack
{
	stack_element* top = nullptr;
	int stack_size = 0;

	bool empty()
	{
		if (top)	return false;
		else return true;
	}

	stack_element* AddStack(int inf)
	{
		stack_element* spt = new stack_element;
		spt->inf = inf;
		spt->next = top;
		top = spt;
		stack_size++;
		return top;
	}

	void pop()
	{
		stack_element* spt = top;
		top = top->next;
		delete spt;
		stack_size--;
	}

	
	stack_element* Delete_elements()
	{
		stack_element* tmp = top;
		stack_element* spt = new stack_element;
		int min_element = 0;
		

		if (tmp != 0 && tmp->next == nullptr)
		{
			min_element = tmp->inf;
		}

		else
		{
			while (tmp)
			{
				if (tmp->inf < min_element)
				{
					min_element = tmp->inf;
					spt = tmp;

				}
				tmp = tmp->next;
			}
		}
		
		while (top != spt && top->next != nullptr)
		{
			stack_element* skr = top;
			top = top->next;
			delete skr;
			stack_size--;
		}
		return nullptr;
	}

	void print() 
	{
		stack_element* spt = top;
		while (spt != nullptr)
		{
			cout << spt->inf << " ";
			spt = spt->next;
		}
	}
};

int main()
{
	Stack s;
	int n;
	int k;

	cout << "Enter the number of stack elements:";
	cin >> n;
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << " Enter element:";
		cin >> k;
		s.AddStack(k);
	}
	s.print();
	cout << endl;
	s.Delete_elements();
	s.print();
	s.pop();
}