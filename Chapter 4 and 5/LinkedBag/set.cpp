#include "set.h"
#include <cassert>
using namespace main_savitch_5;

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