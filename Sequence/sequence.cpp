#include "sequence.h"
#include <cassert>

namespace main_savitch_3
{
sequence::sequence()
{
	used = 0;
}
void sequence::start()
{
		current_index = 0;
}
bool sequence::is_item() const
{
	return current_index < used;
	}
void sequence::insert(const value_type& entry)
//Precondition: size() < CAPACITY
//Postcondition: A new copy of entry has been inserted in the sequence.
// before the current item. If there was no current item, then the 
// new entry has been inserted at the front. In either case, the new item is now the 
// current item of the sequence
{
	size_type i;
	assert(size() < CAPACITY);
	if(!is_item())
		current_index = 0;
	
	for(i = used; i > current_index; --i)
		data[i] = data[i-1];
	
	data[current_index] = entry;
	++used;
			
}
void sequence::attach(const value_type& entry)
//Precondition: size() < CAPACITY
//Postcondition: A new copy of entry has been inserted in the sequence
// after the current item. If there was no current item, then the 
// new entry has been attached at the end. In either case, the new item is now the 
// current item of the sequence	
{
	
	size_type i;
	assert(size() < CAPACITY);
	if(!is_item())
	{
		current_index = size()+1;
	}
	
	for(i = used; i > current_index; --i)
		data[i] = data[i-1];
	
	data[current_index] = entry;
	++used;
}
void sequence::remove_current()
// Precondition: is_item returns true
// Postcondition: The current item has been removed from the sequence,
// and the item after this (if there is one) is now the current item
{
	assert(is_item());
	for(int i = (current()); i < used; ++i)
		data[i] = data[i+1];					//Removes 
		--used;
		
	}
//---------------------------------
//Question 23
//---------------------------------
void sequence::remove(const value_type& target)

// Postcondition: The target has been removed from the sequence,
// and the item after this (if there is one) is now the current item
{
	size_type index;
	index = 0;
	for(int i = 0; i < used; ++i)
		if(data[i] == target)
		{
			index = i;
		current_index = index;
		remove_current();
		}
}