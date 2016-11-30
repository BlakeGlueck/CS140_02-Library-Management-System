#include "Book.h"

Book::Book()
{
	_Name = "EMANON";
	_DueDate = "00/00/0000";
	_checkedOut = false;
	_borrower = "NONE";
}

Book::Book(string name)
{
	_Name = name;
	_DueDate = "00/00/0000";
	_checkedOut = false;
	_borrower = "NONE";
}

Book::Book(string name, string date)
{
	_Name = name;
	_DueDate = date;
	_checkedOut = false;
	_borrower = "NONE";
}

Book::Book(string name, string date, int checkedOut, string borrower)
{
	_Name = name;
	_DueDate = date;
	_checkedOut = checkedOut;
	_borrower = borrower;
}

string const Book::getName()
{
	return _Name;
}

string const Book::getDueDate()
{
	return _DueDate;
}

void Book::setName(string name)
{
	_Name = name;
}

void Book::setDueDate(string date)
{
	_DueDate = date;
}

bool Book::equals(Book book)
{
	return ((book.getName().compare(_Name) == 0) && (book.getDueDate().compare(_DueDate) == 0));
}

string const Book::getBorrower()
{
	return _borrower;
}

void Book::setBorrower(string name)
{
	_borrower = name;
}

bool Book::isCheckedOut() const
{
	return _checkedOut;
}

void Book::checkOut()
{
	_checkedOut = true;
}

void Book::checkIn()
{
	_checkedOut = false;
}

Book& Book::operator++()
{
	_checkedOut = false;
	return *this;
}

Book& Book::operator--()
{
	_checkedOut = true;
	return *this;
}

std::ostream& operator<<(std::ostream& os, Book& anInstance)
{
	os << "<" << anInstance.getName() << ", " << anInstance.getDueDate() << ", " << anInstance.isCheckedOut() << ", " << anInstance.getBorrower() << ">";

	return os;
}


void Book::appendBookRecord()
{
	ofstream outfile("BookRecord.txt", ios::app);

	outfile << "<" << _Name << ", " << _DueDate << ", " << _checkedOut << ", " << _borrower << ">" << std::endl;

	outfile.close();
}