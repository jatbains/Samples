// ClassesByReferences.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

typedef struct Node
{
	int val;
	string s1;

}Node;

void Multiply(Node s,Node &t,Node *u);

int main()
{
	Node s1;
	Node t1;
	Node u1;

	u1.s1 = "hello";
	u1.val = 30;

	Multiply(s1,t1, &u1);   // Passing by value, Reference and Pointer

	cout << endl;

	cout << s1.val << " " << t1.val << " " << u1.val << endl;

	system("pause");
    return 0;
}

void Multiply(Node s,Node &t,Node *u)
{
	s.s1 = "Hello";
	s.val = 10;
	t.val = 100;
	u->val = 50;

	cout << s.s1 << " " << s.val << endl;

}
