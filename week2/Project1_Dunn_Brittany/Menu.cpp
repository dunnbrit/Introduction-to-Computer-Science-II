/*************************************************************************
 * Program Name: Menu.cpp
 * Author: Brittany Dunn
 * Date: April 15 2018
 * Description: This is the implementation file for the Menu functions.
 *************************************************************************/
#include <iostream>
#include "startGame.hpp"
#include <string>
using std::string;
using std::string;
using std::cout;
using std::endl;
using std::cin;

//This function displays the start menu on console
void displayStartMenu()
{
	cout << "1. Start" << endl;
	cout << "2. Quit" << endl;
	cout << "Please enter the number of your choice." << endl;
}

//This function displays the end menu on console
void displayEndMenu()
{
	cout << "1. Play Again" << endl;
	cout << "2. Quit" << endl;
	cout << "Please enter the number of your choice." <<endl;
}

//This function takes the choice input by the user and uses a switch 
//statement to determine next action
void  menuChoice(char choice)
{

	switch(choice)
	{
		case '1': startGame();
			break;
		case '2': 
			break;
		default: cout << "You did not enter 1 or 2.";
			cout << " Returning to menu." << endl;
			break;
	}
}
