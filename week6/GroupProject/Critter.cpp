/***********************************************************************************
** Program name: Critter.cpp
** Author: Samantha Schrock
** Date: 5/5/18
** Description: This is the implementation file for the Critter class with constructors
to create a critter with a step counter of zero or as passed to the contrustor and
functions get the type and get the step counter
***********************************************************************************/


#include "Critter.hpp"


/***********************************************************************************
** Description: Constructor that creates a critter with a row and column as passed
in the parameters & sets the step counter to 0
***********************************************************************************/
Critter::Critter(int r, int c, char t)
{
	row = r;
	col = c;
	stepCounter = 0;
	type = t;
	moveFlag = true;
}



/***********************************************************************************
** Description: Constructor that creates a critter with at a row, column and step
counter as passed in the parameters
***********************************************************************************/
Critter::Critter(int r, int c, char t, int s)
{
	row = r;
	col = c;
	stepCounter = s;
	type = t;
	moveFlag = true;
}



/***********************************************************************************
** Description: Function that does nothing in critter
***********************************************************************************/
bool Critter::starve()
{
	return false;
}



/***********************************************************************************
** Description: Function sets the move flag to false
***********************************************************************************/
void Critter::resetMoveFlag()
{
	moveFlag = false;
}



/***********************************************************************************
** Description: Function returns the critter's move flag
***********************************************************************************/
bool Critter::getMoveFlag()
{
	return moveFlag;
}


/***********************************************************************************
** Description: Function that returns the type of critter
***********************************************************************************/
char Critter::getType()
{
	return type;
}



/***********************************************************************************
** Description: Function that returns the critter's step counter
***********************************************************************************/
int Critter::getStepCounter()
{
	return stepCounter;
}


/***********************************************************************************
** Description: Destructor
***********************************************************************************/
Critter::~Critter()
{
}
