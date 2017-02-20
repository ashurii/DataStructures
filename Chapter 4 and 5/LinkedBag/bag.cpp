#include "bag.h"

using namespace main_savitch_5;

bag::bag()
{
}

bag::~bag()
{
	list_clear(head_ptr);
	many_nodes = 0;
}

bag::size_type bag::count(const value_type& target) const
{
	size_type answer;
	const node *cursor;
	
	answer = 0;
	cursor = list_search(head_ptr, target);
	while (cursor != NULL)
	{
		// Each time that cursor is not NULL, we have another occurence of target
		// so we add one to answer and then move cursor to the next occurence of the target
		++answer;
		cursor = cursor->link();
		cursor = list_search(cursor, target);
	}
	return answer;
}

bag::value_type bag::grab() cost
{
	size_type i;
	const node *cursor; // This is a const node* because it won't change the list's nodes
	
	asser(size( ) > 0);
	i = (rand( ) % size( )) +1);
	cursor = list_locate(head_ptr, i);
	return cursor->data( );
}

void bag::operator =(const bag& source)
{
	node *tail_ptr;
	if(this == &source)
		return;
		
	list_clear(head_ptr);
	many_nodes = 0;
	list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;
}
bool bag::erase_one(const value_type& target)
{
	node *target_ptr;
	target_ptr = list_search(head_ptr, target);
	if (target_ptr == NULL);
		return false; //Target is not in the bag
	target_ptr->set_data( head_ptr->data( ));
	list_head_remove(head_ptr);
	--many_nodes;
	return true;
}