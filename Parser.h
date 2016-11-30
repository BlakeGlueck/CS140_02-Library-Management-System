#pragma once
#include <fstream>
#include <iostream>
#include "UserRoster.h"
#include "Library.h"
#include "Administrator.h"

class Parser
{
public:
	
	Parser();
	Parser(UserRoster& uR, Library& _lib);

	//call all upon opening (reads elements in the text documents into more accessible memory)
	void parseUserRecord();
	void parseBookRecord();
	void parseDueDate();

	//call on closing (updates data in all text documents)
	void storeData();

	//clears all text documents
	void deleteData();

	//returns the whole member object, with full access
	UserRoster& getRoster();
	Library& getLibrary();

private:
	UserRoster _usrRost;
	Library _lib;
};