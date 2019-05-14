/*************************************************************************
 * Program Name: Menu.cpp
 * Author: Brittany Dunn
 * Date: April 22 2018
 * Description: This is the implementation file for the Menu functions.
 *************************************************************************/
#include <iostream>
#include <string>
#include "Menu.hpp"

using std::string;
using std::endl;
using std::cin;
using std::cout;

//This function displays the start menu on console
void displayStartMenu()
{
	cout << "1. Play Game" << endl;
	cout << "2. Quit Game" << endl;
	cout << "Please enter the number of your choice." << endl;
}

//This function takes the choice input by the user and uses a switch
//statement to determine the next action
void menuChoice(char choice)
{
	switch(choice)
	{
		case '1': break;
		case '2': break;
		default: cout << "You did not enter 1 or 2.";
			cout << " Returning to menu." << endl;
			break;
	}
} 

