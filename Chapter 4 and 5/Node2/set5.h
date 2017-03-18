// FILE: set5.h (part of the namespace main_savitch_chapter6)
// TEMPLATE CLASS PROVIDED:
//   set<Item> (a collection of items; each item may appear multiple times)
//
// TYPEDEFS for the set<Item> template class:
//   set<Item>::value_type
//     This is the Item type from the template parameter.
//     It is the data type of the items in the set. It may be any 
//     of the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, a copy constructor, an assignment
//     operator, and a test for equality (x == y).
//
//   set<Item>::size_type
//     This is the data type of any variable that keeps track of how many items
//     are in a set
//
//   set<Item>::iterator and set<Item>::const_iterator
//     Forward iterators for a set or a const set.
//   
// CONSTRUCTOR for the set<Item> class:
//   set( )
//     Postcondition: The set is empty.
//
// MODIFICATION MEMBER FUNCTIONS for the set<Item> class:
//   size_type erase(const Item& target)
//     Postcondition: All copies of target have been removed from the set.
//     The return value is the number of copies removed (which could be zero).
//
//   bool erase_one(const Item& target)
//     Postcondition: If target was in the set, then one copy of target has
//     been removed from the set; otherwise the set is unchanged. A true
//     return value indicates that one copy was removed; false indicates that
//     nothing was removed.
//
//   void insert(const Item& entry) 
//     Postcondition: A new copy of entry has been inserted into the set.
//
//   void operator +=(const set& addend) 
//     Postcondition: Each item in addend has been added to this set.
//
// CONSTANT MEMBER FUNCTIONS for the set<Item> class:
//   size_type count(const Item& target) const 
//     Postcondition: Return value is number of times target is in the set.
//
//   Item grab( ) const 
//     Precondition: size( ) > 0.
//     Postcondition: The return value is a randomly selected item from the set.
//
//   size_type size( ) const 
//     Postcondition: Return value is the total number of items in the set.
//
// STANDARD ITERATOR MEMBER FUNCTIONS (provide a forward iterator):
//   iterator begin( )
//   const_iterator begin( ) const
//   iterator end( )
//   const iterator end( ) const
//
// NONMEMBER FUNCTIONS for the set<Item> class:
//   template <class Item>
//   set<Item> operator +(const set<Item>& b1, const set<Item>& b2) 
//     Postcondition: The set returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the set<Item> class:
//    Assignments and the copy constructor may be used with set objects.
//
// DYNAMIC MEMORY USAGE by the set<Item>: 
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: The constructors, insert, operator +=, operator +, and the
//   assignment operator.

#ifndef MAIN_SAVITCH_set5_H
#define MAIN_SAVITCH_set5_H
#include <cstdlib>   // Provides NULL and size_t and NULL
#include "node2.h"   // Provides node class

namespace main_savitch_6B
{
    template <class Item>
    class set
    {
    public:
        // TYPEDEFS
	typedef std::size_t size_type;
        typedef Item value_type;
	typedef node_iterator<Item> iterator;
	typedef const_node_iterator<Item> const_iterator;
	
        // CONSTRUCTORS and DESTRUCTOR
        set( );
        set(const set& source);
        ~set( );
	
        // MODIFICATION MEMBER FUNCTIONS
        size_type erase(const Item& target);
        bool erase_one(const Item& target);
        void set_insert(const Item& entry);
        void operator +=(const set& addend);
        void operator =(const set& source);
	
        // CONST MEMBER FUNCTIONS
        bool contains(const Item& target) const;
        Item grab( ) const;
        size_type size( ) const { return many_nodes; }
		void print();
	
	// FUNCTIONS TO PROVIDE ITERATORS
	iterator begin( )
	    { return iterator(head_ptr); }
	const_iterator begin( ) const
	    { return const_iterator(head_ptr); }
	iterator end( )
	    { return iterator( ); } // Uses default constructor 
	const_iterator end( ) const
	    { return const_iterator( ); } // Uses default constructor 

    private:
        node<Item> *head_ptr;        // Head pointer for the list of items
        size_type many_nodes;        // Number of nodes on the list
    };

    // NONMEMBER functions for the set
    template <class Item>
    set<Item> operator +(const set<Item>& b1, const set<Item>& b2);
}

// The implementation of a template class must be included in its header file:
#include "set5.template"
#endif
