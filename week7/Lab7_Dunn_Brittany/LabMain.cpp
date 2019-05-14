/*************************************************************************
 * Program Main: LabMain.cpp
 * Author: Brittany Dunn
 * Date: May 20 2018
 * Description: This program displays a menu and lets the user choose 
 * from 5 different options.
 *************************************************************************/

#include <iostream>
#include <string>
#include "QueueNode.hpp"
#include "Menu.hpp"
#include "getInt.hpp"
#include "Queue.hpp"

using std::cout;
using std::string;
using std::cin;
using std::endl;

int main()
{
	int choice;
	string temp1;
	string temp2;
	Queue queue;
	
	do
	{
	//Display menu
	displayMenu();

	//Get and validate choice
	cin >> temp1;
	temp2 = inputValid(temp1);
	while(temp2 == "invalid")
	{
		temp2 = inputInvalid();
	}
	choice = getInt(temp2);
	while(choice < 1 || choice > 5 )
	{
		temp2 = inputInvalid();
		while(temp2 == "invalid")
		{
			temp2 = inputInvalid();
		}
		choice = getInt(temp2);
	}

	//Perform next action based on choice
	menuChoice(choice, &queue);
	} 
	while(choice != 5);

	return 0;
}
