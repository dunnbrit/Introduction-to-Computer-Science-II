/*************************************************************************
 * Program Name: Barbarian.cpp
 * Author: Brittany Dunn
 * Date: May 13 2018
 * Description: This is the implementation file for the derived class
 * Barbarian.
 *************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Barbarian.hpp"

using std::cout;
using std::endl;

//This is the constructor for the class Barbarian
Barbarian::Barbarian()
{
	armor = 0;
	strength = 12;
	type = "Barbarian";
}

//This function gets the damage of an attack
int Barbarian::attack()
{
	int damage = 0;
	int roll = 0;

	//Roll 2 6-sided dice
	for(int i = 0; i < 2; ++i)
	{
		roll = (rand() % 6 + 1);
		cout << "Barbarian rolled " << roll << "." << endl;
		damage += roll;
	}
	
	return damage;
}

//This function takes the damage from an attacker and returns the damage 
//after the attack is defended	
int Barbarian::defend(int attack)
{
	int defense = 0;
	int roll = 0;
	
	//Roll 2 6-sided dice
	for(int i = 0; i < 2; ++i)
	{
		roll = (rand() % 6 + 1);
		cout << "Barbarian rolled " << roll << "." << endl;
		defense += roll;
	}
	return (attack - defense);
}
