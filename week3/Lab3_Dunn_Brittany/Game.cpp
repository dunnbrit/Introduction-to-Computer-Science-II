/*************************************************************************
 * Program Name: Game.cpp
 * Author: Brittany Dunn
 * Date: April 22 2018
 * Description: This is the implementation file for the class Game.
 *************************************************************************/

#include <iostream>
#include <string>
#include <memory>
#include "Menu.hpp"
#include "Game.hpp"
#include "getInt.hpp"
#include "Player.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"

using std::shared_ptr;
using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::make_shared;

//This function begins the game
void Game::startGame()
{
	//Holds user's menu choice
	char choice;
	
	do
	{
		//Display menu
		displayStartMenu();
		
		//Clear previous choice and get user's choice
		cin.clear();
		choice = cin.get();
		cin.ignore(100, '\n');
		
		//Use choice to determine next step
		menuChoice(choice);
	}
	while(choice != '1' && choice != '2');

	//If choice was to start game
	if(choice == '1')
	{
		//Strings to hold input so it can be validated it is an int
		string temp1;
		string temp2;

		//Prompt players for how many rounds
		cout << "How many rounds of War would you like to play?" <<endl;

		//Get rounds from user
		cin >> temp1;
		
		//Validate rounds is an int greater than 0
		temp2 = inputValid(temp1);
		while(temp2 == "invalid")
		{
			temp2 = inputInvalid();
		}	
		rounds = getInt(temp2);
		while(rounds <= 0)
		{
			temp2 = inputInvalid();
			while(temp2 == "invalid")
			{
				temp2 = inputInvalid();
			}
			rounds = getInt(temp2);
		}
	
		//Prompt player1 for number of sides for die
		cout << "Player 1: How many sides should your die have?" <<endl;
				 
		//Get number of sides from player1
		cin.clear();
		cin >> temp1;

		//Validate sides is an integer greater than 0
		temp2 = inputValid(temp1);
		while(temp2 == "invalid")
		{
			temp2 = inputInvalid();
		}
		die1sides = getInt(temp2);
		while(die1sides <= 0)
		{
			temp2 = inputInvalid();
			while(temp2 == "invalid")
			{
				temp2 = inputInvalid();
			}
			die1sides = getInt(temp2);
		}
	
		//Prompt player2 for number of sides for die
		cout << "Player 2: How many sides should your die have?" <<endl;
		
		//Get number of sides from player1
		cin.clear();
		cin >> temp1;

		//Validate sides is an integer greater than 0
		temp2 = inputValid(temp1);
		while(temp2 == "invalid")
		{
			temp2 = inputInvalid();
		}
		die2sides = getInt(temp2);
		while(die2sides <= 0)
		{
			temp2 = inputInvalid();
			while(temp2 == "invalid")
			{
				temp2 = inputInvalid();
			}
			die2sides = getInt(temp2);
		}
		
		//Prompt player1 for type of die choice
		cout << "Player 1: Would you like to use a " <<endl;
		cout << "1. Die" << endl;
		cout << "2. Loaded Die" << endl;
		cout << "Please enter your 1 or 2 for your choice." <<endl;

		//Get user choice for type of die
		cin.clear();
		cin >> temp1;

		//Validate the choice is 1 or 2
		temp2 = inputValid(temp1);
		while(temp2 == "invalid")
		{
			temp2 = inputInvalid();
		}
		die1type = getInt(temp2);
		while(die1type < 1 || die1type > 2)
		{
			temp2 = inputInvalid();
			while(temp2 == "invalid")
			{
				temp2 = inputInvalid();
			}
			die1type = getInt(temp2);
		}

		//Prompt player 2 for type of die choice
		cout << "Player 2: Would you like to use a " <<endl;
		cout << "1. Die" << endl;
		cout << "2. Loaded Die" << endl;	
		cout << "Please enter your 1 or 2 for your choice." <<endl;

		//Get user choice for type of die
		cin.clear();
		cin >> temp1;
	
		//Validate the choice is 1 or 2
		temp2 = inputValid(temp1);
		while(temp2 == "invalid")
		{
			temp2 = inputInvalid();
		}
		die2type = getInt(temp2);
		while(die2type < 1 || die2type > 2)
		{
			temp2 = inputInvalid();
			while(temp2 == "invalid")
			{
				temp2 = inputInvalid();
			}
			die2type = getInt(temp2);
		}
		
		//Varibles to store die types to be displayed in scoring
		string die1Name;
		string die2Name;
		
		//Create player1 die object based on user input
		shared_ptr<Die> die1;
		
		//If user chooses die
		if(die1type == 1)
		{
			die1 = make_shared<Die> (die1sides);
			die1Name = "die";
		}
		//If user chooses loaded die
		else if(die1type == 2)
		{
			die1 = make_shared<LoadedDie> (die1sides);
			die1Name = "loaded die";
		}

		//Create player1 object		
		Player player1(die1);

		//Create player2 die object based on user input
		shared_ptr<Die> die2;

		//If user chooses die
		if(die2type == 1)
		{
			die2 = make_shared<Die> (die2sides);
			die2Name = "die";

		}
		//If user chooses loaded die
		else if(die2type == 2)
		{
			die2 = make_shared<LoadedDie> (die2sides);
			die2Name = "loaded die";
		}

		//Create player1 object
		Player player2(die2);

		//Varibles to keep track of numbers rolled
		int player1Rolled;
		int player2Rolled;
		int drawcounter;		
		//Roll die for each player for each round
		for(int i = 0; i < rounds; ++i)
		{
			//Player 1 roll
			player1Rolled = player1.getNumberRolled();
			cout << "Player 1 rolled " << player1Rolled;
			cout << " using a " << die1sides;
			cout << "-sided " << die1Name << "." << endl;   
			//Player 2 roll
			player2Rolled = player2.getNumberRolled();
			cout << "Player 2 rolled " << player2Rolled;
			cout << " using a " << die2sides;
			cout << "-sided " << die2Name << "." << endl;

			//Determine and display who gets point
			if(player1Rolled == player2Rolled)
			{
				cout << "\nThis round is a draw.";
				cout << " No points were awarded.\n" <<endl;
				++drawcounter;
			}		
			else if(player1Rolled < player2Rolled)
			{
				cout << "\nPlayer 2 won this round.";
				player2.addPoint();
				cout << " Player 2 awarded 1 point.\n" <<endl;
			}
			else if(player1Rolled > player2Rolled)
			{
				cout << "\nPlayer 1 won this round.";
				player1.addPoint();
				cout << " Player 1 awarded 1 point.\n" <<endl;
			}
		}

		//Display winner and final score
		cout << "The final score after " << rounds;
		cout << " rounds is: " <<endl;
		cout << "Player 1: " << player1.getScore() <<endl;
		cout << "Player 2: " << player2.getScore() <<endl;
		cout << "Draws: " << drawcounter << endl;
		
		cout << "\n The winner is ";
		if(player1.getScore() == player2.getScore())
		{
			cout << "neither Player 1 or Player 2.";
			cout << " It is a draw.\n" <<endl;
		}
		else if(player1.getScore() < player2.getScore())
		{
			cout << "Player 2.\n" <<endl;
		}
		else if(player1.getScore() > player2.getScore())
		{
			cout << "Player 1.\n" <<endl;
		}
 

	}
}
