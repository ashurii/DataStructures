#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <algorithm>
#include "bag.h"
using namespace std;
namespace main_savitch_3
{
bag::bag()
{
	used = 0;
}
bag operator +(const bag& b1, const bag& b2)
{
	bag answer;
	
	answer += b1;
	answer += b2;
	return answer;
	}

void bag::operator +=(const bag& addend)
// Precondition: size() + addend.size() <= CAPACITY
// Postcondition: Each item in addend has been added to this bag.
// Library facilities used: algorithm, cassert
{
	copy(addend.data, addend.data + addend.used, data + used); 
	used += addend.used;
	}
	
bag::size_type bag::count(const value_type& target) const
{
	size_type answer;
	size_type i;
	answer = 0;
	for(i = 0; i < used; i++)
		if(target == data[i])
			++answer;
	return answer;
	}
	

void bag::insert(const value_type& entry)
{
	//assert(size() < CAPACITY);
	data[used] = entry;
	++used;
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
	//----------------------
	//QUESTION 12
	//----------------------
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
}

	



