/*************************************************************************
 * Program Name: Die.cpp
 * Author: Brittany Dunn
 * Date: April 22 2018
 * Description: This is the implementation file for the class Die.
 *************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include "Die.hpp"

using std::string;

//Constructors for Die object
Die::Die(int n)
{
	N = n;
}
//Constructor Used for loaded die
Die::Die()
{
	N = 0;
}

//This function generates a random number, checks it is less than or equal to
//the number of die sides and greater than 0 then returns the number
int Die::rollDie()
{
	int rolled;

	rolled = rand() % N + 1;

	return rolled;
}


