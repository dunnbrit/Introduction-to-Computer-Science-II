/*********************************************************************
** Program name: main.cpp
** Author: group11
** Date: 5MAY2018
** Description: CS162 group project main file
*********************************************************************/

#include <iostream>
#include "Board.hpp"
#include "Menu.hpp"
#include "inputValidation.hpp"


int main ()
{
	srand(time(0));

	int numberGameSteps;
	int choice;
	int rows = 20;
	int cols = 20;
	int ants = 100;
	int bugs = 5;
	std::string userInput;
	Menu boardMenu("Extra Credit:");

	//Extra Credit menu
	boardMenu.addOptions("Customize board");
	boardMenu.addOptions("Default board");

	int boardChoice = boardMenu.buildMenu();

	if (boardChoice == 1)
	{
		//Get the number of rows
		rows = getInt("How many rows?", 2, 175);

		//Get the number of columns
		cols = getInt("How many columns?", 2, 175);
		
		//Get the number of ants
		int maxAnts = rows * cols - 1;
		ants = getInt("How many ants?", 1, maxAnts);

		//Get the number of doodlebugs
		int maxBugs = rows * cols - ants;
		bugs = getInt("How many doodlebugs?", 1, maxBugs);
	}

	Board gameBoard(rows, cols, ants, bugs);
	
	//Set the doodlebugs & ants
	gameBoard.randomDoodlebugs();
	gameBoard.randomAnts();
	
	//Run for number of steps and ask if user want to keep playing
	do
	{
		std::cout << std::endl;

		//Get number of steps to play
		numberGameSteps = getInt("How many time steps would you like to run?", 1, 500000);

		for (int i = 0; i < numberGameSteps; i++)
		{
			//Set the move flags for all critters to false
			gameBoard.resetMoveFlags();
			
			//Move the doodlebugs
			gameBoard.moveDoodlebugs();

			//Move the ants
			gameBoard.moveAnts();

			//Breed the doodlebugs
			gameBoard.breedDoodlebugs();

			//Breed all ants
			gameBoard.breedAnts();

			//Starve the doodlebugs
			gameBoard.starveDoodlebugs();

			//Print the board
			gameBoard.printBoard();

		}

		//Create play again menu
		Menu playAgain("Would you like to keep playing?");
		playAgain.addOptions("Yes");
		playAgain.addOptions("Exit Program");

		//Display menu and get the user's choice
		choice = playAgain.buildMenu();
	}
	while (choice == 1);

    return 0;
}
