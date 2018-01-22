// ContextTime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;
long func(void);

int main()
{
	time_t myTime;
	time_t conTime;
	time(&myTime);
	cout << "Time before calling " << myTime << endl;

	for (int x = 0; x < 100; x++)
	{
		conTime = func();
	}
	time(&conTime);

	cout << "Context time is " << conTime - myTime << endl;

	system("pause");
    return 0;
}

long func(void)
{
	time_t myTime;
	
	time(&myTime);
	cout << "Time after calling " << myTime << endl;
	// Called function

	return myTime;
}