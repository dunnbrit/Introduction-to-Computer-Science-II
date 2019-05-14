/*************************************************************************
 * Program Name: startGame.cpp
 * Author: Brittany Dunn
 * Date: April 15 2018
 * Description: This is the implementation file for the function startGame.
 *************************************************************************/
#include <iostream>
#include <string>
#include "getInt.hpp"
#include "Ant.hpp"

using std::string;
using std::cout;
using std::endl;
using std::cin;

// This function prompts the user to enter the number of rows,columns,and
// steps and the starting row and column of the ant. It uses the users
// inputed information to create a dynamatic 2D array and an Ant object.
// It then calls the Ant class function startSimulation to begin the
// simulation.
void startGame()
{
	//Varibles to store user entered information
	int row;
	int column;
	int steps;
	int startRow;
	int startColumn;
	string temp;
	string temp2;
	//Get information from user
	
	//Get the number of Rows from user
	cout << "Please enter the number of rows for the board." << endl;
	cin >> temp;	
	//Validate rows is an integer greater than 0
	temp2 = inputValid(temp);
	while(temp2 == "invalid")
	{	
		temp2 = inputInvalid();
	}
	row = getInt(temp2);
	while(row <= 0)
	{
		temp2 = inputInvalid();
		while(temp2 == "invalid")
		{
			temp2 = inputInvalid();
		}
		row = getInt(temp2);
	}

	//Get the number of columns from user
	cout << "Please enter the number of columns for the board." << endl;
	cin >> temp;
	//Validate columns is an integer greater than 0
	temp2 = inputValid(temp);
	while(temp2 == "invalid")
	{
		temp2 = inputInvalid();
	}	
	column = getInt(temp2);
	while(column <= 0)
	{
		temp2 = inputInvalid();
		while(temp2 == "invalid")
		{
			temp2 = inputInvalid();
		}
		column = getInt(temp2);
	}

	//Get the number of steps
	cout << "Please enter the number of steps for simulation." <<endl;
	cin >> temp;
	//Validate steps is an integer greater than 0
	temp2 = inputValid(temp);
	while(temp2 == "invalid")
	{
		temp2 = inputInvalid();
	}
	steps = getInt(temp2);
	while(steps <= 0 || steps > 250)
	{
		temp2 = inputInvalid();
		while(temp2 == "invalid")
		{
			temp2 = inputInvalid();
		}
		steps = getInt(temp2);
	}
	
	//Get the starting row
	cout << "Please enter the starting row of the ant." << endl;
	cin >> temp;
	//Valid starting row is an integer greater than 0 and less
	//than the number of rows 
	temp2 = inputValid(temp);
	while(temp2 == "invalid")
	{
		temp2 = inputInvalid();
	}
	startRow = getInt(temp2);
	//Subract on to account for array starting at 0;first ant should
	//appear where user would expect
	startRow -= 1;
	while(startRow < 0 || startRow >= row)
	{
		temp2 = inputInvalid();
		while(temp2 == "invalid")
		{
			temp2 = inputInvalid();
		}
		startRow = getInt(temp2);
		startRow -= 1;
	}

	//Get the starting column
	cout << "Please enter the starting column of the ant." << endl;
	cin >> temp;
	//Validate starting column is an integer greater than 0 and less 
	//than the number of columns
	temp2 = inputValid(temp);
	while(temp2 == "invalid")
	{	
		temp2 = inputInvalid();
	}
	startColumn = getInt(temp2);
	//Subtract 1 to account for array starting at 0
	startColumn -= 1;
	while(startColumn < 0 || startColumn >= column)
	{
		temp2 = inputInvalid();
		while(temp2 == "invalid")
		{
			temp2 = inputInvalid();
		}
		startColumn = getInt(temp2);
		startColumn -= 1;
	}
	
	//Dynamatically create 2D array which will be used as the board
	char **board = new char*[row];
	{
		for(int i = 0; i < row; ++i)
		{
			board[i] = new char[column];
		}
	}
	
	//Create Board object
	Board ant(row,column,startRow,startColumn,steps,board);

	//Start simulation
	ant.startSimulation();
	
	//Free dynamatically allocated memory for 2D array
	for(int i = 0; i < row; ++i)
	{
		delete [] board[i];
	}
	delete [] board;
	board = NULL;
} 
