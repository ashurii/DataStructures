#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include "node1.h"

using namespace std;
using namespace main_savitch_5;

node* user_Input()
{
	//Postcondition: Takes inputs from user to popute a linked list.
	node::value_type user_input = 0;
	node* linked_list1 = NULL;
	
	cout << "Enter doubles to populate a linked list.\n enter -1 to end the list." << endl;
	while(user_input != -1)
	{
		cin >> user_input;
		if(user_input != -1)
			list_head_insert(linked_list1, user_input);
	}
	return linked_list1;
}

void list_sort(node*& head_ptr)
{
	//	Precondition: head_ptr is a head pointer of a linked list of items
	//	compared with a less-than operator.
	//	Postcondition: head_ptr points to the head of a linked list with exactly the same entries
	//	(including repitions if any), but the entries in this list_sort
	//	are sorted from smallest to largest. The original linked list is no longer available.
	node* cursor;
	node* sorted_list = NULL;
	node* largest_node = head_ptr;
	
	while(head_ptr != NULL)
	{
		largest_node = head_ptr;
		for(cursor = head_ptr; cursor != NULL; cursor = cursor->link())
		{
			if(cursor->data( ) > largest_node->data())						//Find node with the largest item of all the nodes in original list
			{
					largest_node = cursor;
			}	
		}
		list_head_insert(sorted_list, largest_node->data( ));				//Insert this node at the head of the new list
		largest_node->set_data(head_ptr->data( ));
		list_head_remove(head_ptr);											//
	}
	head_ptr = sorted_list;
}
void delete_repetitions(node*& head_ptr)
{
	//Precondition: values can be compared with == operator
	//Post Condition: duplicate nodes removed from the list
	node* cursor;
	node* dup;

	node::value_type duplicates = 0;
		
	for(cursor= head_ptr->link( ); cursor != NULL; cursor = cursor->link()) //Cycle through list after the head of the list
	{
		
		
		if(cursor->link() != NULL)									//If we haven't reached the end of the list
			dup = list_search(cursor->link( ), cursor->data( ));	//search list starting at cursor->link( ) for a node with data that matches cursor->data( )
																	//If no matching node found, dup set to NULL, otherwise, dup set to the matching node
		if(dup != NULL)	
		{
			++duplicates;
			dup->set_data(head_ptr->data( ));						//The data in the duplicate node is set to the head_ptr data, creating a duplicate of the head pointer
			list_head_remove(head_ptr);								//The head pointer is removed, leaving one value
			cursor = head_ptr;
		}
	}
	cout << "The number of duplicates was:\t" << duplicates << endl;
	dup = list_search(head_ptr->link( ), head_ptr->data( ));		//Check the head one more time for duplicate value
	if(dup != NULL);
		list_head_remove(head_ptr);									//If duplicate found, remove head

}

void split(node*& head_ptr)
{
	//Precondition: item values can be compared using the < operator
	//Postcondition: The procedure divides the nodes into two linked lists:
	//One containing all the nodes that contain an item less than the splitting value,
	//and one that contains all the other nodes. If the original linked list had any
	//repeated integers (ie, any two or more nodes with the same item in them)
	//then the new linked list that has this item should have the same number 
	//of nodes that repeat this item. 
	node* less_than_split;
	node* target;
	node* cursor;
	node* less_than_tail;
	node::value_type splitting_value;
	
	cout << "Enter a value where you want to split your list:" << endl;
	cin >> splitting_value;
	
	cursor = head_ptr;
	list_copy(head_ptr, less_than_split, less_than_tail);

	if(head_ptr->data( ) < splitting_value)
	{
		list_head_remove(head_ptr);
	}

	for(cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	{
		if(cursor->data( ) < splitting_value)						//Checks if data of the node is less than the split value
		{
			target = list_search(head_ptr, cursor->data( ));		//Make the target node pointer point to the node that matches the cursor data
			target->set_data(head_ptr->data( ));					//overwrite the target data with the current head pointer data, creating duplicate of head pointer
			list_head_remove(head_ptr);								//remove the duplicate head pointer from original list
		}
		else
		{
			target = list_search(less_than_split, cursor->data( ));		//Make the target node pointer point to the node that matches the cursor data
			target->set_data(less_than_split->data( ));					//overwrite the target data with the current head pointer data, creating duplicate of head pointer
			list_head_remove(less_than_split);							//remove the duplicate head pointer from original list
		}
	}
	


	
	cout << "Values less than split value " << splitting_value << ": " << endl;
	for(cursor = less_than_split; cursor != NULL; cursor = cursor->link( ))
		cout << cursor->data( ) << ", ";
		
	cout << endl;
	cout << endl;
	cout << "The rest of the values: ";
	for(cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
		cout << cursor->data( ) << ", ";
}
int main(int argc, char **argv)
{
	
	node *linked_list;
	node *cursor;
	
	
	linked_list = user_Input();
	int co = 0;
	for(cursor = linked_list; cursor != NULL; cursor = cursor->link())
	{
		cout << cursor ->data() << ", ";
		co++;
		
	}
	cout << endl;
	cout << endl;
	list_sort(linked_list);
	
	cout << "The sorted list:" << endl;
	for(cursor = linked_list; cursor != NULL; cursor = cursor->link())
		cout << cursor ->data() << ", ";
		
	cout << endl;
	cout << endl;
	delete_repetitions(linked_list);

	
	for(cursor = linked_list; cursor != NULL; cursor = cursor->link())
		cout << cursor ->data() << ", ";

	cout<< endl;
	cout<< endl;
	
	split(linked_list);
	
	return EXIT_SUCCESS;
}
