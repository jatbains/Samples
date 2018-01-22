// FileIO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class Car
{
private:
	int numWheels;
	int engineSize;
	static int numCars;
public:
	Car(int nWheels, int esize)
	{
		numWheels = nWheels;
		engineSize = esize;
		Car::numCars++;
	}
	int  GetWheels()
	{
		return numWheels;
	}
	int GetESize()
	{
		return engineSize;
	}
	int NumCars()
	{
		return numCars;
	}
};


int main()
{
	string quote = "The in Spain falls mainly on the plain";
	int myAge = 20;
	ofstream writer;
	writer.open("Quote.txt");

	if (!writer)
	{
		cout << "Error Opening" << endl;
	}
	else
	{
		writer << quote << endl;
	}
	writer.close();

	FILE myFile;
	ifstream inFile;
	inFile.open("Quote.txt");

	cout << "My age address is " << &myAge << endl;

	system("pause");
    return 0;
}

