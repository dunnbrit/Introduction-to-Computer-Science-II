/***********************************************************************************
** Program name: inputValidation.cpp
** Author: Samantha Schrock
** Date: 4/18/18
** Description: This functions takes a prompt and an min and max integer as parameters,
prints the prompt to the screen, takes the users input and validates that the input is 
an integer and is within the range specified.
****************************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include "inputValidation.hpp"



int getInt(std::string prompt, int min, int max)
{
	bool isValid = false;
	std::string input;
	int validInt;

	do
	{
		//Print prompt to screen & get user's input
		std::cout << prompt << std::endl;
		std::getline(std::cin, input);
		std::stringstream inputSStream(input);

		//Check if input is an integer
		if(inputSStream >> validInt && !(inputSStream >> input))
		{
			//Check if within range
			if (validInt < min || validInt > max)
			{
				std::cout << "input is not valid" << std::endl;
				std::cout << "You must enter an integer between " << min << " and " << max << ".";
				std::cout << std::endl;
			}

			else
			{
				isValid = true;
			}
		}

		else
		{
			std::cout << "input is not valid" << std::endl;
		}
	}
	while (isValid == false);

	return validInt;
}
