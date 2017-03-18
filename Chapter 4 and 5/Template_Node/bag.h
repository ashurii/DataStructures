#ifndef BAG_H
#define BAG_H

namespace main_savitch_6B{
template <class Item>
class bag
{
public:
	//TYPEDEFS
	typedef node_iterator<Item> iterator;
	typedef const_node_iterator<Item> const_iterator;
	
	//FUNCTIONS TO PROVIDE ITERATORS
	iterator begin( ){ return iterator(head_ptr);}
	const_iterator begin( ) const{ return const_iterator( head_ptr);}
	iterator end( ) { return iterator( );}
	const iterator end( ) {return const_iterator( );}
private:
	node<Item> *head_ptr;
	size_type many_nodes;

};
}
#endif // BAG_H
