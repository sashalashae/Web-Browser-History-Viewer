#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

//Sasha Morgan
//ECE 2574
//Nov. 4th, 2016
#include "abstract_list.h"

template <typename T> class LinkedList : public AbstractList<T> {
public:

	// default constructor
	LinkedList();

	// copy constructor
	LinkedList(const LinkedList& x);

	// destructor
	~LinkedList();

	// copy assignment
	LinkedList& operator=(LinkedList x);

	// determine if a list is empty
	bool isEmpty();

	// return current length of the list
	std::size_t getLength();

	// insert item at position in the list using 0-based indexing
	// throws std::range_error on invalid position
	void insert(std::size_t position, const T& item);

	// remove item at position in the list using 0-based indexing
	// throws std::range_error on invalid position
	void remove(std::size_t position);

	// remove all items from the list
	void clear();

	// get a copy of the item at position using 0-based indexing
	// throws std::range_error on invalid position
	T getEntry(std::size_t position); ///const;

	// set the value of the item at position using 0-based indexing
	// throws std::range_error on invalid position
	void setEntry(std::size_t position, const T& newValue);


private:
	template <typename x>
	struct nodetype
	{
		x alist; 
		nodetype<x>* prev; 
		nodetype<x>* next; 
	};
	int count; //size
	void copy(const LinkedList<T> & other); 
	typedef nodetype<T>* linker; 
	linker search(size_t position); 
	nodetype<T> *first; 
	
	
};

#include "linked_list.txx"

#endif // _LINKED_LIST_H_