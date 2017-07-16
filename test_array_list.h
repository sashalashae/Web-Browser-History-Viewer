#include <string>
#include <cxxtest/TestSuite.h>

#include "dynamic_array_list.h"

#include <cstdlib>
#include <stack>
//#include <iostream>

template class DynamicArrayList<int>;

class ArrayListTests : public CxxTest::TestSuite
{
public:
	void testisempty(void)
	{
		DynamicArrayList<int> b;
		TS_ASSERT(b.isEmpty() == true);
	}
	void testisnotempty(void)
	{
		DynamicArrayList<int> b;
		b.insert(0, 1);
		TS_ASSERT(b.isEmpty() == false);
	}
   void testgetLength( void )
   {
	   DynamicArrayList<int> a;
	   a.insert(0, 1);
	   TS_ASSERT(a.getLength() == 1);
   }  
   void testremove(void)
   {
	   DynamicArrayList<int> a;
	   a.insert(0, 1);
	   a.insert(1, 1);
	   a.insert(2, 2);
	   a.remove(2);
	   TS_ASSERT(a.getLength() == 2);
   }
   void testget(void)
   {
	   DynamicArrayList<int> a;
	   a.insert(0, 1);
	   a.insert(1, 1);
	   a.insert(2, 2);
	   TS_ASSERT(a.getEntry(2) == 2);
   }
};
