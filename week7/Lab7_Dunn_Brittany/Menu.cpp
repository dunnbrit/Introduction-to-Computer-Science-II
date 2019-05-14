/*************************************************************************
 * Program Name: Menu.cpp
 * Author: Brittany Dunn
 * Date: May 20 2018
 * Description: This is the implementation file for the menu functions
 *************************************************************************/

#include <iostream>
#include <string>
#include "Menu.hpp"
#include "Queue.hpp"
#include "getInt.hpp"

using std::string;
using std::cout;
using std::endl;
using std::cin;


//This function displays the menu
void displayMenu()
{
	cout << "\nPlease choose an option from the list below: " <<endl;
	cout << "1. Add a value to the back of the queue" <<endl;
	cout << "2. Display the front value" <<endl;
	cout << "3. Remove the front node" <<endl;
	cout << "4. Display the queue's contents" <<endl;
	cout << "5. Exit" <<endl;
	cout << "Please enter the number of your choice." <<endl;
}

//This function takes the users choice and determines next action
void menuChoice(int choice, Queue* queue)
{
	int number;
	string temp1;	
	string temp2;

	switch(choice)
	{
		case 1:
		{
			//Prompt user to enter number
			cout << "Please enter a number: " << endl;
			//Get number and validate input
			cin.ignore();
			cin >> temp1;
			temp2 = inputValid(temp1);
			while(temp2 == "invalid")
			{
				temp2 = inputInvalid();
			}
			number = getInt(temp2); 
			//Call function to add to back of queue
			queue->addBack(number);
		}
			break;
		case 2:
		{
			//Check if queue is empty
			if(queue->isEmpty())
			{
				cout << "Your queue is empty." << endl;
			}
			//If not, print return of of function
			else
			{
				cout << "The first node value is: ";
				cout << queue->getFront() << endl;
			}
		}
			break;
		case 3:
		{
			//Call function to remove first node
			queue->removeFront();
		}
			break;
		case 4:
		{
			//Call function to print queue
			queue->printQueue();
		}	
			break;
		case 5:
			break;
	}
}
			
