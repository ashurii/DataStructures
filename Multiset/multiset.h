#include <set>
#ifndef MULTISET_H
#define MULTISET_H

class multiset
{
public:
	multiset();
	
	typedef int value_type;
	typedef std::size_t size_type;
	static const size_type CAPACITY = 30;
	
	//CONSTANT MEMBER FUNCTIONS
	size_type size() const{ return used; }
	size_type count(const value_type& target) const;
	
	//MODIFICATION MEMBER FUNCTIONS
	get_ages(const multiset<int>& value) const;
	bool erase_one(const value_type& target);
	size_type erase(const value_type& target);
	void insert(const value_type& entry);
	
	//OPERATOR OVERLOADERS
	void operator +=(const multiset<int>& addend);

	
private:
	value_type data[CAPACITY];		// An array to store items
	size_type used;					// How much of the array is used
};

#endif // MULTISET_H
