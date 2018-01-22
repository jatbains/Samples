// Operators.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Book
{
private:
	int mPages;
public:
	void setPages(int pages);
	bool operator==(const Book &b);
	Book operator+(const Book &b);
};

void Book::setPages(int pages)
{
	mPages = pages;
}

bool Book::operator==(const Book &b)
{
	if (this->mPages == b.mPages)
		return true;
	else
		return false;
}
Book Book::operator+(const Book &b)
{
	Book newBook;
	newBook.mPages = b.mPages + this->mPages;
	return newBook;

}

int main()
{
	Book bible;
	Book koran;
	Book gita;
	bible.setPages(100);
	koran.setPages(100);
	gita = bible + koran;

	if (koran == bible)
		cout << "They are the same " << endl;
	else
		cout << "They are not the same " << endl;
	system("pause");
    return 0;
}

