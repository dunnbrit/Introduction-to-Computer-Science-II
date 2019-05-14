/*************************************************************************
 * Program Name: TestDriver.cpp
 * Author: Brittany Dunn
 * Date: May 13 2018
 * Description: This program is a combat game between two characters.
 *************************************************************************/

#include <iostream>
#include <string>
#include <memory>

#include "getInt.hpp"
#include "Menu.hpp"
#include "Universe.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	//Varibles used to make and validate user choice
	int choice = 0;
	string temp1 = "";
        string temp2 = "";

	//Run game once and then while player has choosen to keep playing
	do
	{
	//Create two character pointers to use in universe constructor later
	//and to create characters of the correct type
	std::shared_ptr<Character> characterA;
	std::shared_ptr<Character> characterB;	

	//Display character choice menu
	//Get first character
	displayCharacterMenu();

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
	
	//Create characterA character object
	characterA = characterChoice(choice);

	cin.ignore();
	
	//Display character choice menu
	//Get second character
	displayCharacterMenu();

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

	//Create characterB character object
	characterB = characterChoice(choice);

	//Create universe object
	Universe universe(characterA, characterB);

        //varible to track round number and game over
        int round = 1;
	bool gameOver;
	
	//Play game
	cout << "Starting game..." << endl;

	//Run game until game over
	do
	{	
	//Start Round 1
	cout << "Round " << round << ": " << endl;
	universe.firstRoundResults();
	round++;

	//Check defender is not dead
	if(universe.gameOver() == false)
	{
		//Start round 2
		cout << "Round " << round << ": " << endl;
		universe.secondRoundResults();
		round++;
	}
	
	//Check if defender is dead
	gameOver = universe.gameOver();

	}while(gameOver == false);		

	//display end menu
	displayEndMenu();
	
	//Get and validate choice
	cin >> temp1;
	temp2 = inputValid(temp1);
	while(temp2 == "invalid")
	{
		temp2 = inputInvalid();
	}
	choice = getInt(temp2);
	while(choice < 1 || choice > 2 )
	{
		temp2 = inputInvalid();
		while(temp2 == "invalid")
		{
			temp2 = inputInvalid();
		}
		choice = getInt(temp2);
	}

	}
	while(choice != 2);

	return 0;
}
	

