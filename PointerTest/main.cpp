#include <stdio.h>
#include <iostream>


using namespace std;
int main(int argc, char **argv)
{
	int p = 0, k = 0;
	
	int *p_ptr = 0;
	
	*p_ptr = p;
	p = 4;
	
	cout << p << endl;
	
	k = p;
	
	cout << endl;
	cout << k <<endl;
}
