#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include "set5.h"

using namespace main_savitch_6B;
using namespace std;

int main(int argc, char **argv)
{
	set<int> set1;
	
	set1.set_insert(1);
	set1.set_insert(2);
	set1.set_insert(2);
	
	set<int> set2;
	set2.set_insert(2);
	set2.set_insert(3);
	
	set1 +=set2;
	set1.print( );
}
