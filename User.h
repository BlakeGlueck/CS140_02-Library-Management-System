#pragma once
#include<string>
#include<vector>
#include<iostream>
#include "Book.h"
#include "Library.h"
#include<fstream>
//#include "UserRoster.h"
//#include "Administrator.h"

using namespace std;

class User 
{
public:
	User(std::string name);
	User(std::string name, std::vector<Book> books);
	//returns the name of this user
	std::string const getName();
	//returns the whole vector of this user's books with full access.
	vector<Book>& getBooks();
	//sets the name
	void setName(std::string);

	//adds a book to this User's books, updates the borrower, and assigns the due date
	void checkoutBook(string bkName, Library& lib);
	void checkoutBook(string bkName, Library& lib, bool opening, string dueDate);
	//removes and returns a particular book from this User's books. Also updates the book in the Library
	void returnBook(string bkName, Library& lib);

	//returns a pointer to a book in this User's _books
	Book* searchBook(string name);

	friend std::ostream& operator<<(std::ostream& os, User& anInstance);

	//appends this user's data to the UserRecord.txt
	void appendUserRecord();

protected:
	std::string _Name;

	//contains all this User's books
	vector<Book> _books;
};