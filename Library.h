#pragma once
#include<vector>
#include<iostream>
#include "Book.h"
#include "myListADT.h"
//#include "UserRoster.h"

class Library : public myListADT<Book> 
{
public:
	Library();

	void add(Book& element);
	std::vector<Book>& getAll();
	Book* search(std::string name);
	bool isEmpty() const;
	unsigned int size() const;
	Book& checkOutBook(std::string name);

	void deleteBook(string name);

	friend std::ostream& operator<<(std::ostream& os, Library& anInstance);


private:
	vector<Book> _bookshelf;
};