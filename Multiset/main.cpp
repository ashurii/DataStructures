#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <set>

using namespace std;
int main(int argc, char **argv)
{
//--------------------------
//Question 30
//--------------------------
	multiset<int> ages;
	multiset<int>::iterator it;
	//get_ages(ages);
	//check_ages(ages);
	ages.insert(10);
	ages.insert(20);
	ages.insert(30);
	for(it = ages.begin(); it != ages.end(); ++it)
		cout << *it << endl;
		
	cout <<" May your family live long and prosper."<< endl;
//-----------------------------------------------
// QUESTION 34
//-----------------------------------------------

	multiset<double> num;
	num.insert(1);
	num.insert(2);
	num.insert(3);
	
	cout << "The average number is:\n";
	cout << average(num);
	
return EXIT_SUCCESS;
}

double average(const multiset<double>& num)
{
	multiset<double>::iterator it2;
	double sum;
	double average;
	for(it2 = num.begin(); it2 != num.end(); ++it2)
		sum+= *it2;
	average = sum/num.size();
	return average;
	}
	
//-------------------------------------------------------------------------
/*void get_ages(const multiset<int>& ages)
{
	int user_input;
	cout << "Enter your families ages." << endl;
	cout << "Enter negative number to finish" << endl;
	cin >> user_input;
	
	while(user_input >=0)
		if(ages.size() < ages.CAPACITY)
			ages.insert(user_input);
		else
			cout << "I have run out of room and can't add that age."
		cin >> user_input;
	}
	
void check_ages(const multiset<int>& ages)
{
	int user_input;
	cout <<"Type those again. Press return after each age:" << endl;
	while(ages.size() > 0)
	{
		cin >> user_input;
		if(ages.erase_one(user_input))
			cout << "Yes, I've found that age and removed it." << endl;
		else
			cout << "No, that age does not occur!" << endl;
		}
	}*/