#include <iostream>
#include "Triangle.h"

using namespace std;

int main()
{
	Triangle* ABC = Triangle::Instance(5.5, 6.4, 7.2);
	Triangle* DEF = Triangle::Instance(10, 20, 30);

	cout << "*ABC: " << *ABC << endl;
	cout << "*DEF: " << *DEF << endl;
}
