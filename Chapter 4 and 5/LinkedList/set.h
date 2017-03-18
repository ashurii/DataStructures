#ifndef MAIN_SAVITCH_set_H  
#define MAIN_SAVITCH_set_H
#include <iostream>
#include <cstdlib> // Provides size_t and NULL
#include "node1.h"

//Invariant for the Link List set Class
//1. The items in the set are stored in a linked list
//2. The head pointer of the list is stored in the member variable head_ptr
//3. The total number of items in the list is stored in the member variable many_nodes.
//4. The set can only contain one copy of an item

namespace main_savitch_5
{
template <class Item>
class set
{
public:
	typedef Item Item;
	typedef std::size_t size_type;
	set();
	~set();
	set(const set& source)  //Copy Constructor
	//Library facilities used: node1.h
	{
		node *tail_ptr;
		
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.many_nodes;
	}
		//CONSTANT MEMBER FUNCTIONS
	void print_set() const;
	size_type size() const{ return many_nodes; }
	bool contains(const Item& target) const;
	Item grab( )const;
	//MODIFICATION MEMBER FUNCTIONS
	bool erase_one(const Item& target);
	size_type erase(const Item& target);
	void set_insert(const Item& entry);
	
	//OPERATOR OVERLOADERS
	void operator +=(const set& addend);
	void operator =(const set& source);
	friend std::ostream& operator << (std::ostream& out, const set& s);
private:
	node*  head_ptr;
	node* tail_ptr;
	size_type many_nodes;
};
//Non Member functions for the set class
   
    template <class Item>
    set<Item> operator +(const set<Item>& s1, const set<Item>& s2);
}

#include "set4.template"  // Include the implementation
#endif
