/*************************************************************************
 * Program Name: LoladedDie.hpp
 * Author: Brittany Dunn
 * Date: April 22 2018
 * Description: This is the header for the derived class LoadedDie.
 *************************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include <string>
#include "Die.hpp"

class LoadedDie : public Die
{
	public:
		LoadedDie(int);
		int rollDie() override;
};
#endif
