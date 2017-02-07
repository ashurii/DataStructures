#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "bag.h"
using namespace std;
using namespace main_savitch_3;
int main(int argc, char **argv)
{
	bag first_bag;
	bag second_bag;
	first_bag.insert(8);
	first_bag.insert(4);
	first_bag.insert(8);
	second_bag.insert(100);
	bag third_bag(first_bag);
	//bag first_bag += second_bag;
	
	bag ages;
	//get_ages(ages);
	//check_ages(ages);
	cout << "May your family live long" << endl;
	cout <<first_bag.size() <<endl;
	first_bag.erase_one(8);
	cout << first_bag.size() <<endl;
	
	return EXIT_SUCCESS;
}
