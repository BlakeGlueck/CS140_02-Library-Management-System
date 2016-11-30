#include "UserRoster.h"

UserRoster::UserRoster()
{
	_Users = vector<User>();
}

//Adds a user to _Users
void UserRoster::add(User& usr)
{
	_Users.push_back(usr);
}

//returns the vector representation of _Users
vector<User>& UserRoster::getAll()
{
	return _Users;
}

//finds the user of that name and returns a reference to it.
User* UserRoster::search(string name)
{
	User* usrptr = NULL;
	if (_Users.empty())
	{
		//If user is not found, return nullpointer
		return usrptr;
	}
	for (User& usr : _Users)
	{
		if ((usr.getName()).compare(name) == 0)
		{
			usrptr = &usr;
			return usrptr;
		}
	}
	//If user is not found, return nullpointer
	return usrptr;
}

bool UserRoster::isEmpty() const
{
	return _Users.empty();
}

unsigned int UserRoster::size() const
{
	return _Users.size();
}

std::ostream& operator<<(std::ostream& os, UserRoster& anInstance)
{
	os << "Here is the UserRoster: \n[" << std::endl;
	for (User user : anInstance.getAll())
	{
		os << user << "\n";
	}
	os << "]\n";
	return os;
}

void UserRoster::deleteUser(string name, Library& lib)
{
	int index = 0;
	for (User& user : _Users)
	{
		if (user.getName().compare(name) == 0)
		{
			while (!user.getBooks().empty())
			{
				user.returnBook(user.getBooks().at(0).getName(), lib);
			}
			

			_Users.erase(_Users.begin() + index);
			return;
		}
		index++;
	}
}