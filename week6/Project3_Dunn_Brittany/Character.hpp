/*************************************************************************
 * Program Name: Character.hpp
 * Author: Brittany Dunn
 * Date: May 13 2018
 * Description: This is the header file for the base class Character
 *************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

class Character
{
	protected:
		int armor;
		int strength;
		std::string type;

	public:
		virtual ~Character() = default;
		virtual int attack() = 0;
		virtual int defend(int) = 0;
		int getArmor();
		int getStrength();
		std::string getType();
		void applyDamage(int);
};

#endif

