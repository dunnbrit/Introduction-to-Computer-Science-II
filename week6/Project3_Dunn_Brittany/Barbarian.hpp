/*************************************************************************
 * Program Name: Barbarian.hpp
 * Author: Brittany Dunn
 * Date: May 13 2018
 * Description: This is the header file for the derived class Barbarian
 *************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian : public Character
{
	public:
		Barbarian();
		int attack() override;
		int defend(int) override;
};

#endif
