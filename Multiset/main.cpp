#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <set>
using namespace std;

void get_ages(multiset<int>& ages)
{
	
	int user_input;
	cout << "Enter your families ages." << endl;
	cout << "Enter negative number to finish" << endl;
	cin >> user_input;
	

	while(user_input >=0)
	{
		if(ages.size() < ages.max_size())
			ages.insert(user_input);
		else
			cout << "I have run out of room and can't add that age.";
		cin >> user_input;
	}
}
	
void check_ages(multiset<int>& ages)
{
	int user_input;
	cout <<"Type those again. Press return after each age:" << endl;
	while(ages.size() > 0)
	{
		cin >> user_input;
		if(true)
			cout << "Yes, I've found that age and removed it." << endl;
		else
			cout << "No, that age does not occur!" << endl;
		}
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
int main(int argc, char **argv)
{
//--------------------------
//Question 30 & 34
//--------------------------
	multiset<int> ages;
	multiset<int>::iterator it;
	
	multiset<double> num;
	num.insert(1);
	num.insert(2);
	num.insert(3);
	
	cout << "The average of 1,2,3 is:" << endl;
	cout << average(num) << endl;
	check_ages(ages);
	get_ages(ages);

	
int user_input;
	cout << "Enter your families ages." << endl;
	cout << "Enter negative number to finish" << endl;
	cin >> user_input;
	
	while(user_input >=0)
	{
		if(ages.size() < ages.max_size())
			ages.insert(user_input);
		else
			cout << "I have run out of room and can't add that age.";
		cin >> user_input;
	}
	for(it = ages.begin(); it != ages.end(); ++it)
		cout << *it << endl;
		
	cout <<" May your family live long and prosper."<< endl;




	
return EXIT_SUCCESS;
}


	
//-------------------------------------------------------------------------

