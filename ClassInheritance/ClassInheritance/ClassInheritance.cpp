// ClassInheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Shape
{
private:
	string color;
protected:
	bool isTwoDim;
public:
	Shape(string color,bool is2D);
	~Shape();
	virtual void WhoAmI();
	virtual int Area() = 0;
	virtual int Volume() = 0;
};
Shape::Shape(string color, bool is2D)
	:isTwoDim(is2D)
{
	this->color = color;
	cout << "Shape constructor" << endl;
}

Shape::~Shape()
{
	cout << "Destructor ";
	WhoAmI();
}

void Shape::WhoAmI()
{
	cout << "I am a Shape" << endl;
}

class Circle : public Shape
{
private:
	int radius;
public:
	Circle(int radius);
	~Circle();
	void WhoAmI();
	int Area();
	int Volume();
};

Circle::Circle(int radius)
	: radius(radius),
	Shape("blue",true)
{
	cout << "Circle constructor" << endl;
}

Circle::~Circle()
{
	cout << "Destructor ";
	WhoAmI();
}
void Circle::WhoAmI()
{
	cout << "I am a Circle" << endl;
}
int Circle::Area()
{
	return (3.14*radius*radius);
}

int Circle::Volume()
{
	return -1;
}

class Square : public Shape
{
private:
	int length;
public:
	Square(int len);
	~Square();
	void WhoAmI();
	int Area();
	int Volume();
};
Square::Square(int length)
	:length(length),
	Shape("red", true)
{
	cout << "Square constructor" << endl;
}
Square::~Square()
{
	cout << "Destructor ";
	WhoAmI();
}

void Square::WhoAmI()
{
	cout << "I am a Square" << endl;
}

int Square::Area()
{
	return (length*length);
}

int Square::Volume()
{
	return -1;
}

int main()
{
	//class Shape *shape;

	
	class Circle *myCircle = new Circle(25);
	cout << endl;
	class Square *mySquare = new Square(10);

	cout << endl;
	delete myCircle;
	cout << endl;

	delete mySquare;

	system("pause");
    return 0;
}

