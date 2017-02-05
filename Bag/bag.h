//File bag.h
//CLASS PROVIDED: bag(part of the namespace main_savitch_3
//
// TYPEDEFS and MEMBER CONSTANTS for the bag class:
//	typedef__ value_type
//		bag::value_type is the data type of the items in the bag. It may be any of the C++
//		build-in types(int, char, etc.), or a class with a default constructor, and assignment
//		operator, and operators to test for equality (x == y) and no-equality (x != y).
//	typedef __size_type
//		bag::size_type is the data type of any variable that keeps track of how many items are in a bag
//
//	VALUE SEMANTICS for the bag class:
//	Assignments and the copy contructor may be used with bag objects.


#ifndef MAIN_SAVITCH_BAG_H
#define MAIN_SAVITCH_BAG_H
#include <cstdlib>


namespace main_savitch_3
{
class bag
{
public:
	bag();
	typedef int value_type;
	typedef std::size_t size_type;
	static const size_type CAPACITY = 30;
	//CONSTANT MEMBER FUNCTIONS
	size_type size() const{ return used; }
	size_type count(const value_type& target) const;
	//MODIFICATION MEMBER FUNCTIONS
	bool erase_one(const value_type& target);
	size_type erase(const value_type& target);
	void insert(const value_type& entry);
	
	//OPERATOR OVERLOADERS
	void operator +=(const bag& addend);

	
private:
	value_type data[CAPACITY];		// An array to store items
	size_type used;					// How much of the array is used
};
// Non member functions for the bag class
bag operator +(const bag& b1, const bag& b2);
}


#endif // BAG_H
