#ifndef _DYNAMIC_ARRAY_LIST_H_
#define _DYNAMIC_ARRAY_LIST_H_

#include "abstract_list.h"

template <typename T>
class DynamicArrayList : public AbstractList<T>
{
public:

	// default constructor
	DynamicArrayList();

	// copy constructor
	DynamicArrayList(const DynamicArrayList& x);

	// destructor
	~DynamicArrayList();

	// copy assignment
	DynamicArrayList& operator=(DynamicArrayList x);

	

	// determine if a list is empty
	bool isEmpty();

	// return current lenght of the list
	std::size_t getLength();

	// insert item at position in the list using 0-based indexing
	void insert(std::size_t position, const T& item);

	// remove item at position in the list using 0-based indexing
	void remove(std::size_t position);

	// remove all items from the list
	void clear();

	// get a copy of the item at position using 0-based indexing
	T getEntry(std::size_t position);

	// set the value of the item at position using 0-based indexing
	void setEntry(std::size_t position, const T& newValue);
private:

	/*
	// data members
	T *data;
	std::size_t capacity; //Max Size of the Array
	std::size_t length; //S
	std::size_t count; //countervariable that keeps track of the amount of items in the list
	//int count;
	*/
	std::size_t maxStackSize;
	std::size_t stackTop;
	T* alist;
	void copy(const DynamicArrayList<T>& other);
	//void listinital();
};

#include "dynamic_array_list.txx"

#endif // _DYNAMIC_ARRAY_LIST_H_
