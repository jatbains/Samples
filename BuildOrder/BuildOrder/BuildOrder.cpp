// BuildOrder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int const static MAX_PROJECTS = 6;


typedef struct Build
{
	char projects[MAX_PROJECTS]= { 'a','b','c','d','e','f' };
	int dependencies[MAX_PROJECTS][MAX_PROJECTS];
	
}Build;

int main()
{
	Build myBuild;
	int Dependencies[MAX_PROJECTS][MAX_PROJECTS]= { {0,0,0,1,0,0},
						                                {0,0,0,1,0,0},
						                                {0,0,0,0,0,0},
						                                {0,0,1,0,0,0},
						                                {0,0,0,0,0,0},
						                                {1,1,0,0,0,0} };
	
	



	system("pause");
    return 0;
}

