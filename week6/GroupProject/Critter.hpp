/***********************************************************************************
** Program name: Critter.hpp
** Author: Samantha Schrock
** Date: 5/5/18
** Description: This is the class specification file for the Critter class. It
represents a critter with a row, column, step counter, and character type. It has
functions to get the type and get the step counter.
***********************************************************************************/


#ifndef CRITTER_HPP
#define CRITTER_HPP


class Critter
{
	protected:
		int stepCounter;
		int row;
		int col;
		char type;
		bool moveFlag;

	public:
		Critter(int, int, char);
		Critter(int, int, char, int);
		virtual bool move(Critter***&, int, int) = 0;
		virtual void breed(Critter***&, int, int) = 0;
		virtual bool starve() = 0;
		void resetMoveFlag();
		bool getMoveFlag();
		char getType();
		int getStepCounter();
		virtual ~Critter();
};
#endif

