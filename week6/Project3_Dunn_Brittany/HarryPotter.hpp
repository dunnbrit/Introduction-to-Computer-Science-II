/*************************************************************************
 * Program Name: HarryPotter.hpp
 * Author: Brittany Dunn
 * Date: May 13 2018
 * Description: This is the header file for the derived class Harry Potter
 *************************************************************************/

#ifndef HARYYPOTTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"

class HarryPotter : public Character
{
	private:
		int lives;
	public:
		HarryPotter();
		int attack() override;
		int defend(int) override;
};

#endif
