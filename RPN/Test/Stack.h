template <class T>

class Stack
{
public:
	Stack(int size);
	~Stack();

	T Top();
	void Push(T a);//�������� �������
	T Pop();//������� � ������� ������� �������
	bool isEmpty();//�������� �� �������
	void Print();//������� ����
private:
	T* arr;
	int size;
	T top;
};

template <class T>
Stack<T>::Stack(int s)
{
	size = s;
	arr = new T[size];
	top = -1;
}

template <class T>
Stack<T>::~Stack()
{
	delete[]arr;
}

template <class T>
T Stack<T>::Top()
{
	if (top == -1)
	{
		return 0;
	}
	else
	{
		return arr[top];
	}
}

template <class T>
void Stack<T>::Push(T a)
{
	if (top == size - 1)
	{
		cout << "Overlouded!";
		throw 1;
	}
	top++;
	arr[top] = a;

}

template <class T>
bool Stack<T>::isEmpty()
{
	if (top == -1)//������
		return true;
	else return false;
}

template <class T>
T Stack<T>::Pop()
{
	if (top == -1)
	{
		return 0;
	}
	arr[top] = 0;
	top--;
	return arr[top];
}

template <class T>
void Stack<T>::Print()
{
	for (int i = 1; i < size; i++)
	{
		cout << arr[i] << " ";
	}

}