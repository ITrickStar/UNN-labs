# Deus Vult
 Don't waste your time
Миххев Иван Алексеевич
ФИИТ-3
#include <iostream>

using namespace std;

template <class T>
class node
{
public:
	T value;
	node<T>* next;
};

template <class T>
class List
{
	node <T>* first;
public:
	List()
	{
		first = NULL;
	}
	List(T L)
	{
		first = new node();
		first->value = L;
		first->next = NULL;
	}
	~List()
	{
		node <T>* second;
		while (first != NULL)
		{
			second = first;
			first = second->next;
			delete second;
		}
	}

	void add(T value)
	{
		node <T>* second;
		second = new node<T>;
		second->value = value;
		second->next = first;
		first = second;
	}

	void addlist(List <T> L)
	{
		node *c = first;
		while (true)
			if (c->next == NULL) break;
			else L = c -> next;
		c.next = L.first;
	}
};



int main()
{
	List<int> arr;
	arr.add(5);

	system("pause");
	return 0;
}
