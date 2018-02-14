// Threads.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>


using namespace std;
mutex mtx;
static int index = 0;

void Name(int i)
{

	while (index<100)
	{
		mtx.lock();
		cout << "My name is Thread " << i << endl;
		index++;
		mtx.unlock();
	}
}

int main()
{

	thread t1(Name,1);
	thread t2(Name,2);

	t1.join();
	t2.join();
	system("pause");
    return 0;
}



