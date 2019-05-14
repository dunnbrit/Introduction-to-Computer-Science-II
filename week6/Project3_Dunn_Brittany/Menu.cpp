/*************************************************************************
 * Program Name: Menu.cpp
 * Author: Brittany Dunn
 * Date: May 13 2018
 * Description: This is the implementation file for the Menu functions
 *************************************************************************/

#include <iostream>
#include <memory>
#include "Menu.hpp"
#include "Barbarian.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp" 
#include "HarryPotter.hpp"

using std::cout;
using std::cin;
using std::endl;

//This function displays the character menu
void displayCharacterMenu()
{
	cout << "Choose a character from the list: " << endl;
	cout << "1. Vampire" << endl;
	cout << "2. Barbarian" << endl;
	cout << "3. Blue Men" << endl;
	cout << "4. Medusa" << endl;
	cout << "5. Harry Potter" << endl;
	cout << "Please enter the number of your choice." << endl;
}

//This function displays the end menu
void displayEndMenu()
{
	cout << "Would you like to: " << endl;
	cout << "1. Play Again" <<endl;
	cout << "2. Exit Game" << endl;
	cout << "Please enter the number of your choice." << endl;
}

//This function takes the user's character choice and creates a character
//object of that type
std::shared_ptr<Character> characterChoice(int choice)
{
	std::shared_ptr<Character> character;
	switch(choice)
	{
		case 1:
		{
			character = std::make_shared<Vampire>();
			cout << "You have choosen Vampire." << endl;
			return character;
		}
			break;
		case 2:
		{	
			character = std::make_shared<Barbarian>();
			cout << "You have choosen Barbarian." << endl;
			return character;
		}
			break;
		case 3:
		{
			character = std::make_shared<BlueMen>();
			cout << "You have choosen Blue Men." << endl;
			return character;
		}
			break;
		case 4:
		{
			character = std::make_shared<Medusa>();
			cout << "You have choosen Medusa." << endl;
			return character;
		}
			break;
		case 5:
		{
			character = std::make_shared<HarryPotter>();
			cout << "You have choosen Harry Potter." << endl;
			return character;
		}
			break;
	}
}
