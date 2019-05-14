/*************************************************************************
 * Program Name: Player.hpp
 * Author: Brittany Dunn
 * Date: April 22 2018
 * Description: This is the header file for the class Player
 *************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <memory>
#include "Die.hpp"
#include "LoadedDie.hpp"

class Player
{
	private:
		int score =0;
		std::shared_ptr<Die> ptr_die;		
	public:
		Player(std::shared_ptr<Die>); 
		int getNumberRolled();	
		int getScore();
		void addPoint();
};
#endif
