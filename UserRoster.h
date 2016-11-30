#pragma once
#include<vector>
#include<string>
#include<iostream>
#include "User.h"
#include "Administrator.h"

class UserRoster : public myListADT<User>
{
public:
	UserRoster();
	
	virtual void add(User& element);
	virtual std::vector<User>& getAll();
	virtual User* search(std::string name);
	virtual bool isEmpty() const;
	virtual unsigned int size() const;

	void deleteUser(string name, Library& lib);

	friend std::ostream& operator<<(std::ostream& os, UserRoster& anInstance);

private:
	vector<User> _Users;
};