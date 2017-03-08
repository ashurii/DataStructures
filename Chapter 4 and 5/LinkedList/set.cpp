#include "set.h"
//#include "node1.h"
#include <cassert>
#include <iostream>

using namespace std;
namespace main_savitch_5
{
set::set()
{
	head_ptr = NULL;
	many_nodes = 0;
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
void set::print_set() const
{
		const node *cursor; // This is a const node* because it won't change the list's nodes
		for(cursor = head_ptr; cursor != NULL; cursor = cursor->link())
			cout << cursor->data() << " ,";
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
	
	
	for(cursor = addend.head_ptr; cursor!= NULL; cursor = cursor->link())
		set_insert(cursor->data( ));
}
bool set::erase_one(const value_type& target)
{
	node *target_ptr;
	target_ptr = list_search(head_ptr, target);
	if (target_ptr == NULL)
		return false; //Target is not in the set
	target_ptr->set_data( head_ptr->data( ));
	list_head_remove(head_ptr);
	--many_nodes;
	return true;
}
ostream& operator<< (ostream& out, const set& set1)
{
	node* cursor;
	for(cursor = set1.head_ptr; cursor != NULL; cursor = cursor->link())
		out << cursor->data() << endl;	
	return out;
}
}
