// Intersection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
typedef struct Point {
	int x;
	int y;
}Point;

int main()
{
	// Intersection of two lines Represent as 2d array

	Point L1[2];
	Point L2[2];
	double SL1;
	double SL2;
	
	L1[0].x = 5;
	L1[0].y = 1;
	L1[1].x = 10;
	L1[1].y = 4;

	L2[0].x = -3;
	L2[0].y = -12;
	L2[1].x = 4;
	L2[1].y = 8;

	// See if L1 and L2 intersect
	// Lines intersect if they have a common point 
	// Find slope of two lines
	SL1 = (float)(L1[1].x - L1[0].x) / (L1[1].y - L1[0].y);
	SL2 = (float)(L2[1].x - L2[0].x) / (L2[1].y - L2[0].y);

	// Check for Parallel


	system("pause");
    return 0;
}
void CheckParallel(float s1, float s2)
{
	if (s1 == s2)
		cout << "Lines are Parallel" << endl;
}


