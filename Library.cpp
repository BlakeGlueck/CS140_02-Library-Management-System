#include "Library.h"

Library::Library()
{
	_bookshelf = vector<Book>();
}

//adds a Book to the Library.
void Library::addBook(Book aBook)
{
	_bookshelf.push_back(aBook);
}

//returns the whole bookshelf
vector<Book> const Library::getBooks()
{
	return _bookshelf;
}

std::ostream& operator<<(std::ostream& os, Library& anInstance)
{
	os << "[\n";

	for (Book b : anInstance.getBooks())
	{
		os << b << "\n";
	}

	os << "]" << endl;

	return os;
}