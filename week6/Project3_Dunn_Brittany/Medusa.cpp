/*************************************************************************
 * Program Name: Medusa.cpp
 * Author: Brittany Dunn
 * Date: May 13 2018
 * Description: This is the implementation file for the derived class
 * Medusa.
 *************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Medusa.hpp"

using std::cout;
using std::endl;

//This is the constructor for the class Barbarian
Medusa::Medusa()
{
	armor = 3;
	strength = 8;
	type = "Medusa";
}

//This function gets the damage of an attack
int Medusa::attack()
{
	int damage = 0;
	int roll = 0;

	//Roll 2 6-sided die
	for(int i = 0; i < 2; ++i)
	{
		roll = (rand() % 6 + 1);
		cout << "Medusa rolled " << roll << "." << endl;
		damage += roll;
	}

	//Glare
	if(damage == 12)
	{
		cout << "Medusa used glare. ";
		cout << "Target has been turned to stone." << endl;
		//Make damage high enough to kill target
		damage = 100;
	}

	return damage;
}

//This function takes the damage from an attacker and returns the damage 
//after the attack is defended	
int Medusa::defend(int attack)
{
	int roll = 0;
	roll = (rand() % 6 + 1);
	cout << "Medusa rolled " << roll << "." << endl;
	attack -= roll; 
	
	return attack;
}
