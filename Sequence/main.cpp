
#include <cstdlib>  // Provides size_t
#include <iostream>
#include "sequence.h"

using namespace std;
using namespace main_savitch_3;
int main(int argc, char **argv)
{
	sequence seq1;
	int user_input;
	int count;
	cout << "enter 3 numbers" << endl;
	
	do{
		cin >> user_input;
		++count;
		}while(count < 3);
	cout << "Your numbers are:" << endl;
	for(int i =0; i < seq1.size( ); ++i){
		cout << seq1.get_data(i) << endl;
		seq1.advance();
	}
		return 0;
}