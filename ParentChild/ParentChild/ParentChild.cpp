// ParentChild.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

typedef enum Car 
{
	BMW,
	Toyota,
	Mercedes,
	Honda,
	Ford
}Car;

typedef struct Node {

	enum Car myCar;
	int year;
	struct Node *child;

}Node;

Node *AllocCarType(Car myCar, int year);
Node * InsertCar(Node *head, Car type, int year);
void PrintCars(Node *head);

int main()
{
	Node *head=NULL;
	// Add some cars
	head = InsertCar(head, Toyota, 2000);
	head = InsertCar(head, BMW, 2017);
	head = InsertCar(head, Mercedes, 2013);
	head = InsertCar(head, Ford, 2010);

	PrintCars(head);

	system("pause");
    return 0;
}

void PrintCars(Node *head)
{
	Node *temp = head;

	while (temp != NULL)
	{
		cout << temp->myCar << " " << temp->year << endl;
		temp = temp->child;
	}


}

Node * InsertCar(Node *head, Car type, int year)
{
	if (head == NULL)
	{
		head = AllocCarType(type, year);
		return head;
	}
	// Check the list
	Node *temp = head;

	while (temp->child != NULL)
	{
		temp = temp->child;
	}
	temp->child = AllocCarType(type, year);  // head remains unchanged !!!!!!!
	return head;
}

Node *AllocCarType(Car  myCar,int year)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->myCar = myCar;
	temp->year = year;
	temp->child = NULL;
	return temp;
}