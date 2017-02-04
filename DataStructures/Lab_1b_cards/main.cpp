// Created By Ashly Altman
// Data Structures Section 05

#include <iostream>
#include <iomanip>     // Provides setw function for setting output width
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <cassert>     // Provides assert function
#include <math.h>

using namespace std;

class Card
{
public:
	Card();
	int get_rank() const{return rank;}
	int get_suit() const{return suit;}
	void set_rank(int newRank)
	{
		if(newRank <= 13)
			rank = newRank;
		else
			rank = 1;
	}
	void set_suite(int newSuit)
	{
	suit = newSuit;
	}
private:
	int suit;
	int rank;
};
int main()
{
	char spades[] = "spades";
	char clubs[] = "clubs";
	char diamonds[] = "diamonds";
	char hearts[] = "hearts";
	
	
	Card newCard;
	newCard.set_rank(10);
	//newCard.set_suite("clubs");
	cout<< "Your card is " << newCard.get_rank();
	if(newCard.get_suit() == 1)
		cout<< " of " << spades<< endl;
	else if(newCard.get_suit() == 2)
		cout<< " of " << clubs<< endl;
	else if(newCard.get_suit() == 3)
		cout<< " of " << diamonds<< endl;
	else
		cout<< " of " << hearts<< endl;
}
Card::Card()
{
	rank = 1;
	suit = 1;
}
