#pragma once
#include <iostream>

using namespace std;


class Triangle
{
private:

	double a, b, c;
	static  Triangle* instance;

	Triangle();
	Triangle(double, double, double);

public:
	
	static Triangle* Instance(const double a, const double b, const double c);
	
	~Triangle();

	double GetA() const;
	double GetB() const;
	double GetC() const;

	void SetA(double a);
	void SetB(double b);
	void SetC(double c);

	double Perimeter() const;
	double Area() const;

	void operator += (double);
	friend ostream& operator << (ostream& out, const Triangle& obj);
	friend istream& operator >> (istream& in, Triangle& obj);

};

