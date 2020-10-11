#define _CRT_SECURE_NO_WARNING
#include <iostream>
#include <algorithm>
#include <string>
#include "Stack.h"

using namespace std;

string out = "";

void Post(string str)
{
	Stack<char> stk(10);

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ') continue;
		switch (str[i]) {
		case '(':
			stk.Push('(');
			break;
		case ')':
		{
			while (!stk.isEmpty())
			{
				if (stk.Top() != '(')
				{
					out.push_back(stk.Top());
					stk.Pop();
				}
				else break;
			}
			stk.Pop();
		}
		break;
		case '-':
		case '+':
			if (stk.isEmpty()) stk.Push(str[i]);
			else {
				while (!stk.isEmpty())
				{
					if (stk.Top() != '(')
					{
						out.push_back(stk.Top());
						stk.Pop();
					}
					else break;
				}
				stk.Push(str[i]);
			}
			break;
		case '*':
		case '/':
			if (stk.isEmpty()) stk.Push(str[i]);
			else
			{
				while (!stk.isEmpty() || stk.Top() == '*' || stk.Top() == '/')
				{
					if (stk.Top() != '(')
					{
						out.push_back(stk.Top());
						stk.Pop();
					}
					else break;
				}
				stk.Push(str[i]);
			}
			break;
		default: out.push_back(str[i]);
		}
	}
	out.push_back(stk.Top());
}

int Res()
{
	int a;
	int b;
	Stack<int> stk(10);
	for (size_t i = 0; i < out.length(); i++)
	{
		switch (out[i]) {
		case '-':
			b = stk.Top();
			a = stk.Pop() - b;
			stk.Pop();
			stk.Push(a);
			break;
		case '+':
			b = stk.Top();
			a = stk.Pop() + b;
			stk.Pop();
			stk.Push(a);
			break;
		case '*':
			b = stk.Top();
			a = stk.Pop() * b;
			stk.Pop();
			stk.Push(a);
			break;
		case '/':
			b = stk.Top();
			a = stk.Pop() / b;
			stk.Pop();
			stk.Push(a);
			break;
		default: stk.Push((int)out[i] - (int)'0');
		}
	}
	return stk.Top();
}

void main() 
{
		string str = "(2+4) * (4/2-1)*2";
		//remove_if(str.begin(), str.end(), isspace);

		cout << str << endl;
		
		Post(str);

		cout << out << " = " << Res() << endl;

	system("pause");
}