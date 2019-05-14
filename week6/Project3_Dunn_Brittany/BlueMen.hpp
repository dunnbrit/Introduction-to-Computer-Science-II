/*************************************************************************
 * Program Name: BlueMen.hpp
 * Author: Brittany Dunn
 * Date: May 13 2018
 * Description: This is the header file for the derived class BlueMen
 *************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"

class BlueMen : public Character
{
	public:
		BlueMen();
		int attack() override;
		int defend(int) override;
};

#endif
