// Classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Car
{
public :
	Car(string color, string make, int year)
	{
		SetColor(color);
		SetMake(make);
		SetYear(year);
	}
	string GetColor()
	{
		return mColor;
	}
	void SetColor(string color)
	{
		mColor = color;
	}
	string GetMake()
	{
		return mMake;
	}
	void SetMake(string make)
	{
		mMake = make;
	}
	int GetYear()
	{
		return mYear;
	}
	void SetYear(int year)
	{
		mYear = year;
	}

private:
	string mColor;
	string mMake;
	int mYear;
};

class ElectricCar : public Car
{
public:
	ElectricCar(string color, string make, int year, int battery)
		: Car(color, make, year)
	{
		SetBattery(battery);
	}
	void SetBattery(int battery)
	{
		mBattery = battery;
	}
	int GetBattery()
	{
		return mBattery;
	}
private:
	int mBattery;


};

int main()
{
	cout << "Create two types of cars " << endl << endl;
	string make("Buick");
	string color("black");

	Car Buick(color,make,2016);
	make.assign("Porsche");
	color.assign("red");
	Car Porsche(color,make, 2010);

	make.assign("Tesla");
	color.assign("Yellow");


	ElectricCar Tesla(color,make,2018,3000);
	// What are the two types of cars
	cout << Buick.GetMake() << "  " << Buick.GetColor() << endl;
	cout << Porsche.GetMake() << "  " << Buick.GetColor() << endl;
	cout << Tesla.GetMake() << "  " << Tesla.GetColor() << endl;

	getchar();
    return 0;
}

