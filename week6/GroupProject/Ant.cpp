/***********************************************************************************
** Program name: Ant.cpp
** Author: Samantha Schrock
** Date: 5/5/18
** Description: This is the implementation file for the Ant class with constructors
to create an ant with step counter of zero or as passed in the parameter and functions
to move and breed the ant.
***********************************************************************************/


#include "Ant.hpp"
#include <cstdlib>


/***********************************************************************************
** Description: Constructor that creates an ant with at a row and column as passed
in the parameters & sets the step counter to 0
***********************************************************************************/
Ant::Ant(int r, int c) : Critter(r , c, 'O')
{
}



/***********************************************************************************
** Description: Constructor that creates a ant with at a row, column and step
counter as passed in the parameters
***********************************************************************************/
Ant::Ant(int r, int c, int s) : Critter(r, c, 'O', s)
{
}



/***********************************************************************************
** Description: Function that randomly moves the ant into an empty space adjacent to
it or does nothing if all spaces full
***********************************************************************************/
bool Ant::move(Critter***& board, int maxRow, int maxCol)
{
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
				//If not at the edge, move the ant if the space is empty
				if (row != 0)
				{
					if (board[row - 1][col] == nullptr)
					{
						//Increment the step counter
						stepCounter++;

						board[row - 1][col] = new Ant(row - 1, col, stepCounter);

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
						//Increment the step counter
						stepCounter++;

						board[row + 1][col] = new Ant(row + 1, col, stepCounter);

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
				//If not at the edge, move the ant if the space is empty
				if (col != 0)
				{
					if (board[row][col - 1] == nullptr)
					{
						//Increment the step counter
						stepCounter++;
						
						board[row][col - 1] = new Ant(row, col - 1, stepCounter);

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
				//If not at the edge, move the ant if the space is empty
				if (col != maxCol)
				{
					if (board[row][col + 1] == nullptr)
					{
						//Increment the step counter
						stepCounter++;

						board[row][col + 1] = new Ant(row, col + 1, stepCounter);

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

	//Increment the step counter
	stepCounter++;

	return false;
}



/***********************************************************************************
** Description: Function returns false for starving
***********************************************************************************/
bool Ant::starve()
{
	return Critter::starve();
}


/***********************************************************************************
** Description: Function that breeds the ant into a empty space adjacent to it or
does nothing if all spaces full
***********************************************************************************/
void Ant::breed(Critter***& board, int maxRow, int maxCol)
{
	if (stepCounter >= 3)
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
							board[row - 1][col] = new Ant(row - 1, col);

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
							board[row + 1][col] = new Ant(row + 1, col);

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
							board[row][col - 1] = new Ant(row, col - 1);

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

							board[row][col + 1] = new Ant(row, col + 1);

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
