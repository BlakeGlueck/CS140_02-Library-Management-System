#pragma once
#include<vector>
#include "Book.h"


class Library
{
public:
	Library();

	//adds a Book to the Library.
	void addBook(Book aBook);

	//returns the whole bookshelf
	vector<Book> const getBooks();

	friend std::ostream& operator<<(std::ostream& os, Library& anInstance);


private:
	vector<Book> _bookshelf;
};