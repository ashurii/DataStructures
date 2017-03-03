#include "set.h"
//#include "node1.h"
#include <cassert>

namespace main_savitch_5
{
set::set()
{
}

set::~set()
{
	list_clear(head_ptr);
	many_nodes = 0;
}

bool set::contains(const value_type& target) const
{
	const node *cursor;
	bool contains = false;
	
	cursor = list_search(head_ptr, target);
	if(cursor != NULL)
		contains = true;
	return contains;
}
void set::set_insert(const value_type& entry)
{

	if(!contains(entry))
	{
		list_head_insert(head_ptr, entry);
		++many_nodes;
	}	
	else
		return;
}
set::value_type set::grab() const
{
	size_type i;
	const node *cursor; // This is a const node* because it won't change the list's nodes
	
	assert(size( ) > 0);
	i = (rand( ) % size( ) +1);
	cursor = list_locate(head_ptr, i);
	return cursor->data( );
}

void set::operator =(const set& source)
{
	node *tail_ptr;
	if(this == &source)
		return;
		
	list_clear(head_ptr);
	many_nodes = 0;
	list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;
}
void set::operator +=(const set& addend)
{
	node* cursor; //cursor for this list
	
	
	for(cursor = addend.head_ptr; cursor->link() != NULL; cursor = cursor->link())
		list_insert(tail_ptr, cursor->data( ));
}
bool set::erase_one(const value_type& target)
{
	node *target_ptr;
	target_ptr = list_search(head_ptr, target);
	if (target_ptr == NULL);
		return false; //Target is not in the set
	target_ptr->set_data( head_ptr->data( ));
	list_head_remove(head_ptr);
	--many_nodes;
	return true;
}
}
