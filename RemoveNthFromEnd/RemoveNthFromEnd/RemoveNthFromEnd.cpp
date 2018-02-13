// RemoveNthFromEnd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


 //Definition for singly-linked list.
 typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 }ListNode;

 ListNode *AllocNode(int x);
 ListNode * InsertNode(ListNode *head, int x);
 void PrintList(ListNode *head);
 ListNode *Reverse(ListNode* head);
 ListNode *RemoveNode(ListNode *head, int n);

 int main()
 {
	 int data[] = { 4,8,6,12,10,1,16 };
	 int size = sizeof(data) / sizeof(data[0]);
	 ListNode *head = nullptr;

	 for (int i = 0; i < size; i++)
	 {
		 head = InsertNode(head, data[i]);
	 }

	 PrintList(head);

	 cout << endl;

	 head = Reverse(head);

	 PrintList(head);

	 cout << endl;
	 // Remove 2nd node
	 head = RemoveNode(head, 2);

	 PrintList(head);

	 cout << endl;

	 // Reverse again
	 head = Reverse(head);

	 PrintList(head);

	 cout << endl;

	 system("pause");
	 return 0;
}

 ListNode *RemoveNode(ListNode *head,int n)
 {
	 ListNode *temp = head;
	 ListNode *prev = nullptr;

	 for (int i = 1; i < n; i++)
	 {
		 prev = temp;
		 if (temp->next != nullptr)
		 {
			 temp = temp->next;
		 }

	 }
	 // temp points to node and prev to one before it
	 prev->next = temp->next;
	 free(temp);
	 return head;
 }

 ListNode *Reverse(ListNode* head)
 {
	 ListNode *prev = nullptr;
	 ListNode *curr = head;
	 ListNode *temp = nullptr;

	 while (curr != nullptr)
	 {
		 temp = curr->next;
		 curr->next = prev;
		 prev = curr;
		 curr = temp;
	 }
	 // curr is null and prev is new head
	 return prev;
 }

 void PrintList(ListNode *head)
 {
	 ListNode *temp = head;
	 while (temp != nullptr)
	 {
		 cout << " " << temp->val << " ";
		 temp = temp->next;
	 }
 }

ListNode *AllocNode(int x)
{
	ListNode *temp = new ListNode(x);
	return temp;
	
}
ListNode * InsertNode(ListNode *head, int x)
{
	if (head == nullptr)
	{
		head = AllocNode(x);
		return head;
	}
	ListNode *temp = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}

	temp->next = AllocNode(x);
	return head;
}
