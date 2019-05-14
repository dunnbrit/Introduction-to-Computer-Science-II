/*************************************************************************
 * Program Name: Player.cpp
 * Author: Brittany Dunn
 * Date: April 22 2018
 * Description: This is the implementation file for the class Player
 *************************************************************************/
#include <iostream>
#include <string>
#include <memory>
#include "Player.hpp"

using std::shared_ptr;
using std::string;

//This is the constructor for the player object
Player::Player(shared_ptr<Die> ptrDie)
{
	ptr_die = ptrDie;	
	score = 0;
}






//This fuction calls the die oject function roll die and returns the 
//rolled number
int Player::getNumberRolled()
{
	return ptr_die->rollDie();

}

//This function adds 1 point to score
void Player::addPoint()
{
	score += 1;
}

//This function returns the player's score
int Player::getScore()
{
	return score;
}

