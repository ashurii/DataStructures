#include "set.h"
#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <algorithm>
#include <cassert>


using namespace std;
namespace main_savitch_3
{
	set::set(size_type initial_capacity)
	{
		data = new value_type[initial_capacity];
		capacity = initial_capacity;
		used = 0;
	}
	set::set(const set& source)
	{
		data = new value_type[source.capacity];
		capacity = source.capacity;
		used = source.used;
		copy(source.data, source.data + used, data);
	}
	set::~set()
	{
		delete []data;
	}
	void set::operator =(const set& source)
	{
		if(this == &source)
			return;
		value_type *new_data;
		if(capacity != source.capacity)
		{
			new_data = new value_type[source.capacity];
			delete [] data;
			data = new_data;
			capacity = source.capacity;
		}
		used = source.used;
		copy(source.data, source.data + used, data);
	}
	set operator +(const set& s1, const set& s2)
	{
		set answer;
		
		answer += s1;
		answer += s2;
		return answer;
		}

	void set::operator +=(const set& addend)
	// Precondition: size() + addend.size() <= CAPACITY
	// Postcondition: Each item in addend has been added to this set.
	// Library facilities used: algorithm, cassert
	{
		assert(size() + addend.size() <= capacity);
		copy(addend.data, addend.data + addend.used, data + used); 
		used += addend.used;
		}
		
	bool set::contains(const value_type& target) const
	{
		bool result;
		for(unsigned int i = 0; i < used; i++)
			if(target == data[i])
				result = true;
			else
				result = false;
			return result;
		}
		

	void set::insert(const value_type& entry)
	{
		assert(size() < capacity);
		assert(!(contains(entry)));
		data[used] = entry;
		++used;
		}
		
	bool set::erase_one(const value_type& target)
	//Postcondition: if target was in the set, then one copy as been removed;
	// Otherwise the set is unchanged. A true return value indicates that one 
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
			return false; //Target is not in the set. Do nothing
		
		//When execution reaches here, target is in the set at data[index]
		// So, reduce used by 1 and copy the last item onto data[index].
		data[index] = data[--used];
		return true;
	}

}

	





