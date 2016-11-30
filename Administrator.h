#pragma once
#include<string>
#include "User.h"
#include "Library.h"
#include "UserRoster.h"

class Administrator : public User {
public:
	Administrator(string name);
	Administrator(string name, std::vector<Book> books);

	//creates a book with the given name and adds it to the given library
	void addNewBookToLibrary(string bookName, Library& lib);

	//returns the default due date found in "Record.txt"
	static string getDefaultDueDate();
	//non-static method for changing the default due date
	void changeDefaultDueDate(string newDueDate);

	//appends this user to "UserRecord.txt"
	void appendUserRecord();
	
private:
	static string DefaultDueDate;
};