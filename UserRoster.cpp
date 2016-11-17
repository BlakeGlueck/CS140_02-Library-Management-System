#include "UserRoster.h"

UserRoster::UserRoster()
{
	_Users = vector<User>();
}

//Adds a user to _Users
void UserRoster::addUser(User usr)
{
	_Users.push_back(usr);
}

//returns the vector representation of _Users
vector<User> UserRoster::getUsers()
{
	return _Users;
}

//finds the user of that name and returns a reference to it.
User& UserRoster::searchUser(string name)
{
	if (_Users.empty())
	{
		//If user is not found, return Dummy user
		User usr("EMANON");
		return usr;
	}
	for (User usr : _Users)
	{
		if ((usr.getName()).compare(name) == 0)
		{
			return usr;
		}
	}
	//If user is not found, return Dummy user
	User usr("EMANON");
	return usr;
}