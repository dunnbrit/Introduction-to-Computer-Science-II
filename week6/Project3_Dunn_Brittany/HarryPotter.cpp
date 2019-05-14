/*************************************************************************
 * Program Name: HarryPotter.cpp
 * Author: Brittany Dunn
 * Date: May 13 2018
 * Description: This is the implementation file for the derived class
 * HarryPotter.
 *************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "HarryPotter.hpp"

using std::cout;
using std::endl;

//This is the constructor for the class Barbarian
HarryPotter::HarryPotter()
{
	armor = 0;
	strength = 10;
	type = "Harry Potter";
	lives = 1;
}

//This function gets the damage of an attack
int HarryPotter::attack()
{
	int damage = 0;
	int roll = 0;

	//Roll 2 6-sided dice
	for(int i = 0; i < 2; ++i)
	{
		roll = (rand() % 6 + 1);
		cout << "Harry Potter rolled " << roll << "." << endl;
		damage += roll;
	}
	
	return damage;
}

//This function takes the damage from an attacker and returns the damage 
//after the attack is defended	
int HarryPotter::defend(int attack)
{
	int defense = 0;
	int roll = 0;
	int damage = 0;	

	//Roll 2 6-sided dice
	for(int i = 0; i < 2; ++i)
	{
		roll = (rand() % 6 + 1);
		cout << "Harry Potter rolled " << roll << "." << endl;
		defense += roll;
	}

	//Calculate damage
	damage = attack - defense;
	
	//If this is Harry's first live and the damage would have killed
	//him then use Hogwarts
	if(lives == 1 && (strength - damage) <= 0)
	{
		cout << "Harry Potter used Hogwarts.";
		cout << " Harry has fully recovered from damage";
		cout << " and his strength is now 20." << endl;
		strength = 20;
		--lives;
		damage = 0;
	}
	
	return damage;
}

