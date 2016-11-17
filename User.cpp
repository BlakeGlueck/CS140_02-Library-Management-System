#include "User.h"
#include "Administrator.h"

User::User(string name)
{
	_Name = name;
}

string const User::getName()
{
	return _Name;
}

//returns the vector representation of all of this User's books.
vector<Book> const User::getBooks()
{
	return _books;
}

void User::setName(string name)
{
	_Name = name;
}

//adds a book to this User's books and assigns a due date
void User::checkoutBook(Book book)
{

	book.setDueDate(Administrator::getDefaultDueDate());

	_books.push_back(book);
}

//removes and returns a particular book from this User's books.
Book User::returnBook(Book book)
{
	if (_books.empty())
	{
		//If the book is not found, return this dummy book.
		Book abook("Not a book", "No Date");
		return abook;
	}
	else
	{
		//finds the book, and returns it. Then removes the book from _books. 
		int i = 0;
		for (Book bk : _books)
		{
			if (bk.equals(book))
			{
				//find and copy
				Book result = bk;
				//remove
				_books.erase(_books.begin() + i );
				//return
				return result;
			}
			i++;
		}
		//If the book is not found, return this dummy book.
		Book abook("Not a book", "No Date");
		return abook;
	}
}

Book& User::searchBook(string name)
{
	if (_books.empty())
	{
		//If the book is not found, return this dummy book.
		Book abook("Not a book", "No Date");
		return abook;
	}
	for (Book bk : _books)
	{
		if (bk.getName().compare(name) == 0)
		{
			return bk;
		}
	}
	//If the book is not found, return this dummy book.
	Book abook("Not a book", "No Date");
	return abook;
}


std::ostream& operator<<(std::ostream& os, User& anInstance)
{
	os << anInstance.getName() << " has these books checked out:\n[\n";

	for (Book b : anInstance.getBooks())
	{
		os << b << "\n";
	}
	os << "]\n";

	return os;
}

