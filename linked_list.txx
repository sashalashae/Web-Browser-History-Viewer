//Sasha Morgan
//ECE 2574
//Nov. 4th, 2016

#include "linked_list.h"

#include <stdexcept>
template<typename T>
LinkedList<T>::LinkedList() // default constructor
{
	first = NULL; //sets the pointer equal to null
	count = 0; //counter variable
}

//Copy Assignment
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
	count = x.count; ///sets the counter variables equal to each other
	copy(x); //Calls the copy function to create a new capy list
}
template <typename T>
LinkedList<T> & LinkedList<T>::operator=(LinkedList<T> x)
{
	count = x.count; //sets the counter variables equal to each other
	copy(x); //Calls the copy function to create a new capy list
	return *this;
}

template  <typename T>
LinkedList<T>::~LinkedList()
{
	this->clear(); //Deletes the list
}


// This method makes a copy of the linked list by arrange its pointer nodes
template <typename T>
void LinkedList<T>::copy(const LinkedList<T> & other)
{
	nodetype<T>* holdfirst = nullptr;  //pointer for the first position
	nodetype<T>* holdsecond = nullptr; //pointe for the second position
	if (other.first != nullptr)
	{
		first = new nodetype<T>; //creates a new head node
		first->prev = other.first->prev; //points the head node to the previous node
		first->alist = other.first->alist; //points the node to the list

		holdfirst = first;
		holdsecond = first->next;
	}
	if (other.first == nullptr)
	{
		first = nullptr; //sets the first node 
	}
	while (holdsecond != nullptr)
	{
		holdfirst->next = new nodetype<T>;
		holdfirst = holdfirst->next; 
		holdfirst->prev = holdsecond->prev;
		holdsecond = holdsecond->next;
	}
}

//This method searches through the list to find the correct item
template <typename T>
typename LinkedList<T>::linker LinkedList<T>::search(size_t position)
{
	if (position >= 0 && position <= count) //Makes sure the position is within the list
	{
		linker spec = first; //creates a node
		int i = 0; //counter position
		while (i < position)
		{
			spec = spec->next; 
			i++;//updates the loop
		}
		return spec;
	}
	else
	{
		throw std::range_error("Hold Up Wait A Minute, your out of range homie! Try Again."); //throws the range error
	}
}
//If the list is empty the method returns true, otherwise the list is not empty and returns false
template <typename T>
bool LinkedList<T>::isEmpty()
{
	bool check = false; //creates a default boolean condition
	if (first == nullptr)
	{
		check = true;
	}
	return check;
}

//Gets the current length of the list, by returning the counter variable
template <typename T>
size_t LinkedList<T>::getLength()
{
	return count;
}

//Inserts an item into the position
//Creates a new node and stores the information in it
//Connects the new node to the head and tail of the node
template <typename T>
void LinkedList<T>::insert(std::size_t position, const T& item)
{
	if (position >= 0 && position <= count) //Checks to see if the position is in the list
	{
		linker newnew = new nodetype<T>; //creates a new linking node
		newnew->alist = item; //sets the node to point to the data then sets the data 
		if (position == 0 && first == nullptr) //Checks the position
		{
			
			newnew->next = nullptr; //Inserts the new node at the fron of the list
			newnew->prev = nullptr;
			first = newnew;
		}
		else if (position == 0 && first != nullptr)
		{
			
			newnew->next = first; //inserts the node at a position that is not the front of the list
			newnew->prev = nullptr;
			first = newnew;
		}
		else
		{
			linker before = search(position - 1);
			if (before != nullptr)
			{
				newnew->next = before->next;
				before->next = newnew;
			}
			else
			{
				throw std::range_error("Hold Up Wait A Minute, your out of range homie! Try Again.");
			}
		}
		count++;

	}
	else //The position is out of bounds it throws a range error
	{
		throw std::range_error("Hold Up Wait A Minute, your out of range homie! Try Again.");
	}
}

//Removes an item from any position
template <typename T>
void LinkedList<T>::remove(size_t position)
{
	if (position >= 0 && position <= count) //checks to see if the position 
	{
		linker current = nullptr; //creates a new node and sets it equal to null
		if (position == 0)
		{
			if (first != nullptr)
			{
				current = first; //sets the place holder equal to the first node
				first = first->next; //points the first node to the second node
			}
			else
			{
				throw std::range_error("Hold Up Wait A Minute, your out of range homie! Try Again.");
			}
		}
		else
		{
			linker before = search(position - 1); //gets the positon of the node to the left of the data point
			if (before->next != nullptr) //points the place holder to the next pointer
			{
				current = before->next; //sets the current place holder equal to the previous term which points to the next term
				before->next = current->next;
			}
			else
			{
				throw std::range_error("Hold Up Wait A Minute, your out of range homie! Try Again.");
			}
		}
		current->next = nullptr; //sets the current place holder node to the next node and sets it equal to nullptr
		delete current; //deletes the current place holder
		current = nullptr; //sets the current place holder to be equal to nullptr
		count--; //decrements the counter variable
	}
	else
	{
		throw std::range_error("Hold Up Wait A Minute, your out of range homie! Try Again.");
	}
}

//Gets a specific item at a specific location
template <typename T>
T LinkedList<T>::getEntry(std::size_t position)
{
	if (position >= 0 && position <= count) //checks to see if the position is in range
	{
		linker point = search(position); //searches for the specific item and sets a temporary node equal to it
		return point->alist;
	}
	else
	{
		throw std::range_error("Hold Up Wait A Minute, your out of range homie! Try Again.");
	}
}

template <typename T>
void LinkedList<T>::clear()
{
	while (!this->isEmpty())
	{
		this->remove(0);
	}
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
	if (position >= 0 && position <= count)
	{
		nodetype<T>* fin = search(position);
		fin->alist = newValue;
	}
	if (position < 0 && position > count)
	{
		throw std::range_error("Hold Up Wait A Minute, your out of range homie! Try Again.");
	}

}
