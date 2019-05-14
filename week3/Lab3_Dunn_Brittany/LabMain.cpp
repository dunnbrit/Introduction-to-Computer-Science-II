/*************************************************************************
 * Program Name: LabMain.cpp
 * Author: Brittany Dunn
 * Date: April 22 2018
 * Decription: This program runs a game simulation of a simplified
 * version of War using die.
 *************************************************************************/

#include <iostream>
#include "Game.hpp"
#include "Menu.hpp"
#include "getInt.hpp"
#include "Player.hpp"
#include "Die.hpp"
//#include "LoadedDie.hpp"

int main(int char**)
{
	//create Game object to use game functions
	Game game;
	
	//Begin game simulation
	game.startGame();

	return 0;
}
