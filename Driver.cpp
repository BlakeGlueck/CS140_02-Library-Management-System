#include "Administrator.h"
#include "User.h"
#include "Book.h"
#include "UserRoster.h"
#include "Library.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ofstream outfile("Record.txt", ios::out);

	//outfile.open("Record.txt");

	Library lib;
	Book MobyDick("Moby Dick", "1/1/1");
	Book PrideAndPrejudice("PrideAndPrejudice", "2/1/1");
	Book DeathOfASalesman("Death of a Salesman", "3/1/1");
	Book WWZ("World War Z", "4/1/1");

	lib.addBook(MobyDick);
	lib.addBook(PrideAndPrejudice);
	lib.addBook(DeathOfASalesman);
	lib.addBook(WWZ);

	outfile << MobyDick << endl;
	outfile << "Bibliothek: " << lib;

	User Tommy("Tommy");

	Tommy.checkoutBook(MobyDick);

	cout << Tommy;

	Tommy.returnBook(MobyDick);

	cout << Tommy;

	Administrator admin("admin");

	cout << "Lib before Orientalism " << lib;
	admin.addNewBookToLibrary("Orientalism", lib);

	cout << "New lib" << lib;

	UserRoster usrRstr();

	//usrRstr.



	outfile.close();
	system("pause");
	return 0;
}