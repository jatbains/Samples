// VirtualFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

class Person
{
public:
	virtual void  Occupation(void){
		cout << " I am a person " << endl;
	}
};

class Student : public Person
{
public:
	void Occupation(void)
	{
		cout << "I am a Student " << endl;
	}
};

class Teacher : public Person
{
public:
	void Occupation(void) {
		cout << "I am a Teacher " << endl;
	}


};

int main()
{
	Person *s = new Student;


	Person *t = new Teacher;

	s->Occupation();
	cout << endl << endl;
	t->Occupation();



	system("pause");

    return 0;
}

