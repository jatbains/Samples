
import random
import sys
import os

class Node:
    __value = None
    __next = None

def allocNode(n):
    temp = Node
    temp.__value = n
    temp.__next = None
    return temp

def insertNode(head,n):
    if (head == None):
        head = allocNode(n)
        return head
    else :
        temp = None
        temp = head
        while (temp.__next != None):
            temp = temp.__next
        temp.__next = allocNode(n)
    return head

values = [12,3,15,5,18,7,9,21,23]

head = None
for x in values:
#    head = insertNode(head,x)
    print(x)







