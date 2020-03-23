#define _CRT_SECURE_NO_WARNING
#include <iostream>
#include <conio.h>
using namespace std;

class Vector
{
	int m_x;
	int m_y;
	int m_z;

public:
	Vector():
		m_x(0),
		m_y(0),
		m_z(0)
	{
		cout << "DEFAULT V " << this << endl;
	} //Конструктор по умолчанию

	Vector(int _x, int _y, int _z) :
		m_x(_x),
		m_y(_y),
		m_z(_z)
	{
		cout << "WRITING V " << this << endl;
	} // Конструктор своих значений

	Vector(const Vector &other) :
		m_x(other.m_x),
		m_y(other.m_y),
		m_z(other.m_z)
	{
		cout << "COPY V " << this << endl;
	} // Конструктор копирования

	Vector & operator= (const Vector &other)
	{
		cout << "Operator= V " << this << endl;
		this->m_x = other.m_x;
		this->m_y = other.m_y;
		this->m_z = other.m_z;

		return *this;
	} // Перегрузка присваивания

	friend void printV(Vector other); //делаем доступ к приватным переменным

};

void printV (Vector other)
{
	cout << "(" << other.m_x << "," << other.m_y << "," << other.m_z << ")" << endl;
}



class Matrix
{
	int** arr;
	int m_column;
	int m_row;

public:
	Matrix() :
		arr(nullptr),
		m_column(0),
		m_row(0)
	{
		cout << "DEFAULT M " << this << endl;
	} //Конструктор по умолчанию

	Matrix(int _column, int _row) :
		m_column(_column),
		m_row(_row)
	{
		arr = new int* [m_row];
		for (int count = 0; count < m_row; count++) {
			arr[count] = new int[m_column];
		}

		for (int i = 0; i < m_row; i++)
		{
			for(int j = 0; j < m_column; j++)
			arr[i][j] = rand() % 10;
			cout << arr[i] << " ";
		}

		cout << "WRITING M " << this << endl;
	} // Конструктор своих значений

	Matrix(const Matrix& other) :
		m_column(other.m_column),
		m_row(other.m_row)
	{

		arr = new int*[m_row];
		for (int count = 0; count < m_row; count++) {
			arr[count] = new int[this->m_column];
		}

		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_column; j++)
		{
			arr[i][j] = other.arr[i][j];
		}

		cout << "COPY M " << this << endl;
	} // Конструктор копирования

	Matrix & operator= (const Matrix &other)
	{
		cout << "Operator= M " << this << endl;

		if (this->arr != nullptr)
		{
			for (int count = 0; count < m_row; count++)
				delete[] this->arr[count];
		}

		this->m_column = other.m_column;
		this->m_row = other.m_row;

		arr = new int*[this->m_row];
		for (int count = 0; count < this->m_row; count++) {
			arr[count] = new int[this->m_column];
		}

		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_column; j++)
			{
				this->arr[i][j] = other.arr[i][j];
			}

		return *this;
	} // Перегрузка присваивания

	~Matrix()
	{
		for (int count = 0; count < m_row; count++)
			delete[] this->arr[count];
	}

	friend void printM (Matrix other);

};

void printM(Matrix other)
{
	cout << other.arr[0][0];

	for (int i = 0; i < other.m_row; i++) {
		cout << "\n";
		for (int j = 0; j < other.m_column; i++)
			cout << other.arr[i][j] << " ";
	}
}

void main()
{
	Vector a(9, 1, 1);
	Vector b(1, 0, 0);

	printV(a);

	a = b;

	printV(a);

	Matrix c(1, 1);
	Matrix d(2, 2);

	printM(c);

	c = d;

	printM(c);

	system("pause");
}