/*************************************************************************
 * Program Name: LoadedDie.cpp
 * Author: Brittany Dunn
 * Date: April 22 2018
 * Description: This is the implementation file for the derived class
 * LoadedDie.
 *************************************************************************/
#include "LoadedDie.hpp"
#include <iostream>
#include <string>

using std::string;

//This is the consructor for the loadedDie object
LoadedDie::LoadedDie(int n)
{
	N = n; 
}

int LoadedDie::rollDie()
{
	int min = N/2;
	int rolled;
	rolled = (rand() %(N - min + 1)) + min;
	return rolled;
}
	
