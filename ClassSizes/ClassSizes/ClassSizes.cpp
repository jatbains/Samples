// ClassSizes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


class Shape
{
private:
	short point;

public:
	virtual void WhatAmiI();
	virtual int MyArea();
	bool Instantiated();
};

bool Shape::Instantiated()
{
	return true;
}

int Shape::MyArea()
{
	return 0;
}

void Shape::WhatAmiI()
{
	cout << "I am a point" << endl;
}

class Circle : public Shape
{
private:
	int radius;
public:
	int MyArea();
	static bool AmIFlat();
};

int Circle::MyArea()
{
	return (3.14*radius*radius);
}

bool Circle::AmIFlat()
{
	return true;
}

class Square : public Shape
{
private:
	int length;
public:
	int MyArea();
	bool AmIFlat();
};

int Square::MyArea()
{
	return (length*length);
}

bool Square::AmIFlat()
{
	return true;
}

int main()
{
	Shape shape;
	Circle circle;
	Square square;


	cout << "Size of Shape class is " << sizeof(Shape) << endl;
	cout << "Size of Shape is " << sizeof(shape) << endl;
	cout << "Size of Circle class is " << sizeof(Circle) << endl;
	cout << "Size of Circle is " << sizeof(circle) << endl;
	cout << "Size of Square class is " << sizeof(Square) << endl;
	cout << "Size of Square is " << sizeof(square) << endl;



	system("pause");
    return 0;
}

