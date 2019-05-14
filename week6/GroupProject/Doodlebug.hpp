/***********************************************************************************
** Program name: Doodlebug.hpp
** Author: Group 11
** Date: May 13 2018
** Description: This is the class specification file for the Doodlebug class. It inherits
from the Critter class and represents an ant with functions to move and breed the ant.
***********************************************************************************/


#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug : public Critter
{
	private: 
		int lastEat;
	public:
		Doodlebug(int, int);
		Doodlebug(int, int, int, int);
		bool move(Critter***&, int, int) override;
		void breed(Critter***&, int, int) override;
		bool starve() override;
};
#endif

