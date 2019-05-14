/*************************************************************************
 * Program Name: Lab2Main.cpp
 * Author: Brittany Dunn
 * Date: April 15 2018
 * Description: This program reads a file selted by user and counts the 
 * frequency of each letter. Then it writes the letter frequence to a
 * different file choosen by the user.
 *************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "countLetters.hpp"
#include "outputLetters.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

int main()
{
	//Varible to store user's file name	
	string fileName;
	ifstream readFile;

	//Array to store the frequency of letters
	int letterCounter [26];

	//Prompt user for file name
	cout << "Please enter the name of your file." <<endl;

	//Get file name
	cin >> fileName;
	cin.ignore(100,'\n');

	//Open file
	readFile.open(fileName, std::ios::in);
	
	//If file cannot be opened exit program
	if(!readFile)
	{
		cout << "Error opening file." << endl;;
		return 0;
	}

	//Call function to read file and count letters
	count_letters(readFile, letterCounter);
	
	//Close file
	readFile.close();

	return 0;

}


