// Threads.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <mutex>


using namespace std;
mutex mtx;

void Name(int i)
{
	mtx.lock();
	
	cout << "My name is Thread " << i << endl;
	mtx.unlock();
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



