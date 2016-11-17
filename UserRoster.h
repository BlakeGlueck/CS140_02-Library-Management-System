#pragma once
#include<vector>
#include<string>
#include "User.h"
#include "Administrator.h"

class UserRoster
{
public:
	UserRoster();
	
	//Adds a user to _Users
	void addUser(User usr);

	//returns the vector representation of _Users
	vector<User> getUsers();

	//finds the user of that name and returns a reference to it.
	User& searchUser(string name);

private:
	vector<User> _Users;
};