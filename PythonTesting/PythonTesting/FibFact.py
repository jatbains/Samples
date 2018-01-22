import random
import sys
import os


def fact(n):
    if n ==0 :
        return 1
    return n*fact(n-1)

def Fib(n):
    if (n<=1):
        return n
    return Fib(n-1)+Fib(n-2)

def main():
    pass



print()
print(fact(10))
print()
print(Fib(10))


if __name__ == "__main__":
    sys.exit(int(main() or 0))

