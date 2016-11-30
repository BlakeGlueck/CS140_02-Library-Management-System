# CS140_02-Library-Management-System

Notes on the organization of the project.
	I decided to implement a Parser class which does almost all of 
	the reading and writing to the three text documents (Record, UserRecord, and BookRecord.txt)
	at the beginning and end of the runtime, not during.	

	A user can check out more than one book, but a book can only be checked out by
	one user at a time.

	An Administrator is a User, but a User is not necessarily an Administrator (Administrator
	inherits from User).

	The whole project is done without throwing any exceptions, so do not worry if the
	program has to break. Everything should still be saved in the text documents.
	That being said, I wish we covered exceptions in class. I had trouble implementing
	them on my own. I would have liked to have them in this project.

Here are the required methods. 

Implement at-least two overloaded methods
	In User
	//adds a book to this User's books, updates the borrower, and assigns the due date
	void checkoutBook(string bkName, Library& lib);
	void checkoutBook(string bkName, Library& lib, bool opening, string dueDate);

Implement at-least two overloaded constructor
	//constructors
	Book();
	Book(string name);
	Book(string name , string date);
	Book(string name, string date, int checkedOut, string borrower);
	
Implement at-least two overloaded operator
	//check in
	Book& operator++();
	//check out
	Book& operator--();

Implement at-least one method which return pointer
	In "myListADT"
	//returns a pointer to the searched element if it exists in the member vector. If not, returns a NULL pointer
	virtual T* search(std::string name) = 0;

Implement Templates (function or class)
	myListADT (inherited by UserRoster and Library)

Use Vectors and Arrays in at-least one feature
	in User
	//contains all this User's books
	vector<Book> _books;	

Implement insert new book record methods
	See Driver
Implement insert new student record methods
	See Driver
Implement display all book and all students (2 diff methods)
	See Driver
Implement specific book details
	See Driver
Implement specific student details  
	See Driver
Implement delete books and student record methods (2 methods)
	See Driver
Implement search book and student record methods (2methods)
	See Driver
Implement modify book and student record methods (search and modify book and student record)
	See Driver
Implement Issue book method (update the book and student records in file)
	See Driver
Implement deposit book method (update the book and student records in file)
	See Driver
Implement check due date for student method (display book and due date)
	See Driver
Implement check due date for book and borrower details as a method (display student & due date)
	See Driver
Implement driver class
	See Driver


Driver options:
	1-create user
	2-create administrator
	3-create book
	4-check out book
	5-return book
	6-display all users
	7-display all books
	8-delete user
	9-delete book
	10-delete administrator
	11-display book
	12-display user
	13-modify book
	14-modify user
	15-check due date for user
	16-check due date for book
	17-change default due date
	18-clear all stored data and quit
	0-Exit


  
