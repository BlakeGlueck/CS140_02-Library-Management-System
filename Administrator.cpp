#include "Administrator.h"

Administrator::Administrator(string name)
	:User(name)
{

}

Administrator::Administrator(string name, std::vector<Book> books)
	: User(name, books)
{

}

void Administrator::addNewBookToLibrary(string bookName, Library& lib)
{
	Book newBook(bookName);
	lib.add(newBook);
}


/*void Administrator::alterDueDateOfFor(string userName, string bookName, string newDueDate, UserRoster usrRstr)
{
	User usr = usrRstr.search(userName);

	Book bk = usr.searchBook(bookName);

	bk.setDueDate(newDueDate);
}*/

string Administrator::DefaultDueDate{ "12/8/2016" };

string Administrator::getDefaultDueDate()
{
	return DefaultDueDate;
}

void Administrator::changeDefaultDueDate(string newDueDate)
{
	DefaultDueDate = newDueDate;
}

void Administrator::appendUserRecord()
{
	ofstream outfile("UserRecord.txt", ios::app);

	outfile << _Name << ":a ";
	for (Book bk : _books)
	{
		outfile << bk << ", ";
	}
	outfile << "%" << std::endl;

	outfile.close();
}