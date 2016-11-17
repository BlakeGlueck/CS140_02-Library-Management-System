#pragma once
#include<string>
#include "User.h"
#include "Library.h"
#include "UserRoster.h"

class Administrator : public User {
public:
	Administrator(string name);

	//creates a book with the given name and adds it to the given library
	void addNewBookToLibrary(string bookName, Library& lib);

	//alters the book of the given name if it is in the given User's _books by changing the due date to the given due date.
	void alterDueDateOfFor(string userName, string bookName, string newDueDate, UserRoster usrRstr);

	static string getDefaultDueDate();
	void changeDefaultDueDate(string newDueDate);


	
private:
	static string DefaultDueDate;
};