/*************************************************************************
 * Program Name: Universe.cpp
 * Author: Brittany Dunn
 * Date: May 13 2018
 * Description: This is the implementation file for the class Universe
 *************************************************************************/

#include <iostream>
#include <string>
#include <memory>
#include "Universe.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"

using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;

//This is the constructor for the class Universe
Universe::Universe(shared_ptr<Character>& a, shared_ptr<Character>& b)
{
	characterA = a;
	characterB = b;
}

//This function calls the functions and displays the results of the first
//attack/defense
void Universe::firstRoundResults()
{
	int attack = 0;
	int defense = 0;
	int damage = 0;

	//Display characters info
	cout << "Attacker Type: " << characterA->getType() << endl;
	cout << "Defender Type: " << characterB->getType() << endl;
	cout << "        Armor: " << characterB->getArmor() <<endl;
	cout << "     Strength: " << characterB->getStrength() << endl;

	//Character A attacks
	attack = characterA->attack();
	cout << characterA->getType() << " attacked " << characterB->getType();
	cout << " with an attack of " << attack << " points." <<endl;

	//Character B defends
	defense = characterB->defend(attack);
	cout << characterB->getType() << " defended "; 
	cout <<	characterA->getType() << "'s attack causing " << defense;
	cout << " points of damage after " <<  characterB->getType();
	cout << "'s defense." << endl;

	//Total damage
	damage = defense - (characterB->getArmor());
	cout << "Because of " << characterB->getType() << "'s armor";
	cout << ", the total damage was ";
	//Account for possible negative damage because armor
	//if damage is negative make it 0
	if(damage < 0)
	{ 
		damage = 0;
	} 
	cout <<	damage << " points." << endl;
	
	//Apply damage and get strength
	characterB->applyDamage(damage);
	cout << characterB->getType() << "'s strength is currently ";
	cout << characterB->getStrength() << endl;
}	
//This function calls the functions and displays the results of the second
//attack/defense
void Universe::secondRoundResults()
{
	int attack = 0;
	int defense = 0;
	int damage = 0;
	
	//Display characters info
	cout << "Attacker Type: " << characterB->getType() << endl;
	cout << "Defender Type: " << characterA->getType() << endl;
	cout << "        Armor: " << characterA->getArmor() <<endl;
	cout << "     Strength: " << characterA->getStrength() << endl;

	//Character A attacks
	attack = characterB->attack();
	cout << characterB->getType() << " attacked " << characterA->getType();
	cout << " with an attack of " << attack << " points." <<endl;
	
	//Character B defends
	defense = characterA->defend(attack);
	cout << characterA->getType() << " defended ";
	cout << characterB->getType() << "'s attack causing " << defense;
	cout << " points of damage after " <<  characterA->getType();
	cout << "'s defense." << endl;

	//Total damage
	damage = defense - (characterA->getArmor());
	cout << "Because of " << characterA->getType() << "'s armor";
	cout << ", the total damage was ";
	//Account for possible negative damage because armor
	//if damage is negative make it 0
	if(damage < 0)
	{
		damage = 0;
	}
	cout << damage << " points." << endl;

	//Apply damage and get strength
	characterA->applyDamage(damage);
	cout << characterA->getType() << "'s strength is currently ";
	cout << characterA->getStrength() << endl;
}

//This function returns true if a character has died
bool Universe::gameOver()
{
	bool game = false;;
	if(characterA->getStrength() <= 0)
	{
		game = true;
	}
	if(characterB->getStrength() <= 0)
	{
		game = true;
	}
	
	return game;
}
		
