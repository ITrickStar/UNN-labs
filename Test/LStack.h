#pragma once
#include "List.h"

template<class T>
class LStack
{
public:
	List<T> S;

	int Size()
	{
		return S.GetSize();
	}

	void Push(T data)
	{
		S.push_back(data);
	}

	void Pop()
	{
		S.pop_front();
	}

	void Print()
	{
		cout << "Your List: " << endl;
		cout << S.GetSize() << endl;

		for (int j = 0; j < S.GetSize(); j++)
		{
			cout << S[j]->data << " ";
		}

		cout << endl;
	}
};