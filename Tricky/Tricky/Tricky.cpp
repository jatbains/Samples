// Tricky.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;


struct marks {
	int p : 3;
	int c : 3;
	int m : 2;
};

int main()
{
	int x = 5;
	int *y = 0;
	struct marks s = { 2,-6,5 };
	printf("%d %d %d\n", s.p, s.c, s.m);

	y = (int *)malloc(sizeof(int));

	cout << "Address of x on stack is " << &x << " Address of y on heap is " << y << endl;

	getchar();
    return 0;
}

