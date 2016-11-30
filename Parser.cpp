#include "Parser.h"

Parser::Parser()
{
	_usrRost = UserRoster();
	_lib = Library();
}

Parser::Parser(UserRoster& uR, Library& lib)
{
	_usrRost = uR;
	_lib = lib;
}

UserRoster& Parser::getRoster()
{
	return _usrRost;
}

Library& Parser::getLibrary()
{
	return _lib;
}


void Parser::parseUserRecord()
{
	ifstream infile("UserRecord.txt", ios::in);

	
	char line[256];

	


	while (infile.good())
	{
		infile.getline(line, 256);
		if (!(line[0] >= 65 && line[0] <= 122))
		{
			//std::cout << "END OF DOCUMENT" << std::endl;
			break;
		}
		//std::cout << "line: " << line << std::endl;
		//username
		std::string userName = "";
		//user's books
		std::vector<Book> books;
		//If this line is for an admin or a user in general
		char userOrAdmin;


		//index in line
		int index = 0;
		char chr = line[index];

		
		while (chr != ':')
		{
			userName += chr;
			index++;
			chr = line[index];
		}
		index++;
		chr = line[index];
		userOrAdmin = chr;
		index++;
		index++;
		chr = line[index];
		if (chr != '%')
		{
			index++;
			chr = line[index];
		}

		//std::cout << userName << std::endl;
		
		

		//each book
		while (chr != '%')
		{
			std::string bookName = "";
			std::string dueDate = "";
			int checkedOut;
			std::string borrower = "";

			//bookname
			while (chr != ',')
			{
				bookName += chr;
				index++;
				chr = line[index];
			}
			index++;
			chr = line[index];
			//std::cout << "bookname " << bookName << "; char = " << chr << std::endl;

			//dueDate
			while (chr != ',')
			{
				dueDate += chr;
				index++;
				chr = line[index];
			}
			//std::cout << "dueDate " << dueDate << "; char = " << chr << std::endl;
			//checkedout
			index++;
			index++;
			chr = line[index];
			checkedOut = ((chr == 49)? 1:0);
			index++;
			index++;
			chr = line[index];
			//std::cout << "checkedOut " << checkedOut << "; char = " << chr << std::endl;
			//borrower
			while (chr != '>')
			{
				borrower += chr;
				index++;
				chr = line[index];
			}
			//std::cout << "borrower " << borrower << "; char = " << chr << std::endl;
			index++;
			index++;
			index++;
			chr = line[index];
			if (chr != '%')
			{
				index++;
				chr = line[index];
			}
			//std::cout << "char (end of book while) = " << chr << std::endl;
			//std::cout << "Here is the created book, then the library book.";
			//std::cout << Book(bookName, dueDate, checkedOut, borrower) << std::endl;
			//_lib.search(bookName);
			//std::cout << (*_lib.search(bookName)) << std::endl;
			books.push_back(Book(bookName, dueDate, checkedOut, borrower));
		}
		//std::cout << "END OF LINE" << std::endl;
		if (userOrAdmin == 'a')
		{
			_usrRost.add(Administrator(userName));
			for (Book bk: books)
			{
				(*_usrRost.search(userName)).checkoutBook(bk.getName(), _lib, true, bk.getDueDate());
			}
		}
		else
		{
			_usrRost.add(User(userName));
			for (Book bk : books)
			{
				(*_usrRost.search(userName)).checkoutBook(bk.getName(), _lib, true, bk.getDueDate());
			}
		}
		//std::cout << _usrRost;

	}

	//std::cout << "DONE PARSING" << std::endl;
	infile.close();
}


void Parser::parseBookRecord()
{
	ifstream infile("BookRecord.txt", ios::in);

	char line[256];
	char chr;

	while (infile.good())
	{
		infile.getline(line, 256);
		int index = 0;
		chr = line[index];
		//std::cout << "LINE: " << line << std::endl;

		if (chr == '<')
		{
			index++;
			chr = line[index];

			std::string title;
			std::string dueDate;
			int checkedOut;
			std::string borrower;

			while (chr != ',')
			{
				title += chr;
				index++;
				chr = line[index];
			}
			//std::cout << "TITLE " << title << std::endl;

			index++;
			index++;
			chr = line[index];

			while (chr != ',')
			{
				dueDate += chr;
				index++;
				chr = line[index];
			}

			//std::cout << "DUEDATE " << dueDate << std::endl;

			index++;
			index++;
			chr = line[index];
			checkedOut = ((chr == 49) ? 1 : 0);
			//std::cout << "Checkedout " << chr << endl;
			index++;
			index++;
			index++;
			chr = line[index];

			while (chr != '>')
			{
				borrower += chr;
				index++;
				chr = line[index];
			}
			//std::cout << borrower << std::endl;

			_lib.add(Book(title, dueDate, checkedOut, borrower));
			//cout << _lib;
		}
	}


	infile.close();
}

void Parser::parseDueDate()
{
	ifstream infile("Record.txt", ios::in);

	char line[256];

	Administrator admin("ADDY");
	
	if (infile.good())
	{
		infile.getline(line, 256);

		admin.changeDefaultDueDate(line);
	}
	else
	{
		admin.changeDefaultDueDate("00/00/0000");
	}

	infile.close();
}

void Parser::storeData()
{
	ofstream userOut("UserRecord.txt", ios::out);
	userOut << "";
	userOut.close();
	for (User u : _usrRost.getAll())
	{
		u.appendUserRecord();
	}

	ofstream bookOut("BookRecord.txt", ios::out);
	bookOut << "";
	bookOut.close();
	for (Book bk : _lib.getAll())
	{
		bk.appendBookRecord();
	}

	ofstream record("Record.txt", ios::out);
	record << Administrator::getDefaultDueDate();
	record.close();
}

void Parser::deleteData()
{
	ofstream bookOut("BookRecord.txt", ios::out);
	bookOut << "";
	bookOut.close();

	ofstream userOut("UserRecord.txt", ios::out);
	userOut << "";
	userOut.close();

	ofstream record("Record.txt", ios::out);
	record << Administrator::getDefaultDueDate();
	record.close();
}