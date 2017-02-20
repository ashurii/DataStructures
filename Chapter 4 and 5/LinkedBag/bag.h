#ifndef MAIN_SAVITCH_BAG_H  
#define MAIN_SAVITCH_BAG_H
#include <cstdlib> // Provides size_t and NULL
#include "node1.h"

//Invariant for the Link List Bag Class
//1. The items in the bag are stored in a linked list
//2. The head pointer of the list is stored in the member variable head_ptr
//3. The total number of items in the list is stored in the member variable many_nodes.

namespace main_savitch_5
{
class bag
{
public:
	typedef std::size_t size_type;
	typedef node::value_type value_type;
	bag();
	~bag();
	bag(const bag& source)  //Copy Constructor
	//Library facilities used: node1.h
	{
		node *tail_ptr;
		
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.many_nodes;
	}
		//CONSTANT MEMBER FUNCTIONS
	size_type size() const{ return many_nodes; }
	size_type count(const value_type& target) const;
	value_type grab( )const;
	//MODIFICATION MEMBER FUNCTIONS
	bool erase_one(const value_type& target);
	size_type erase(const value_type& target);
	void insert(const value_type& entry);
	
	//OPERATOR OVERLOADERS
	void operator +=(const bag& addend);
	void operator =(const bag& source);
	
private:
	node*  head_ptr;
	size_type many_nodes;
};
//Non Member functions for the bag class

bag operator +(const bag& b1, const bag& b2);
}
#endif // BAG_H
