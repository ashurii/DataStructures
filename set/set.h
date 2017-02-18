//INVARIANT for the set class:
//	1. The number of items in the set is the member variable used.
//	2.	There can only be one instance of each item in the set.
//	3.	For an empty set we don't care about the contents; for a non empty set, the items are 
//		stored in data[0] through data[used-1], and we don't care what's in the rest.
//	Time Analysis: all operations are O(n)
#ifndef MAIN_SAVITCH_SET_H
#define MAIN_SAVITCH_SET_H
#include <cstdlib>


namespace main_savitch_3
{
class set
{
public:
	
	typedef int value_type;
	typedef std::size_t size_type;
	static const size_type DEFAULT_CAPACITY = 30;

	set(size_type initial_capacity = DEFAULT_CAPACITY);
	set(const set& source);
	~set();
	//CONSTANT MEMBER FUNCTIONS
	size_type size() const{ return used; }
	bool contains(const value_type& target) const;
	//MODIFICATION MEMBER FUNCTIONS
	bool erase_one(const value_type& target);
	size_type erase(const value_type& target);
	void insert(const value_type& entry);
	
	//OPERATOR OVERLOADERS
	void operator +=(const set& addend);
	void operator =(const set& source);
	
private:
	value_type *data;
	size_type used;					// How much of the array is used
	size_type capacity;
};
// Non member functions for the set class
set operator +(const set& s1, const set& s2);
set operator -(const set& s1, const set& s2);
}


#endif // set_H
