#include <string>
#include <cxxtest/TestSuite.h>

#include "linked_list.h"

#include <cstdlib>
#include <stack>

//Sasha Morgan
//ECE 2574
//Nov. 4th, 2016

template class LinkedList<int>;

class LinkedListTests : public CxxTest::TestSuite
{
public:
   void testempty( void )
   {
	   LinkedList<int> a;
	   a.insert(0, 1);
	   TS_ASSERT(a.isEmpty() == false);
   }  
   void testnotempty(void)
   {
	   LinkedList<int> a;
	   a.insert(0, 1);
	   a.remove(0);
	   TS_ASSERT(a.isEmpty() == true);
   }
   void testgetlength(void)
   {
	   LinkedList<int> a;
	   a.insert(0, 1);
	   a.insert(1, 1);
	   a.insert(2, 1);
	   a.insert(3, 1);
	   a.remove(0);
	   TS_ASSERT(a.getLength() == 3);
   }
   void testgetentry(void)
   {
	   LinkedList<int> a;
	   a.insert(0, 1);
	   a.insert(1, 2);
	   a.insert(2, 5);
	   a.insert(3, 8);
	   a.remove(0);
	   TS_ASSERT(a.getEntry(0) == 2);
   }
};
