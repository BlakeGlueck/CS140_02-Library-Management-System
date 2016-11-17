#include "Administrator.h"

Administrator::Administrator(string name)
	:User(name)
{

}

void Administrator::addNewBookToLibrary(string bookName, Library& lib)
{
	Book newBook(bookName);
	lib.addBook(newBook);
}

void Administrator::alterDueDateOfFor(string userName, string bookName, string newDueDate, UserRoster usrRstr)
{
	User usr = usrRstr.searchUser(userName);

	Book bk = usr.searchBook(bookName);

	bk.setDueDate(newDueDate);
}

string Administrator::DefaultDueDate{ "12/8/2016" };

string Administrator::getDefaultDueDate()
{
	return DefaultDueDate;
}

void Administrator::changeDefaultDueDate(string newDueDate)
{
	DefaultDueDate = newDueDate;
}

