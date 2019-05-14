/*************************************************************************
 * Program Name: Project1Main.cpp
 * Author: Brittany Dunn
 * Date: April 15 2018
 * Description: This programs runs a Langton's ant simulation.
 *************************************************************************/

#include <iostream>
#include "Menu.hpp"
#include "startGame.hpp"
#include "getInt.hpp"
#include "Ant.hpp"
#include <string>

using std::string;
using std::cin;

int main()
{
	char choice;

	do
	{
	//Display the Start Menu
	displayStartMenu();

	//Get user's choice
	cin.clear();
	choice = cin.get();
	cin.ignore(100,'\n');
	//Use choice with menu to begin next step	
	menuChoice(choice);

	}
	while(choice != '1' && choice != '2');	

	while(choice == '1')
	{
		do
		{
		//Display end menu
		displayEndMenu();
	
		//Get user's choicei
		cin.clear();
		choice = cin.get();
		cin.ignore(100,'\n');
	
		//Use choice with menu to begin next step
		menuChoice(choice);
	
		}
		while(choice != '1' &&  choice != '2');
	}
	return 0;
}
