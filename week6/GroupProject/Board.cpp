/*********************************************************************
** Program name: Board.cpp
** Author: group11
** Date: 5MAY2018
** Description: CS162 group project - board class implementation file
*********************************************************************/


#include "Board.hpp"
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

/*********************************************************************
Description: Default constructor that creates a 20x20 grid of Critter
pointers
*********************************************************************/
Board::Board()
{
	antCounter = 100;
	doodlebugCounter = 5;

	row = 20;
	col = 20;

	board = new Critter**[row];

    for(int i = 0; i < row; i++)
	{
        board[i] = new Critter*[col];
    }

    //Fills all spaces with nullptrs
    for(int j = 0; j < row; j++)
	{   
    	for(int k = 0; k < col; k++)
		{        
            board[j][k] = nullptr;
        }
    }
}


/*********************************************************************
Description: Constructor that creates a grid of pointers using
values passed in the parameters
*********************************************************************/
Board::Board(int r, int c, int a, int d)
{
	antCounter = a;
	doodlebugCounter = d;

	row = r;
	col = c;
	
	board = new Critter**[row];

    for(int i = 0; i < row; i++)
	{
        board[i] = new Critter*[col];
    }

    //Fills all elements with null pointers
    for(int j = 0; j < row; j++)
	{
        for(int k = 0; k < col; k++)
		{
            board[j][k] = nullptr;
        }
    }
}



/*********************************************************************
Description: prints the game board. Nullptr prints to a space, else
prints doodlebug or ant characters
*********************************************************************/
void Board::printBoard()
{
	std::string decoration(col + 2, '-');
	
	//Top border
	std::cout << decoration << std::endl;

    //Print the board
    for(int i = 0; i < row; i++)
	{
		std::cout << '|';

		for(int j = 0; j < col; j++)
		{
			if (board[i][j] == nullptr)
			{
				std::cout << ' ';
			}

			else
			{
				std::cout << board[i][j]->getType();
			}
			
        }
        
    	std::cout << '|' << std::endl;
    }

    //Bottom Border
    std::cout << decoration << std::endl << std::endl;

}



/*********************************************************************
Description: Spawns ants randomly on game board
*********************************************************************/
void Board::randomAnts()
{
	while (antCounter > 0)
	{
		int r = rand() % row + 0;
		int c = rand() % col + 0;

		if (board[r][c] == nullptr)
		{
			board[r][c] = new Ant(r, c);

			//Decrement ant counter
			antCounter--;
		}
	}
}



/*********************************************************************
Description: Spawns doodlebugs randomly on game board
*********************************************************************/
void Board::randomDoodlebugs()
{
	while (doodlebugCounter > 0)
	{
		int r = rand() % row + 0;
		int c = rand() % col + 0;

		if (board[r][c] == nullptr) 
		{
			board[r][c] = new Doodlebug(r, c);

			//Decrement doodlebug counter
			doodlebugCounter--;
		}
	}
}



/*********************************************************************
Description: Moves ants on board using move function
*********************************************************************/
void Board::moveAnts()
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			//If element is ant, move it
			if (board[i][j] != nullptr)
			{
				if (board[i][j]->getType() == 'O' && board[i][j]->getMoveFlag() == false)
				{
					bool moved = board[i][j]->move(board, row - 1, col - 1);
					
					if (moved)
					{
						delete board[i][j];
						board[i][j] = nullptr;
					}
				}
            }
        }
    }
}



/*********************************************************************
Description: Moves doodlebugs on board using move function
*********************************************************************/
void Board::moveDoodlebugs()
{
	for(int i = 0; i < row; i++)
	{ 
        for(int j = 0; j < col; j++)
		{
			//If element is doodlebug, move it
			if (board[i][j] != nullptr)
			{
				if (board[i][j]->getType() == 'X' && board[i][j]->getMoveFlag() == false)
				{
					bool moved = board[i][j]->move(board, row - 1, col - 1);

					if (moved)
					{
						delete board[i][j];
						board[i][j] = nullptr;
					}
				}
			}  
        }
    }
}



/*********************************************************************
Description: Calls the starve function on the doodlebugs on the board
which will delete a doodlebug if it hasn't eatin in 3 steps
*********************************************************************/
void Board::starveDoodlebugs()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			//If element is not empty, call the starve function
			if (board[i][j] != nullptr)
			{
				bool starved = board[i][j]->starve();

				if (starved)
				{
					delete board[i][j];
					board[i][j] = nullptr;
				}
			}
		}
	}
}



/*********************************************************************
Description: Function that calls the breed function for all doodlebugs
on the board
*********************************************************************/
void Board::breedDoodlebugs()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			//If element is either critter, call the breed function
			if (board[i][j] != nullptr)
			{
				if (board[i][j]->getType() == 'X')
				{
					board[i][j]->breed(board, row - 1, col - 1);
				}
			}
		}
	}
}



/*********************************************************************
Description: Function that calls the breed function for all ants
on the board
*********************************************************************/
void Board::breedAnts()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			//If element is either critter, call the breed function
			if (board[i][j] != nullptr)
			{
				if (board[i][j]->getType() == 'O')
				{
					board[i][j]->breed(board, row - 1, col - 1);
				}
			}
		}
	}
}



/*********************************************************************
Description: Function that resets the move flags for all critters on the
board to false
*********************************************************************/
void Board::resetMoveFlags()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			//If space isn't empty, reset the move flag to false
			if (board[i][j] != nullptr)
			{
				board[i][j]->resetMoveFlag();
			}
		}
	}
}


/*********************************************************************
Description: Destructor frees the dynamicallly allocated memory
*********************************************************************/
Board::~Board()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			delete board[i][j];
		}

		delete[] board[i];
	}

	delete[] board;
	board = nullptr;
}
