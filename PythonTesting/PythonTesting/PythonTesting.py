import random
import sys
import os


greeting = 'Hello World'

print(greeting)

def fact(n):
    if n ==0 :
        return 1
    return n*fact(n-1)

def Fib(n):
    if (n<=1):
        return n
    return Fib(n-1)+Fib(n-2)

print('\n')

names = ['John','George','Paul', 'Ringo']

for x in names:
    print(x)

num = 10
count = 0
while num>0 :
    if (num & (num-1)) :
        count = count+1
    num >>= 1
        
  
print(count)

randNum = random.randrange(0,99)

while randNum != 30 :
    print(randNum)
    randNum = random.randrange(0,99)

print()
print(fact(10))
print()
print(Fib(10))