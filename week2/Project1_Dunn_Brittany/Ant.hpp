/*************************************************************************
 * Program Name: Ant.hpp
 * Author: Brittany Dunn
 * Date: April 15 2018
 * Description: This is the header file for the class Board.
 *************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

class Board
{
	private: 
		int rows;
		int columns;
		int maxRow;
		int maxColumn;		
		char color;
		enum Direction{NORTH,SOUTH,EAST,WEST};
		void changeDirectionRight();
		void changeDirectionLeft();
		Direction antFacing;
		int steps;
		int currentStep;
		char** gameboard;
		void makeMove();
	public:
		Board(int,int,int,int,int,char**);
		void printBoard();
		void startSimulation();
};
#endif
