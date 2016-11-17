#include "Book.h"

Book::Book()
{
	_Name = "EMANON";
	_DueDate = "00/00/0000";
}

Book::Book(string name)
{
	_Name = name;
	_DueDate = "00/00/0000";
}

Book::Book(string name, string date)
{
	_Name = name;
	_DueDate = date;
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

std::ostream& operator<<(std::ostream& os, Book& anInstance)
{
	os << "<" << anInstance.getName() << " , " << anInstance.getDueDate() << ">";

	return os;
}