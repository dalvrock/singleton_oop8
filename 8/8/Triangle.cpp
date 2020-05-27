#include "Triangle.h"
#include <iostream>
#include <cmath>
#include <corecrt_math_defines.h>
#define _USE_MATH_DEFINES

using namespace std;

Triangle* Triangle::instance = nullptr;

Triangle::Triangle(const double a, const double b, const double c)
{
	if (a < 0 ? b < 0 : c < 0)
	{
		throw "Incorrect value !";
	}
	this->a = a;
	this->b = b;
	this->c = c;
}

Triangle::Triangle()
{
	this->a = 0;
	this->b = 0;
	this->c = 0;
}

Triangle* Triangle::Instance(const double a, const double b, const double c)
{
	if (nullptr == Triangle::instance)
	{
		instance = new Triangle(a, b, c);
	}
	return instance;
}

Triangle::~Triangle()
{
	cout << "Destuctor" << endl;
}

double Triangle::GetA() const { return a; }
double Triangle::GetB() const { return b; }
double Triangle::GetC() const { return c; }

void Triangle::SetA(double a)
{
	if (a > 0)
	{
		this->a = a;
	}
}

void Triangle::SetB(double b)
{
	if (b > 0)
	{
		this->b = b;
	}
}

void Triangle::SetC(double c)
{
	if (c > 0)
	{
		this->c = c;
	}
}

double Triangle::Perimeter() const
{
	return (a + b + c);
}

double Triangle::Area() const
{
	return sqrt((((a + b + c) / 2) * ((a + b + c) / 2 - a) * ((a + b + c) / 2 - b) * ((a + b + c) / 2 - c)));
}

void Triangle::operator+=(double n)
{
	this->a = this->a + n;
	this->b = this->b + n;
	this->c = this->c + n;
}

ostream& operator << (ostream& out, const Triangle& obj)
{
	out << "Triangle(" << obj.a << ", " << obj.b << "," << obj.c << ")";
	return out;
}

istream& operator>>(istream& in, Triangle& obj)
{
	cout << "Print a: ";
	in >> obj.a;
	if (obj.a < 0) throw ("Incorrect value of 1st side!");
	cout << "Print b: ";
	in >> obj.b;
	if (obj.b < 0) throw ("Incorrect value of 2nd side!");
	cout << "Print c: ";
	in >> obj.c;
	if (obj.c < 0) throw ("Incorrect value of 3rd side!");
	return in;
}