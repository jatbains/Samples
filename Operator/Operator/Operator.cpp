// Operator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class A 
{
private:
	int age;

public:
	int GetAge() {
		return age;
	}
	void SetAge(int x) {
		age = x;
	}
	A* operator+(const A &a) {
		A *b = new(A);

		b->age = this->age + a.age;
		return b;

	}
};

int main()
{
    return 0;
}

