#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

class Except
{
private:
	int err;
	string txt[2] = { "Index out of range", "Wrong values" };
public:
	static const int indexOutOfRangeException = 0;
	static const int wrongValue = 1;

	Except(int _err) : err(_err) {};
	//string text() { return txt[err]; };
	string text() { return txt[err]; };
	friend ostream& operator<< (ostream& stream, const Except ex);
};

ostream& operator<< (ostream &stream, Except ex)
{
	return stream << ex.text() << endl;;
}



class Shape
{
public:
	virtual double area() const = 0;
};

class Square : public Shape
{
public:
	Square(double size = 1.0) :
		_side(size)
	{
	}

	virtual double area() const
	{
		cout << "Площадь квадрата = ";
		return _side * _side;
	}

private:
	double _side;
};


class Triangle : public Shape
{
public:
	Triangle(double side_a = 3.0, double side_b = 4.0, double side_c = 5.0) :
		_side_a(side_a),
		_side_b(side_b),
		_side_c(side_c)
	{
	}

	virtual double area() const
	{
		double p = (_side_a + _side_b + _side_c) / 2.0;

		cout << "Площадь треугольника = ";

		return sqrt(p * (p - _side_a) * (p - _side_b) * (p - _side_c));
	}

private:
	double _side_a;
	double _side_b;
	double _side_c;
};

class Rectangle : public Shape
{
public:
	Rectangle(double side_a = 3.0, double side_b = 4.0) :
		_side_a(side_a),
		_side_b(side_b)
	{
	}

	virtual double area() const
	{
		cout << "Площадь Прямоугольника = ";

		return _side_a * _side_b;
	}

private:
	double _side_a;
	double _side_b;
};

class Circle : public Shape
{
	static const double Pi;

public:
	Circle(double radius = 1.0) :
		_radius(radius)
	{
	}

	virtual double area() const
	{
		cout << "Площадь круга = ";

		return Pi * _radius * _radius;
	}

private:
	double _radius;
};

const double Circle::Pi = 3.14159265358979323;



int main()
{
	setlocale(LC_ALL, "Russian");

	vector< Shape* > shapes;
	size_t choise;

	do
	{
		cout << "Меню" << endl
			<< "1. Создать квадрат" << endl
			<< "2. Создать треугольник" << endl
			<< "3. Создать круг" << endl
			<< "4. Создать прямоугльник" << endl
			<< "5. Рассчитать площади созданных фигур и выйти" << endl;
		cin >> choise;

		switch (choise)
		{
		case 1:
		{
			try
			{
				double side;

				cout << "Квадрат:" << std::endl;
				cout << "Введите длину стороны: ";
				cin >> side;

				if (side > 0)
				{
					shapes.push_back(new Square(side));
					cout << "Рисуется квадрат " << std::endl;
				}
				else throw Except(Except::wrongValue);
			}

			catch (Except& exception)
			{
				cout << exception << endl;
			}

			break;
		}

		case 2:
		{
			try
			{
				double side_a, side_b, side_c;

				cout << "Треугольник:" << std::endl;
				cout << "Введите длину стороны a: ";
				cin >> side_a;
				cout << "Введите длину стороны b: ";
				cin >> side_b;
				cout << "Введите длину стороны c: ";
				cin >> side_c;

				if (side_a > 0 && side_b > 0 && side_c > 0)
				{
					shapes.push_back(new Triangle(side_a, side_b, side_c));
					cout << "Рисуется треугольник " << std::endl;
				}
				else throw Except(Except::wrongValue);
			}

			catch (Except& exception)
			{
				cout << exception << endl;
			}

			break;
		}

		case 3:
		{
			try
			{
				double rad;

				cout << "Круг:" << endl;
				cout << "Введите длину радиуса: ";
				cin >> rad;

				if (rad > 0)
				{
					shapes.push_back(new Circle(rad));
					cout << "Рисуется круг " << endl;
				}
				else throw Except(Except::wrongValue);
			}

			catch (Except& exception)
			{
				cout << exception << endl;
			}

			break;
		}
		case 4:
		{
			try
			{
				double side_a, side_b;

				cout << "Прямоугольник:" << endl;
				cout << "Введите длину стороны a: ";
				cin >> side_a;
				cout << "Введите длину стороны b: ";
				cin >> side_b;

				if (side_a > 0 && side_b > 0)
				{
					shapes.push_back(new Rectangle(side_a, side_b));
					cout << "Рисуется прямоугольник " << endl;
				}
				else throw Except(Except::wrongValue);
			}

			catch (Except& exception)
			{
				cout << exception << endl;
			}

			break;
		}

		case 5:
		{
			size_t size = shapes.size();

			for (size_t i = 0; i < size; ++i)
				cout << shapes[i]->area() << std::endl;

			break;
		}

		default:
		{
			throw Except(Except::indexOutOfRangeException);

			break;
		}
		};
	} while (choise != 5);

	size_t size = shapes.size();

	for (size_t i = 0; i < size; ++i)
		delete shapes[i];

	system("pause");
	return 0;
}