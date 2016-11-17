#pragma once
#include<string>

using namespace std;

class Book
{
public:
	Book();
	Book(string name);
	Book(string name , string date);

	//getters
	string const getName();
	string const getDueDate();

	//setters
	void setName(string name);
	void setDueDate(string date);

	//determines whether book is equivalant to this based on the name and due date.
	bool equals(Book book);

	friend std::ostream& operator<<(std::ostream& os, Book& anInstance);

private:
	//in the form of First Last
	string _Name;
	//in the form of mm/dd/yyyy
	string _DueDate;
};