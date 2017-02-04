#include <stdio.h>
#include <iostream>
#include <iomanip>     // Provides setw function for setting output width
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <cassert>     // Provides assert function
#include <math.h>

using namespace std;

class PsuedoRandom
{
public:
	//Constructors
	PsuedoRandom();
	PsuedoRandom(int new_seed, int new_multiplier, int new_modulus, int new_increment);
	void set_Seed(int new_seed)
	{
		seed = new_seed;
	}
	int generate_PRandNum()
	{
		int pRandNum = 0;
		pRandNum =(multiplier*seed + increment) % mod;
		this->seed = pRandNum;
		return pRandNum;
	}
	int get_multiplier() const
	{
		return multiplier;
	}
	int get_increment() const
	{
		return increment;
	}
	int get_seed() const
	{
		return seed;
	}
	int get_mod() const
	{
		return mod;
	}
	double generatePRandNum2()
	{
		double rand = (double)generate_PRandNum();
		double new_seed = rand/((double)mod);
		return new_seed;
	}
private:
	int seed, multiplier, mod, increment;
};
int main()
{
	PsuedoRandom num1(1,40,729,725);
	PsuedoRandom num2(1,40,729,725);
	cout << "Initial Values\nSeed: " << num1.get_seed() << "\tMultiplier: " << num1.get_multiplier() << "\nModulus: " << num1.get_mod() << "\tIncrement: " << num1.get_increment() << endl;
	num1.generate_PRandNum();
	cout << "Second Values\nSeed: " << num1.get_seed() << "\tMultiplier: " << num1.get_multiplier() << "\nModulus: " << num1.get_mod() << "\tIncrement: " << num1.get_increment() << endl;
	num1.generate_PRandNum();
	cout << "Third Values\nSeed: " << num1.get_seed() << "\tMultiplier: " << num1.get_multiplier() << "\nModulus: " << num1.get_mod() << "\tIncrement: " << num1.get_increment() << endl;
	double new_seed = 0;
	new_seed = num2.generatePRandNum2();
	cout << "(0...1] random double:" << new_seed << endl;
}
PsuedoRandom::PsuedoRandom(int new_seed, int new_multiplier, int new_modulus, int new_increment)
{
	seed = new_seed;
	multiplier = new_multiplier;
	mod = new_modulus;
	increment = new_increment;
}
