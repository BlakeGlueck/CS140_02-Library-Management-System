#include "Administrator.h"
#include "User.h"
#include "Book.h"
#include "UserRoster.h"
#include "Library.h"
#include "Parser.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	Parser theParser;
	theParser.parseDueDate();
	theParser.parseBookRecord();
	theParser.parseUserRecord();
	
	int option;
	do
	{
		cout << "1-create user." << endl;
		cout << "2-create administrator." << endl;
		cout << "3-create book." << endl;
		cout << "4-check out book." << endl;
		cout << "5-return book." << endl;
		cout << "6-display all users." << endl;
		cout << "7-display all books." << endl;
		cout << "8-delete user." << endl;
		cout << "9-delete book." << endl;
		cout << "10-delete administrator." << endl;
		cout << "11-display book." << endl;
		cout << "12-display user." << endl;
		cout << "13-modify book." << endl;
		cout << "14-modify user." << endl;
		cout << "15-check due date for user." << endl;
		cout << "16-check due date for book." << endl;
		cout << "17-change default due date." << endl;
		cout << "18-clear all stored data and quit." << endl;
		cout << "0-Exit" << endl;
		
		cin >> option;
		if (option == 0)
		{
			theParser.storeData();
			return 0;
		}
		else if (option == 1)
		{
			//Add user
			cout << "Enter your user name." << endl;
			string usrName;
			cin.ignore();
			getline(cin, usrName, '\n');
			cout << "This is the name you entered." << usrName << endl;
			if (theParser.getRoster().search(usrName) == NULL)
			{
				//If that name is not already in the roster, make a new entry.
				theParser.getRoster().add(User(usrName));
				cout << "User successfully added." << endl;
			}
			else
			{
				//The name was already in the roster
				cout << "That Name is already in use" << endl;
	
			}
		}
		else if (option == 2)
		{
			//Add Admin
			cout << "Enter your administator name." << endl;
			string adminName;
			cin.ignore();
			getline(cin, adminName, '\n');
			cout << "This is the name you entered." << adminName << endl;
			if (theParser.getRoster().search(adminName) == NULL)
			{
				//If that name is not already in the roster, make a new entry.
				theParser.getRoster().add(Administrator(adminName));
				cout << "Administrator successfully added." << endl;
			}
			else
			{
				//The name was already in the roster
				cout << "That Name already in use" << endl;	
			}			
		}
		else if (option == 3)
		{
			//create book
			cout << "Enter the Administrator's name." << endl;
			string adminName;
			cin.ignore();
			getline(cin, adminName, '\n');
			cout << "This is the name you entered." << adminName << endl;
			if (theParser.getRoster().search(adminName) == NULL)
			{
				//The name was not found
				cout << "That is not a valid name" << endl;
			}
			else
			{
				Administrator utilAdmin(adminName);
				cout << "Enter the new book's name" << endl;
				string bookName;
				getline(cin, bookName, '\n');
				cout << "This is the book's name you entered." << bookName << endl;
				if (theParser.getLibrary().search(bookName) == NULL)
				{
					utilAdmin.addNewBookToLibrary(bookName, theParser.getLibrary());
				}
				else
				{
					cout << "That name is already in use." << endl;
				}
				

			}
		}
		else if (option == 4)
		{
			//check out book
			cout << "Enter user name" << endl;
			string usrname;
			cin.ignore();
			getline(cin, usrname, '\n');
			cout << "This is the name you entered. " << usrname << endl;
			if (theParser.getRoster().search(usrname) == NULL)
			{
				cout << "INVALID NAME" << endl;
			}
			else
			{
				cout << "Enter book name" << endl;
				string bookname;
				getline(cin, bookname, '\n');
				cout << "This is the name you entered." << bookname << endl;
				if (theParser.getLibrary().search(bookname) == NULL)
				{
					cout << "INVALID NAME" << endl;
					cout << theParser.getLibrary();
					cout << "searched for " << bookname << endl;
					system("pause");
					option = 0;
				}
				else
				{
					cout << theParser.getRoster();
					User test = (*theParser.getRoster().search(usrname));
					cout << test.getName();
					((*theParser.getRoster().search(usrname))).checkoutBook(bookname, theParser.getLibrary());
					cout << "the book was successfully checkedout." << endl;
				}
			}

		}
		else if (option == 5)
		{
			//return book
			cout << "Enter user name" << endl;
			string usrname;
			cin.ignore();
			getline(cin, usrname, '\n');
			cout << "This is the name you entered. " << usrname << endl;
			if (theParser.getRoster().search(usrname) == NULL)
			{
				cout << "INVALID NAME" << endl;
			}
			else
			{
				cout << "Enter book name" << endl;
				string bookname;
				getline(cin, bookname, '\n');
				cout << "This is the name you entered." << bookname << endl;
				if ((*theParser.getRoster().search(usrname)).searchBook(bookname) == NULL)
				{
					cout << "INVALID NAME" << endl;
					cout << (*theParser.getRoster().search(usrname));
					cout << "searched for " << bookname << endl;
					system("pause");
					option = 0;
				}
				else
				{
					((*theParser.getRoster().search(usrname))).returnBook(bookname, theParser.getLibrary());
					cout << "the book was successfully returned." << endl;
				}
			}
		}
		else if (option == 6)
		{
			//display all users
			cout << theParser.getRoster();
		}
		else if (option == 7)
		{
			//display all books
			cout << theParser.getLibrary();
		}
		else if (option == 8 || option == 10)
		{
			//delete user/administrator
			cout << "Enter the name of the user/administrator you wish to delete." << endl;
			string usrname;
			cin.ignore();
			getline(cin, usrname, '\n');
			if (theParser.getRoster().search(usrname) == NULL)
			{
				cout << "INVALID NAME" << endl;
			}
			else
			{
				theParser.getRoster().deleteUser(usrname, theParser.getLibrary());
				cout << "the user/administrator was successfully deleted" << endl;
			}

		}
		else if (option == 9)
		{
			//delete book
			cout << "Enter the name of the book you wish to delete." << endl;
			string bkname;
			cin.ignore();
			getline(cin, bkname, '\n');
			if (theParser.getLibrary().search(bkname) == NULL)
			{
				cout << "INVALID NAME" << endl;
			}
			else
			{
				for (User& user : theParser.getRoster().getAll())
				{
					if (!user.searchBook(bkname) == NULL)
					{
						user.returnBook(bkname, theParser.getLibrary());
					}
				}

				theParser.getLibrary().deleteBook(bkname);
				cout << "the book was successfully deleted" << endl;
			}
		}
		else if (option == 11 || option == 16)
		{
			//display book
			cout << "Enter the name of the book you wish to view" << endl;
			string bkname;
			cin.ignore();
			getline(cin, bkname, '\n');
			cout << (*theParser.getLibrary().search(bkname)) << endl;

		}
		else if (option == 12 || option == 15)
		{
			//display user
			cout << "Enter the name of the User you wish to view" << endl;
			string usrName;
			cin.ignore();
			getline(cin, usrName, '\n');
			cout << (*theParser.getRoster().search(usrName)) << endl;
		}
		else if (option == 13)
		{			
			//modify book
			cout << "Enter the books's current name" << endl;
			string name;
			cin.ignore();
			getline(cin, name, '\n');
			cout << "what would you like to change about the book? Nothing(0), Name(1), dueDate(2), whether it is checked out(3), or the borrower's name(4)?" << endl;
			int opt;
			cin >> opt;
			if (opt == 0)
			{

			}
			else if (opt == 1)
			{
				cout << "Enter the new book name" << endl;
				string name1;
				cin.ignore();
				getline(cin, name1, '\n');

				(*theParser.getLibrary().search(name)).setName(name1);

				for (User& user : theParser.getRoster().getAll())
				{
					if (!user.searchBook(name) == NULL)
					{
						(*user.searchBook(name)).setName(name1);
					}
				}
			}
			else if (opt == 2)
			{
				cout << "Enter the new book due date" << endl;
				string name1;
				cin.ignore();
				getline(cin, name1, '\n');

				(*theParser.getLibrary().search(name)).setDueDate(name1);

				for (User& user : theParser.getRoster().getAll())
				{
					if (!user.searchBook(name) == NULL)
					{
						(*user.searchBook(name)).setDueDate(name1);
					}
				}
			}
			else if (opt == 3)
			{
				cout << "Enter the correct value (1) for checked in. (0) for checked out" << endl;
				int name1;
				cin >> name1;
				if (name1 == 1)
				{
					(*theParser.getLibrary().search(name)).checkIn();

					for (User& user : theParser.getRoster().getAll())
					{
						if (!user.searchBook(name) == NULL)
						{
							(*user.searchBook(name)).checkIn();
						}
					}
				}
				else
				{
					(*theParser.getLibrary().search(name)).checkOut();

					for (User& user : theParser.getRoster().getAll())
					{
						if (!user.searchBook(name) == NULL)
						{
							(*user.searchBook(name)).checkOut();
						}
					}
				}

			}
			else if (opt == 4)
			{
				cout << "Enter the new borrower name" << endl;
				string name1;
				cin.ignore();
				getline(cin, name1, '\n');

				(*theParser.getLibrary().search(name)).setBorrower(name1);

				for (User& user : theParser.getRoster().getAll())
				{
					if (!user.searchBook(name) == NULL)
					{
						(*user.searchBook(name)).setBorrower(name1);
					}
				}
			}
		}
		else if (option == 14)
		{
			//modify user
			cout << "Enter the user's current name" << endl;
			string name;
			cin.ignore();
			getline(cin, name, '\n');
			cout << "Enter the new name." << endl;
			string name1;
			cin.ignore();
			getline(cin, name1, '\n');
			(*theParser.getRoster().search(name)).setName(name1);
			cout << "change successful." << endl;

		}
		else if (option == 17)
		{
			//change default due date
			cout << "Enter the new due date" << endl;
			string date;
			cin.ignore();
			getline(cin, date, '\n');

			Administrator addy("Addy");
			addy.changeDefaultDueDate(date);
			cout << "Change successful." << endl;
		}
		else if (option == 18)
		{
			//delete all stored data and exit
			theParser.deleteData();
			return 0;
		}


	} while (option != 0);
	
	theParser.storeData();
	system("pause");
	return 0;
}