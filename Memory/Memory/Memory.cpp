// Memory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
typedef struct
{
	int age;
	char name[10];
}Record;

int main()
{
	char mem[20] = { 'a','b','c','d','e','f','g','h' ,'i','j','k','l','m','n'};
	char *p = &mem[0];
	Record employs[10];
	Record *r = employs;
	// print out addresses of elements
	for (int i = 0; i < 20; i++)
	{
		printf("Address is %x Values is %c\n", p, *p);
		p++;
	}
	
	printf("Address os records\n");
	printf("Size of records %d  Sizeof age is %d \n", sizeof(Record),sizeof(r->age));
	for (int i = 0; i < 10; i++)
	{
		printf("Address of records is %x\n", r);
		printf("Adddress of last name char is %x\n", &(r->name[10]));
		r++;
	}


	getchar();
    return 0;
}

