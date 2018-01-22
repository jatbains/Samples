// AllignMalloc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
void* allign_malloc(size_t bytes, size_t align);


int main()
{
	void *address = NULL;

	address = allign_malloc(10000, 64);

	cout << "The address is " << address << endl;

	system("pause");
    return 0;
}

void* allign_malloc(size_t bytes, size_t align)
{
	// Allocate memory alligned on align boundary
	// That is the address is divisible by align
	// address % align = 0  
	void *p1 = NULL;
	void *p2 = NULL;
	int offset = align - 1 + sizeof(void*);  // Memory for void * pointer
	if ((p1 = (void *)malloc(sizeof(bytes + align))) == NULL)
	{
		return NULL;
	}
	// Save pointer p1
	p2 = (void*)(((size_t)(p1)+offset)& ~(align - 1)); // POinter into aligned value
	((void**)p2)[-1] = p1;
	return p2;
}

void aligned_free(void *p2)
{
	void *p1;
	// Go back to p1 and then free this
	p1 = ((void**)p2)[-1];
	free(p1);

}