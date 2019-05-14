/***********************************************************************************
** Program name: Doodlebug.cpp
** Author: Group 11
** Date: May 13 2018
** Description: This is the implementation file for the Doodlebug class with constructors
to create an ant with step counter of zero or as passed in the parameter and functions
to move and breed the ant.
***********************************************************************************/


#include "Doodlebug.hpp"
#include <cstdlib>


/***********************************************************************************
** Description: Constructor that creates a doodlebug with at a row and column as passed
in the parameters & sets the step counter to 0
***********************************************************************************/
Doodlebug::Doodlebug(int r, int c) : Critter(r , c, 'X')
{
	lastEat = 0;
}



/***********************************************************************************
** Description: Constructor that creates a doodlebug with at a row, column, step
counter, and last eat as passed in the parameters
***********************************************************************************/
Doodlebug::Doodlebug(int r, int c, int s, int l) : Critter(r, c, 'X', s)
{
	lastEat = l;
}



/***********************************************************************************
** Description: Function that checks for an ant to eat and move into its spot otherwise 
it randomly moves the doodle into an empty space adjacent to it or does nothing if 
all spaces full
***********************************************************************************/
bool Doodlebug::move(Critter***& board, int maxRow, int maxCol)
{
	//Check if ant up, eat and move if there
	if (row != 0)
	{
		if (board[row - 1][col] != nullptr)
		{
			if (board[row - 1][col]->getType() == 'O')
			{
				delete board[row - 1][col];
				
				//Increment the step counter
				stepCounter++;
				
				board[row - 1][col] = new Doodlebug(row - 1, col, stepCounter, 0);

				return true;
			}
		}	
	}
		
	//Check if ant down, eat and move if there
	if (row != maxRow)
	{
		if (board[row + 1][col] != nullptr)
		{
			if (board[row + 1][col]->getType() == 'O')
			{
				delete board[row + 1][col];

				//Increment the step counter
				stepCounter++;
				
				board[row + 1][col] = new Doodlebug(row + 1, col, stepCounter, 0);

				return true;
			}
		}
	}
	
	//Check if ant left, eat and move if there
	if (col != 0)
	{
		if (board[row][col - 1] != nullptr)
		{
			if (board[row][col - 1]->getType() == 'O')
			{
				delete board[row][col - 1];

				//Increment the step counter
				stepCounter++;
				
				board[row][col - 1] = new Doodlebug(row, col - 1, stepCounter, 0);

				return true;
			}
		}
	}
		
	//Check if ant right, eat and move if there
	if (col != maxCol)
	{
		if (board[row][col + 1] != nullptr)
		{
			if (board[row][col + 1]->getType() == 'O')
			{
				delete board[row][col + 1];

				//Increment the step counter
				stepCounter++;
				
				board[row][col + 1] = new Doodlebug(row, col + 1, stepCounter, 0);

				return true;
			}
		}
	}
	
	//If no ant to eat, try to move to empty space
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
	bool allDirections = false;

	do
	{
		int direction = rand() % 4 + 1;
			
		//Try to move up
		if (direction == 1)
		{
			//If up hasn't been tried before
			if (!up)
			{
				//If not at the edge, move the doodlebug if the space is empty
				if (row != 0)
				{
					if (board[row - 1][col] == nullptr)
					{
						//Increment eating counter	
						lastEat++;

						//Increment the step counter
						stepCounter++;

						board[row - 1][col] = new Doodlebug(row - 1, col, stepCounter, lastEat);

						return true;
					}
				}

				//Set the up flag to true
				up = true;
			}
		}	

		//Try to move down
		if (direction == 2)
		{
			//If down hasn't been tried before
			if (!down)
			{
				//If not at the edge, move the ant if the space is empty
				if (row != maxRow)
				{
					if (board[row + 1][col] == nullptr)
					{
						//Increment eating counter	
						lastEat++;

						//Increment the step counter
						stepCounter++;
							
						board[row + 1][col] = new Doodlebug(row + 1, col, stepCounter, lastEat);	
													
						return true;
					}
				}

				//Set the down flag to true
				down = true;
			}
		}

		//Try to move left
		if (direction == 3)
		{
			//If left hasn't been tried before
			if (!left)
			{
				//If not at the edge, move the doodlebug if the space is empty
				if (col != 0)
				{
					if (board[row][col - 1] == nullptr)
					{
						//Increment eating counter	
						lastEat++;

						//Increment the step counter
						stepCounter++;
							
						board[row][col - 1] = new Doodlebug(row, col - 1, stepCounter, lastEat);
							
						return true;	
					}
				}

				//Set the left flag to true
				left = true;
			}
		}

		//Try to move right
		if (direction == 4)
		{
			//If right hasn't been tried before
			if (!right)
			{
				//If not at the edge, move the doodlebug if the space is empty
				if (col != maxCol)
				{
					if (board[row][col + 1] == nullptr)
					{
						//Increment eating counter	
						lastEat++;
						
						//Increment the step counter
						stepCounter++;
						
						board[row][col + 1] = new Doodlebug(row, col + 1, stepCounter, lastEat);
							
						return true;
					}
				}

				//Set the right flag to true
				right = true;
			}
		}

		//If all directions have been tried, set the all directions flag to true
		if (up && down && left && right)
		{
			allDirections = true;
		}
	}
	while (!allDirections);

	//Increment eating counter	
	lastEat++;

	//Increment the step counter
	stepCounter++;

	return false;
}


/***********************************************************************************
** Description: Function that breeds the doodlebug into a empty space adjacent to it or
does nothing if all spaces full
***********************************************************************************/
void Doodlebug::breed(Critter***& board, int maxRow, int maxCol)
{
	if (stepCounter >= 8)
	{
		bool breed = false;
		bool up = false;
		bool down = false;
		bool left = false;
		bool right = false;
		bool allDirections = false;

		do
		{
			int direction = rand() % 4 + 1;

			//Try to breed up
			if (direction == 1)
			{
				//If up hasn't been tried before
				if (!up && !breed)
				{
					//If not at the edge, breed the ant if the space is empty
					if (row != 0)
					{
						if (board[row - 1][col] == nullptr)
						{
							board[row - 1][col] = new Doodlebug(row - 1, col);

							//Set breed flag to true
							breed = true;

							//Reset step counter to zero
							stepCounter = 0;
						}
					}
				}

				//Set the up flag to true
				up = true;
			}

			//Try to breed down
			if (direction == 2)
			{
				//If down hasn't been tried before
				if (!down && !breed)
				{
					//If not at the edge, breed the ant if the space is empty
					if (row != maxRow)
					{
						if (board[row + 1][col] == nullptr)
						{
							board[row + 1][col] = new Doodlebug(row + 1, col);
						
							//Set breed flag to true
							breed = true;

							//Reset step counter to zero
							stepCounter = 0;
						}
					}
				}

				//Set the down flag to true
				down = true;
			}

			//Try to breed left
			if (direction == 3)
			{
				//If left hasn't been tried before
				if (!left && !breed)
				{
					//If not at the edge, breed the ant if the space is empty
					if (col != 0)
					{
						if (board[row][col - 1] == nullptr)
						{
							board[row][col - 1] = new Doodlebug(row, col - 1);

							//Set breed flag to true
							breed = true;

							//Reset step counter to zero
							stepCounter = 0;
						}
					}
				}

				//Set the left flag to true
				left = true;
			}

			//Try to breed right
			if (direction == 4)
			{
				//If right hasn't been tried before
				if (!right && !breed)
				{
					//If not at the edge, breed the ant if the space is empty
					if (col != maxCol)
					{
						if (board[row][col + 1] == nullptr)
						{
				
							board[row][col + 1] = new Doodlebug(row, col + 1);
				
							//Set breed flag to true
							breed = true;

							//Reset step counter to zero
							stepCounter = 0;
						}
					}
				}

				//Set the right flag to true
				right = true;
			}

			//If all directions have been tried, set the all directions flag to true
			if (up && down && left && right)
			{
				allDirections = true;
			}

		} while (!allDirections);
	}
}



/*********************************************************************************
 *Description: Function that deletes a doodlebug if it has not eaten in 3 steps
 ******************************************************************************/
bool Doodlebug::starve()
{
	return lastEat == 3;
}

