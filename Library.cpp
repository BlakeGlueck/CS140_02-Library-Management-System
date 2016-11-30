#include "Library.h"

Library::Library()
{
	_bookshelf = vector<Book>();
}

//adds a Book to the Library.
void Library::add(Book& aBook)
{
	_bookshelf.push_back(aBook);
}

//returns the whole bookshelf
vector<Book>& Library::getAll()
{
	return _bookshelf;
}

Book* Library::search(std::string name)
{
	Book* bkptr = NULL;
	for (Book& bk: _bookshelf)
	{
		if (bk.getName().compare(name) == 0)
		{
			bkptr = &bk;
			return bkptr;
		}
	}
	std::cout << "|" << name << "BOOK NOT FOUND IN THIS LIBRARY." << std::endl;
	//if book is not found, return null pointer
	return bkptr;
}

Book& Library::checkOutBook(std::string name)
{
	if ((*search(name)).getName().compare("Not a book"))
	{
		//if book is not found, return dummy book
		Book abook("Not a book", "No Date");
		return abook;
	}
	else
	{
		int i = 0;
		for (Book bk : _bookshelf)
		{
			if (bk.getName().compare(name) == 0)
			{
				//find and copy
				Book result = bk;
				//remove
				_bookshelf.erase(_bookshelf.begin() + i);
				//return
				return result;
			}
			i++;
		}
	}
}

bool Library::isEmpty() const
{
	return _bookshelf.empty();
}

unsigned int Library::size() const
{
	return _bookshelf.size();
}

std::ostream& operator<<(std::ostream& os, Library& anInstance)
{
	os << "[\n";

	for (Book b : anInstance.getAll())
	{
		os << b << "\n";
	}

	os << "]" << endl;

	return os;
}

void Library::deleteBook(string name)
{
	
	for (int i = 0; i < _bookshelf.size(); i++)
	{
		if (_bookshelf.at(i).getName().compare(name) == 0)
		{
			_bookshelf.erase(_bookshelf.begin() + i);
			return;
		}
	}
}