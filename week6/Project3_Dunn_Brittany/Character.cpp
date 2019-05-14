/*************************************************************************
 * Program Name: Character.cpp
 * Author Name: Brittany Dunn
 * Date: May 13 2018
 * Description: This is the implementation file for the base class
 * Character.
 *************************************************************************/

#include <string>
#include "Character.hpp"

using std::string;

//This function returns the character's armor
int Character::getArmor()
{
	return armor;
}

//This function returns the character's strength
int Character::getStrength()
{
	return strength;
}

//This function returns the chartacter's type
string Character::getType()
{
	return type;
}

//This function applies the total damage from an attack
void Character::applyDamage(int damage)
{
	strength -= damage;
}

