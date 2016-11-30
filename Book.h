#pragma once
#include<string>
#include<fstream>

using namespace std;

class Book
{
public:
	//constructors
	Book();
	Book(string name);
	Book(string name , string date);
	Book(string name, string date, int checkedOut, string borrower);

	//getters
	string const getName();
	string const getDueDate();

	//setters
	void setName(string name);
	void setDueDate(string date);

	//determines whether book is equivalant to this based on the name and due date.
	bool equals(Book book);

	//returns true if the book is checked out
	bool isCheckedOut() const;
	//sets the _checkedOut member bool to the correct value
	void checkOut();
	void checkIn();
	//check in
	Book& operator++();
	//check out
	Book& operator--();

	//setter and getter for _borrower (the borrower of the book)
	string const getBorrower();
	void setBorrower(string name);

	
	friend std::ostream& operator<<(std::ostream& os, Book& anInstance);

	//appends the record to the BookRecord.txt
	void appendBookRecord();

private:
	//in the form of First Last
	string _Name;
	//in the form of mm/dd/yyyy
	string _DueDate;
	//true if the book is checked out
	bool _checkedOut;
	//the name of the person who checked out the book
	string _borrower;
};