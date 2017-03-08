#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include "node1.h"

using namespace std;
using namespace main_savitch_5;

void delete_repetitions(node*& head_ptr)
{
	//Precondition: values can be compared with == operator
	//Post Condition: duplicate nodes removed from the list
	node* cursor;
	node* dup;

	node::value_type duplicates = 0;
	dup = list_search(head_ptr->link( ), head_ptr->data( ));
	if(dup != NULL)
	{
	if(head_ptr->data( ) == dup->data())
		list_head_remove(head_ptr);
	}

		
	for(cursor= head_ptr->link( ); cursor != NULL; cursor = cursor->link())
	{
		
		
		if(cursor->link() != NULL)									//If we haven't reached the end of the list
			dup = list_search(cursor->link( ), cursor->data( ));	//search list starting at cursor->link( ) for a node with data that matches cursor->data( )
																	//If no matching node found, dup set to NULL, otherwise, dup set to the matching node
		if(dup != NULL)	
		{
			++duplicates;
			dup->set_data(head_ptr->data( ));						//The data in the duplicate node is set to the head_ptr data, craeting a duplicate of the head pointer
			list_head_remove(head_ptr);								//The head pointer is removed, leaving one value
			
		}
	}
	cout << "The number of duplicates was:\t" << duplicates << endl;
	dup = list_search(head_ptr->link( ), head_ptr->data( ));
	if(dup != NULL)
	{
	if(head_ptr->data( ) == dup->data())
		list_head_remove(head_ptr);
	}
	
}

void split(node*& head_ptr, node::value_type splitting_value)
{
	//Precondition: item values can be compared using the < operator
	//Postcondition: The procedure divides the nodes into two linked lists:
	//One containing all the nodes that contain an item less than the splitting value,
	//and one that contains all the other nodes. If the original linked list had any
	//repeated integers (ie, any two or more nodes with the same item in them)
	//then the new linked list that has this item should have the same number 
	//of nodes that repeat this item. 
	node* less_than_split;
	node* the_rest = head_ptr;
	node* cursor;
	

	
	for(cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	{
		if(cursor->data( ) < splitting_value)
		{
			list_head_insert(less_than_split, cursor->data( ));
			
		}
		else
		{
			list_head_insert(the_rest, cursor->data( ));
		}
	}


	
	cout << "Values less than split value " << splitting_value << ": " << endl;
	for(cursor = less_than_split; cursor != NULL; cursor = cursor->link( ))
		cout << cursor->data( ) << ", ";
		
	cout << endl;
	cout << endl;
	cout << "The rest of the values: ";
	for(cursor = the_rest; cursor != NULL; cursor = cursor->link( ))
		cout << cursor->data( ) << ", ";
}
int main(int argc, char **argv)
{
	
	node *linked_list;
	node *cursor;
	
	node::value_type num1 = 2, num2 = 4, num3 = 2, num4 = 1, num5 = 2, num6 = 1, num7 = 2;
	list_head_insert(linked_list, num1);
	list_head_insert(linked_list, num2);
	list_head_insert(linked_list, num3);
	list_head_insert(linked_list, num4);
	list_head_insert(linked_list, num5);
	list_head_insert(linked_list, num6);
	list_head_insert(linked_list, num7);
	
	
	for(cursor = linked_list; cursor != NULL; cursor = cursor->link())
		cout << cursor ->data() << ", ";
	cout<< endl;
	cout<< endl;
	
	delete_repetitions(linked_list);

	
	for(cursor = linked_list; cursor != NULL; cursor = cursor->link())
		cout << cursor ->data() << ", ";

	cout<< endl;
	cout<< endl;
	
	split(linked_list, 2);
	return EXIT_SUCCESS;
}
