#pragma once
#include<vector>
#include<string>

template<typename T>
class myListADT
{
public:
	//adds an element (book or User) to the member vector
	virtual void add(T& element) = 0;
	//returns the whole vector along with access to each element
	virtual std::vector<T>& getAll() = 0;
	//returns a pointer to the searched element if it exists in the member vector. If not, returns a NULL pointer
	virtual T* search(std::string name) = 0;
	//returns true if the vector is empty
	virtual bool isEmpty() const = 0;
	//returns the int size of the vector
	virtual unsigned int size() const = 0;
};