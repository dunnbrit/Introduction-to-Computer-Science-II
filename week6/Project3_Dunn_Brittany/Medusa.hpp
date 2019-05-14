/*************************************************************************
 * Program Name: Medusa.hpp
 * Author: Brittany Dunn
 * Date: May 13 2018
 * Description: This is the header file for the derived class Medusa
 *************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character
{
	public:
		Medusa();
		int attack() override;
		int defend(int) override;
};

#endif
