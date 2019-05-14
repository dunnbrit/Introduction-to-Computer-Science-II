/***********************************************************************************
** Program name: Ant.hpp
** Author: Samantha Schrock
** Date: 5/5/18
** Description: This is the class specification file for the Ant class. It inherits
from the Critter class and represents an ant with functions to move and breed the ant.
***********************************************************************************/


#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"

class Ant : public Critter
{
	public:
		Ant(int, int);
		Ant(int, int, int);
		bool move(Critter***&, int, int) override;
		bool starve() override;
		void breed(Critter***&, int, int) override;
};
#endif

