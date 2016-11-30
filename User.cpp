#include "User.h"
#include "Administrator.h"

User::User(string name)
{
	_Name = name;
}

User::User(string name, vector<Book> books)
{
	_Name = name;
	_books = books;
}

string const User::getName()
{
	return _Name;
}

//returns the vector representation of all of this User's books.
vector<Book>& User::getBooks()
{
	return _books;
}

void User::setName(string name)
{
	_Name = name;
}

//adds a book to this User's books and assigns a due date
void User::checkoutBook(string bkName, Library& lib)
{
	Book* bk = lib.search(bkName);
	if (bk == NULL)
	{
		std::cout << "NOT FOUND" << std::endl;
		return;
	}
	else
	{
		Book& book = *bk;
		if (book.isCheckedOut())
		{
			std::cout << bkName << " -------------------------------- is already checkedout." << std::endl;
		}
		else
		{
			book.setDueDate(Administrator::getDefaultDueDate());
			--book;
			book.setBorrower(_Name);
			_books.push_back(book);
			std::cout << book.getName() << "was successfully checked out" << book.isCheckedOut() << std::endl;
		}
	}

	
	
}

void User::checkoutBook(string bkName, Library& lib, bool opening, string dueDate)
{
	Book* bk = lib.search(bkName);
	if (bk == NULL)
	{
		std::cout << "NOT FOUND" << std::endl;
		return;
	}
	else
	{
		Book& book = *bk;
		if (!book.isCheckedOut() || opening)
		{
			book.setDueDate(dueDate);
			--book;
			book.setBorrower(_Name);
			_books.push_back(book);
			//std::cout << book.getName() << "was successfully checked out" << book.isCheckedOut() << std::endl;
		}
		else
		{
			std::cout << bkName << " -------------------------------- is already checkedout and this isn't the opening." << std::endl;
		}
	}
}

//removes and returns a particular book from this User's books.
void User::returnBook(string bkName, Library& lib)
{
	if (_books.empty())
	{
		//If the book is not found, print this message.
		std::cout << "BOOK NOT FOUND. CANNOT RETURN.";
	}
	else
	{
		//finds the book, and returns it. Then removes the book from _books. 
		int i = 0;
		for (Book bk : _books)
		{
			if (bk.getName().compare(bkName) == 0)
			{
				//find and copy
				Book result = bk;
				//remove
				_books.erase(_books.begin() + i );
				//update in the library
				Book& libBook = *lib.search(bkName);
				++libBook;
				libBook.setDueDate("00/00/0000");
				libBook.setBorrower("NONE");
				//return				
				return;
			}
			i++;
		}

		//If the book is not found, print this message.
		std::cout << "BOOK NOT FOUND. CANNOT RETURN.";
	}
}

Book* User::searchBook(string name)
{
	Book* bkptr = NULL;
	if (_books.empty())
	{
		//If the book is not found, return null
		return bkptr;
	}
	for (Book& bk : _books)
	{
		if (bk.getName().compare(name) == 0)
		{
			bkptr = &bk;
			return bkptr;
		}
	}
	//If the book is not found, return NULL
	return bkptr;
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

void User::appendUserRecord()
{
	ofstream outfile("UserRecord.txt", ios::app);

	outfile << _Name << ":u ";
	//outfile << "HERE";
	for (Book bk : _books)
	{
		outfile << bk << ", ";
	}
	outfile << "%" << std::endl;

	outfile.close();
}
