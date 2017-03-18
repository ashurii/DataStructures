// FILE: set4.h (part of the namespace main_savitch_6A)
// TEMPLATE CLASS PROVIDED: set<item>
//
// TEMPLATE PARAMETER, TYPEDEFS and MEMBER CONSTANTS for the set<Item> class:
//   The template parameter, Item, is the data type of the items in the set,
//   also defined as set<Item>::value_type. It may be any of the C++ built-in
//   types (int, char, etc.), or a class with a default constructor, an
//   assignment operator, and operators to test for equality (x == y) and 
//   non-equality (x != y). The definition set<Item>::size_type is the data type
//   of any variable that keeps track of how many items are in a set. The static
//   const DEFAULT_CAPACITY is the initial capacity of a set created by the
//   default constructor.
// NOTE:
//   Many compilers require the use of the new keyword typename before using
//   the expressions set<Item>::value_type and set<Item>::size_type. Otherwise
//   the compiler doesn't have enough information to realize that it is the
//   name of a data type.
//
// CONSTRUCTOR for the set<Item> template class:
//   set(size_type initial_capacity = DEFAULT_CAPACITY)
//     Postcondition: The set is empty with an initial capacity given by the
//     parameter. The insert function will work efficiently (without allocating
//     new memory) until this capacity is reached.
//
// MODIFICATION MEMBER FUNCTIONS for the set<Item> template class:
//   size_type erase(const Item& target)
//     Postcondition: All copies of target have been removed from the set. The
//     return value is the number of copies removed (which could be zero).
//
//   bool erase_one(const Item& target)
//     Postcondition: If target was in the set, then one copy of target has
//     been removed; otherwise the set is unchanged. A true return value
//     indicates that one copy was removed; false indicates that nothing was
//     removed.
//
//   void insert(const Item& entry)
//     Postcondition: A new copy of entry has been added to the set.
//
//   void operator +=(const set<Item>& addend)
//     Postcondition: Each item in addend has been added to this set.
//
//   void reserve(size_type new_capacity)
//     Postcondition: The set's current capacity is changed to new_capacity
//     (but not less than the number of items currently in the set). The insert
//     function will work efficiently without allocating new memory) until the
//     capacity is reached.
//
// CONSTANT MEMBER FUNCTIONS for the set<Item> template class:
//   size_type count(const Item& target) const
//     Postcondition: Return value is number of times target is in the set.
//
//   Item grab( ) const
//     Precondition: size( ) > 0
//     Postcondition: The return value is a randomly selected item from the set.
//
//   size_type size( ) const
//     Postcondition: The return value is the total number of items in the set.
//
// NONMEMBER FUNCTIONS for the set<Item> template class:
//   template <class Item>
//   set<Item> operator +(const set<Item>& b1, const set<Item>& b2)
//     Postcondition: The set returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the set<Item> template class:
//   Assignments and the copy constructor may be used with set objects.
//
// DYNAMIC MEMORY USAGE by the set<Item> template class: 
//   If there is insufficient dynamic memory, then the following functions call
//   new_handler: the constructors, resize, insert, operator += , operator +,
//   and the assignment operator.

#ifndef MAIN_SAVITCH_set4_H
#define MAIN_SAVITCH_set4_H
#include <cstdlib> // Provides size_t
#include "node1.h"

namespace main_savitch_6A
{
    template <class Item>
    class set
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
	typedef Item value_type;
	typedef std::size_t size_type;
	static const size_type DEFAULT_CAPACITY = 30;
        // CONSTRUCTORS and DESTRUCTOR
        set(size_type initial_capacity = DEFAULT_CAPACITY);
        set(const set& source);
        ~set( );
        // MODIFICATION MEMBER FUNCTIONS
        size_type erase(const Item& target);
        bool erase_one(const Item& target);
        void insert(const Item& entry);
        void operator =(const set& source);
        void operator +=(const set& addend);
        void reserve(size_type capacity);
        // CONSTANT MEMBER FUNCTIONS
	void print_set() const;
	size_type size() const{ return many_nodes; }
	bool contains(const Item& target) const;
    private:
	node*  head_ptr;
	node* tail_ptr;
	size_type many_nodes;
    };

    // NONMEMBER FUNCTIONS
    template <class Item>
    set<Item> operator +(const set<Item>& s1, const set<Item>& s2);
}

#include "set4.template"  // Include the implementation
#endif