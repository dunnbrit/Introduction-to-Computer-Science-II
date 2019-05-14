/*********************************************************************
** Program name: Board.hpp
** Author: group11
** Date: 5MAY2018
** Description: CS162 group project - board class header file
*********************************************************************/



#ifndef BOARD_HPP
#define BOARD_CPP

#include "Critter.hpp"

class Board 
{
    private:
		int row;
		int col;
		int antCounter;
		int doodlebugCounter;
        Critter*** board;

    public:
        Board();
        Board(int, int, int, int);
        void printBoard();
        void randomAnts();
        void randomDoodlebugs();
        void moveAnts();
        void moveDoodlebugs();
		void starveDoodlebugs();
		void breedAnts();
		void breedDoodlebugs();
		void resetMoveFlags();
		~Board();
};

#endif