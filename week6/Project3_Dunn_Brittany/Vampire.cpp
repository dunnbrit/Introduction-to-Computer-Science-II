/*************************************************************************
 * Program Name: Vampire.cpp
 * Author: Brittany Dunn
 * Date: May 13 2018
 * Description: This is the implementation file for the derived class
 * Vampire.
 *************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Vampire.hpp"

using std::cout;
using std::endl;

//This is the constructor for the class Barbarian
Vampire::Vampire()
{
	armor = 1;
	strength = 18;
	type = "Vampire";
}

//This function gets the damage of an attack
int Vampire::attack()
{
	int roll = 0;
	roll = (rand() % 12 + 1);
	cout << "Vampire rolled " << roll << "." << endl;
	
	return roll;
}

//This function takes the damage from an attacker and returns the damage 
//after the attack is defended	
int Vampire::defend(int attack)
{
	int charm = 0;
	int roll = 0;
	
	//See if charm will be used
	charm = (rand() % 2 + 1);
	
	//Charm worked
	if(charm == 1)
	{
		cout << "Vampire charmed opponent into not attacking." << endl;
		attack = 0;
	}
	
	//Charm did not work
	else
	{
		roll = (rand() % 6 + 1);
		cout << "Vampire rolled " << roll << "." << endl;
		attack -= roll; 
	}
	
	return attack;
}
