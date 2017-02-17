#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "bag.h"
using namespace std;
using namespace main_savitch_3;
void get_ages(bag& ages)
{
    int user_input; // An age from the user's family

    cout << "Type the ages in your family. ";
    cout << "Type a negative number when you are done:" << endl;
    cin >> user_input;
    while (user_input >= 0)
    {
        ages.insert(user_input);
        cin >> user_input;
    }
}

void check_ages(bag& ages)
{
    int user_input; // An age from the user's family

    cout << "Type those ages again. Press return after each age:" << endl;
    while (ages.size( ) > 0)
    {
        cin >> user_input;
        if (ages.erase_one(user_input))
            cout << "Yes, I've got that age and have removed it." << endl;
        else
            cout << "No, that age does not occur!" << endl;
    }
}

int main(int argc, char **argv)
{
	bag first_bag;
	bag second_bag;
	first_bag.insert(8);
	first_bag.insert(4);
	first_bag.insert(8);
	second_bag.insert(100);
	bag third_bag(first_bag);
	first_bag += second_bag;
	
	bag ages;
	get_ages(ages);
	check_ages(ages);
	cout << "May your family live long" << endl;
	cout <<first_bag.size() <<endl;
	cout << "delete an age from the bag" << endl;
	first_bag.erase_one(8);
	cout << first_bag.size() <<endl;
	
	return EXIT_SUCCESS;
}
