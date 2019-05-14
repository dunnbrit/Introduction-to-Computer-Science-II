/*************************************************************************
 * Program Name: Game.hpp
 * Author: Brittany Dunn
 * Date: April 22 2018
 * Description: This is the header file forthe class Game.
 *************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"

class Game
{
	private:
		int rounds;
		int die1sides;
		int die2sides;
		int drawCounter = 0;
		int die1type;
		int die2type;
	public:
		void startGame();
		void roundWinner();
};
#endif
