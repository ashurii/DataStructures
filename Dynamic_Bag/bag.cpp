#include "bag.h"
#include <cassert>
#include <algorithm>
using namespace std;

namespace main_savitch_4
{
		bag::bag(size_type initial_capacity)
		{
			data = new value_type[initial_capacity];
			capacity = initial_capacity;
			used = 0;
		}
        bag::bag(const bag& source)
		{
			data = new value_type[source.capacity];
			capacity = source.capacity;
			used = source.used;
			copy(source.data, source.data + used, data);
		}
        bag::~bag( )
		{
			delete [] data;
		}
		void bag::operator=(const bag& source)
		{
			//	Check for possible self assignment:
			if (this == &source)
			return;
			
			value_type *new_data;
			if(capacity != source.capacity)
			{
				new_data = new value_type[source.capacity];		//Allocate memory for new array
				delete [] data;
				data = new_data;								//The pointer, data, now points to the newly allocated array
				capacity = source.capacity;
			}
			used = source.used;
			copy(source.data, source.data + used, data);
		}
		void bag::reserve(size_type new_capacity)
		// Library facilities used: alogrithm
		{
			value_type *larger_array;
			
			if (new_capacity == capacity)
				return; // The allocated memory is already the right size
				
			if(new_capacity < used)
				new_capacity = used; //Can't allocate less than we are using
				
			larger_array = new value_type[new_capacity];
			copy(data, data + used, larger_array);
			delete [] data;
			data = larger_array;
			capacity = new_capacity;
		}
	bool bag::erase_one(const value_type& target)
	//Postcondition: if target was in the bag, then one copy as been removed;
	// Otherwise the bag is unchanged. A true return value indicates that one 
	// copy was removed; false indicates that nothing was removed
	{
		size_type index; //Location of target in the data array
	
		// First, set index to the location of target in the data array, 
		// which could be as small as 0, or as large as used-1. If target is not
		// in the array, then index will be set equal to used
		index = 0;
		while((index < used) && (data[index] != target))
			++index;
		if(index == used)
			return false; //Target is not in the bag. Do nothing
		
		//When execution reaches here, target is in the bag at data[index]
		// So, reduce used by 1 and copy the last item onto data[index].
		data[index] = data[--used];
		return true;
	}
	bag::size_type bag::erase(const value_type& target) 
	{
		size_type copies;
		size_type index;
		copies = 0;
		index = 0;
		while((index < used) && (data[index] != target))
			++index;
		if(index == used)
			return 0;// Target not in the bag. Do nothing.
		if((data[index] == target))
			++copies;
		data[index] = data[--used];
		return copies;
	}
//	---------------------------------------------
//	Question 19 
//	---------------------------------------------
	void bag::insert(const value_type& entry)
	{
		if (used == capacity)
			reserve((int)(1 + (used*1.10)));
		data[used] = entry;
		++used;
	}
	void bag::operator +=(const bag& addend)
	// Library faccilities used: algorithm
	{
		if(used + addend.used > capacity)
			reserve(used + addend.used);
	}
}
