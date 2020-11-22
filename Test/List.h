#pragma once
template <typename T>
struct Node
{
public:
	Node* pNext;
	T data;
	Node(T _data = T(), Node* _pNext = nullptr) :data(_data), pNext(_pNext) {}
};



template<class T>
class List
{
private:
	int Size = 0;
	Node<T>* head;

public:
	List()
	{
		head = nullptr;
	}

	List(int n, T data)
	{
		Node<T>* head = new Node<T>(data);
		Node<T>* current = head;
		Size++;

		while (n != 1)
		{
			current->pNext = new Node<T>(data);
			current = current->pNext;
			Size++;
			n--;
		}
	}

	~List()
	{
		while (head != (nullptr))
		{
			Node<T>* p = head;
			head = head->pNext;
			delete p;
		}
	}

	Node<T>* Head() { return head; };
	Node<T>* Tail() { return this->operator[](Size-1);};
	void push_front(T data);
	void push_back(T data);
	void pop_front();
	void pop_back();
	T& operator[](const int Index);
	int GetSize() { return Size; };
};

template <typename T>
void List<T>::push_front(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		head = new Node<T>(data);
		head->pNext = current;
	}
	Size++;
}

template <typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = Tail();
		current->next = new Node<T>(data);
	}
	Size++;
}

template <typename T>
void List<T>::pop_front()
{
	if (head != nullptr)
	{
		Node<T>* current = head;
		head = head->pNext;
		delete current;
		Size--;
	}
}

template <typename T>
void List<T>::pop_back()
{
	if (head != nullptr)
	{
		delete Tail();
		Size--;
	}
}

template <typename T>
T& List<T>::operator[](const int Index)
{
	Node<T> *current = this->head;
	int counter = 0;
	while (current != nullptr)
	{
		if (counter == Index)
		{
			return current->data;
		}
		else current = current->pNext;
		counter++;
	}
}