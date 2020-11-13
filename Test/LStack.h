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
class LStack
{
private:
	int Size = 0;
	Node<T>* head;

public:
	LStack()
	{
		head = nullptr;
	}

	LStack(int n, T data)
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

	~LStack()
	{
		while (head != (nullptr))
		{
			Node<T>* p = head;
			head = head->pNext;
			delete p;
		}
	}

	Node<T>* Head() { return head; };
	void push(T data);
	void pop();
	T& operator[](const int Index);
	int GetSize() { return Size; };
};

template <typename T>
void LStack<T>::push(T data)
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
void LStack<T>::pop()
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
T& LStack<T>::operator[](const int Index)
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