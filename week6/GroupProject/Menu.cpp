/*****************************************************************************************
** Program name: Menu.cpp
** Author: Samantha Schrock
** Date: 4/8/18
** Description: This is the implementation file for the Menu class with a default constructor to
create a Menu with an empty title, a constructor to create a Menu with a title, and functions
to add menu options and build the menu.
****************************************************************************************/


#include <sstream>
#include "Menu.hpp"


/****************************************************************************************
** Description: Default constructor creates a Menu with a blank title.
*****************************************************************************************/
Menu::Menu()
{
	menuTitle = "";
}



/****************************************************************************************
** Description: This constructor creates a Menu with a title as passed in the string
parameter.
*****************************************************************************************/
Menu::Menu(std::string titleIn)
{
	menuTitle = titleIn;
}



/****************************************************************************************
** Description: This function sets a menu's title.
*****************************************************************************************/
void Menu::setTitle(std::string titleIn)
{
	menuTitle = titleIn;
}


/****************************************************************************************
** Description: This function adds an option to the menu by adding the string passed in 
the parameter to the menu's vector.
*****************************************************************************************/
void Menu::addOptions(std::string optionIn)
{
	menuOptions.push_back(optionIn);
}



/****************************************************************************************
** Description: This function builds the menu with the title entered (if any), and the
options in the vector, prints the menu to the screen, accepts the user's input, validates
the input, and returns the value of the input.
*****************************************************************************************/
int Menu::buildMenu()
{
	bool isValid = false;
	std::string input;
	int choice;

	//Print the menu title
	std::cout << menuTitle << std::endl;

	//Print the options & get the user's choice
	int menuSize = menuOptions.size();
	for (int count = 0; count < menuSize; count++)
	{
		std::cout << count + 1 << ". " << menuOptions[count] << std::endl;
	}

	std::cout << std::endl;

	//Perform input validation
	do
	{
		std::cout << "Please select an option: ";
		std::getline(std::cin, input);
		std::stringstream inputSStream(input);

		if (inputSStream >> choice && !(inputSStream >> input))
		{
			//Check if within options range
			if(choice < 1 || choice > menuSize)
			{
				std::cout << "input is not valid" << std::endl;
				std::cout << "You must select an option between 1 and " << menuSize << std::endl;
				std::cout << std::endl;
			}

			else
			{
				isValid = true;
			}
		}	

		else
		{
			std::cout << "input is not valid" << std::endl << std::endl;
		}
	}
	while (isValid == false);

	return choice;
}
