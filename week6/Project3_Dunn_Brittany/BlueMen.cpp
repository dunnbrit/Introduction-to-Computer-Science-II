/*************************************************************************
 * Program Name: BlueMen.cpp
 * Author: Brittany Dunn
 * Date: May 13 2018
 * Description: This is the implementation file for the derived class
 * BlueMen.
 *************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "BlueMen.hpp"

using std::cout;
using std::endl;

//This is the constructor for the class Barbarian
BlueMen::BlueMen()
{
	armor = 3;
	strength = 12;
	type = "Blue Men";
}

//This function gets the damage of an attack
int BlueMen::attack()
{
	int damage = 0;
	int roll = 0;

	//Roll 2 10-sided dice
	for(int i = 0; i < 2; ++i)
	{
		roll = (rand() % 10 + 1);
		cout << "Blue Men rolled " << roll << "." << endl;
		damage += roll;
	}
	
	return damage;
}

//This function takes the damage from an attacker and returns the damage 
//after the attack is defended	
int BlueMen::defend(int attack)
{
	//Determine number of die/mobs
	int mob = 0;
	if(strength < 5)
	{
		mob = 1;
	}
	else if(strength > 4 && strength < 9)
	{
		mob = 2;
	}
	else
	{
		mob = 3;
	}
	
	int defense = 0;
	int roll = 0;
	
	//Roll a 6-sided die for each mob
	for(int i = 0; i < mob; ++i)
	{
		roll = (rand() % 6 + 1);
		cout << "Blue Men rolled " << roll << " for mob "; 
		cout << (i+1) << "." << endl;
		defense += roll;
	}
	return (attack - defense);
}
