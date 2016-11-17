#pragma once
#include<string>
#include<vector>
#include "Book.h"
//#include "Administrator.h"

using namespace std;

class User 
{
public:
	User(std::string name);
	std::string const getName();
	//returns the vector representation of all of this User's books.
	vector<Book> const getBooks();

	void setName(std::string);

	//adds a book to this User's books and assigns a due date
	void checkoutBook(Book book);
	//removes and returns a particular book from this User's books.
	Book returnBook(Book book);

	Book& searchBook(string name);

	friend std::ostream& operator<<(std::ostream& os, User& anInstance);

protected:
	std::string _Name;

	//contains all this User's books
	vector<Book> _books;
};