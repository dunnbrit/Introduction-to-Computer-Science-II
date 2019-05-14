/*************************************************************************
 * Program Name: Vampire.hpp
 * Author: Brittany Dunn
 * Date: May 13 2018
 * Description: This is the header file for the derived class Vampire
 *************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire : public Character
{
	public:
		Vampire();
		int attack() override;
		int defend(int) override;
};

#endif
