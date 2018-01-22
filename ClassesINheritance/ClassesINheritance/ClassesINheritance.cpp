// ClassesINheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

const static int MAX_STRING = 20;

class Vehicle
{
	string make;
	int    year;
	string color;

public:
	Vehicle(string make,int year,string color);
	virtual string GetMake();
	virtual int GetYear();
	virtual string GetColor();
	virtual void TypeOfVehicle();
};

Vehicle::Vehicle(string make, int year, string color)
	:make(make),
	year(year),
	color(color) {
	cout << "Vehicle constructor" << endl; }


string Vehicle::GetColor()
{
	cout << "Color is " << color << endl;
	return color;
}

void Vehicle::TypeOfVehicle()
{
	cout << "This is a generic vehicle" << endl;
}
string Vehicle::GetMake()
{
	cout << "Make is " << make << endl;
	return make;
}

int Vehicle::GetYear()
{
	cout << "Year is " << year << endl;
	return year;
}

class Car : public Vehicle
{
	bool isSedan;
	int doors;

public:
	Car(string make, int year, string color, bool isSedan, int doors);
	void TypeOfVehicle();

};

Car::Car(string make, int year, string color,bool isSedan, int doors)
	:Vehicle(make,year,color),
	isSedan(isSedan),
	doors(doors) 
{
	cout << "Car constructor" << endl;
}

void Car::TypeOfVehicle()
{
	cout << "This is a car" << endl;
}

class Truck : public Vehicle
{
	int wheels;
	int weight;

public:
	Truck(string make, int year, string color, int wheels, int weight);
	void TypeOfVehicle();

};
void Truck::TypeOfVehicle()
{
	cout << "This is a truck" << endl;
}

Truck::Truck(string make, int year, string color, int wheels, int weight)
	:Vehicle(make, year, color),
	wheels(wheels),
	weight(weight) 
{
	cout << "Truck Constructor" << endl;
};


int main()
{
	Car jtCar("bmw", 2015, "black", true, 4);

	Truck pTruck("volvo", 2003, "blue", 10, 10000);

	Truck *bTruck = new Truck("Perter", 2006, "red", 10, 15000);   // Create this on the heap

	cout << endl << endl;

	Vehicle *pV = &jtCar;

	pV->TypeOfVehicle();
	pV->GetColor();
	pV->GetMake();
	pV->GetYear();
	cout << endl << endl;
	Vehicle *pT = &pTruck;

	pT->TypeOfVehicle();
	pT->GetColor();
	pT->GetMake();
	pT->GetYear();

	delete(bTruck);

	system("pause");
    return 0;
}

