/*************************************************************************
 * Program Name: Ant.cpp
 * Author: Brittany Dunn
 * Date: April 15 2018
 * Description: This is the implementation file for the class Ant.
 *************************************************************************/

#include "Ant.hpp"
#include <iostream>

using std::cout;
using std::endl;

//This is the constructor for the class Board. It accepts 5 int
//and 1 char 2D array as parameters.
Board::Board(int r, int c, int sr, int sc, int s, char** board)
{
	//Intialize all data members
	maxRow = r;
	maxColumn = c;
	rows = sr;
	columns = sc;
	steps = s;
	gameboard = board;
	//Intialize 2D array to all white spaces (' ')
	for(int row = 0; row < maxRow; ++row)
	{
		for(int col = 0; col < maxColumn; ++col)
		{
			gameboard[row][col] = ' ';
		}
	}
	//Place ant in starting location
	gameboard[rows][columns] = '*';
	//Intialize data members
	color = ' ';
	antFacing = NORTH;
	currentStep = 0;

}

//This fuction prints the 2D board array
void Board::printBoard()
{
	cout << "\n";

	for(int row = 0; row < maxRow; ++row)
	{
		cout << "|";
		for(int col = 0; col < maxColumn; ++col)
		{
			cout << gameboard[row][col];
		}
		cout << "|";
		cout << endl;
	}
}

//This function changes the direction the ant is facing to 90 degrees left.
void  Board::changeDirectionLeft()
{

	switch(antFacing)
	{
		case NORTH: antFacing = WEST;
			break;
		case WEST: antFacing = SOUTH;
			break;
		case SOUTH: antFacing = EAST;
			break;
		case EAST: antFacing = NORTH;
			break;
	}

}

//This fuction changes the direction the ant is facing to 90 degrees right.
void Board::changeDirectionRight()
{
	switch(antFacing)
	{
		case NORTH: antFacing = EAST;
			break;
		case EAST: antFacing = SOUTH;
			break;
		case SOUTH: antFacing = WEST;
			break;
		case WEST: antFacing = NORTH;
			break;
	}
}

//This function moves the ant following Langton's Rules
void Board::makeMove()
{
	//If the space the ant on is white the ant follows these directions
	if(color == ' ')
	{
		//Change the current space to black
		gameboard[rows][columns] = '#';
		//Rotate the ant 90 degrees right
		changeDirectionRight();
		//Move the ant forward one space in the new direction
		switch(antFacing)
		{
			case NORTH: 
				rows -= 1;
				break;
			case EAST:
				columns += 1;
				break;
			case SOUTH:
				rows += 1;
				break;
			case WEST:
				columns -= 1;
				break;
		}
	}
	//If the space the ant is on is black the ant follows these directions
	if(color == '#')
	{
		//Change the current space to white
                gameboard[rows][columns] = ' ';
		//Rotate the ant 90 degrees left
                changeDirectionLeft();
		//Store the change need to move the ant forward one space in
		//the new direction
                switch(antFacing)
                {
                        case NORTH:
                        	rows -= 1;
                                break;
                        case EAST:        
                                columns += 1;
                                break;
                        case SOUTH:
                                rows += 1;
                                break;
                        case WEST:
                                columns -= 1;
                                break;
                }
	}
	//If the ant will go off the board return the ant to the top left
	//corner of the board. Ant does not change direction 
	if(rows >= maxRow || rows < 0 ||columns >= maxColumn || columns < 0)
	{
		rows = 0;
		columns = 0;
	}
	//Record the color of the space the ant will move to. This determines
	//next move
	color = gameboard[rows][columns];
	//Move the ant forward one space
	gameboard[rows][columns] = '*';
}
				
//This function starts the Langton's ant simulation
void Board::startSimulation()
{
	//Run simulation for the number of steps specified by the user
	//Print the board after each step
	while(currentStep < steps)
	{
		makeMove();
		printBoard();
		++currentStep;
	}
}
